// ======================
// server.js
// ======================

const WebSocket = require('ws');
const { Pool } = require('pg');

// ======================
// PostgreSQL Connection
// ======================

const pool = new Pool({
    user: 'postgres',
    host: 'localhost',
    database: 'nexus_chat',
    password: 'matei123',
    port: 5432,
});

pool.connect()
    .then(client => {
        console.log('Connected to PostgreSQL database');
        client.release();
    })
    .catch(err => console.error('Error connecting to DB', err.stack));

// ======================
// WebSocket Server
// ======================

const wss = new WebSocket.Server({ port: 8080 }, () => {
    console.log('WebSocket server running on ws://localhost:8080');
});

wss.on('connection', (ws) => {
    console.log('Client connected');

    ws.on('message', async (message) => {

        let data;

        // ======================
        // Parse JSON
        // ======================
        try {
            data = JSON.parse(message);
        } catch (err) {
            ws.send(JSON.stringify({
                type: 'error',
                success: false,
                message: 'Invalid JSON message'
            }));
            return;
        }

        // ======================
        // LOGIN
        // ======================
        if (data.type === 'login') {
            const { email, password } = data;

            try {
                const res = await pool.query(
                    'SELECT * FROM account WHERE email = $1 AND password_hash = $2',
                    [email, password]
                );

                if (res.rows.length > 0) {
                    // return user data so client can create a User object
                    const user = res.rows[0];
                    const loginRes = {
                        type: 'login_result',
                        success: true,
                        message: 'Login successful',
                        user: {
                            // ensure numeric id (pg returns as string sometimes)
                            id: Number(user.id),
                            username: user.username,
                            email: user.email
                        }
                    };
                    ws.send(JSON.stringify(loginRes));
                } else {
                    ws.send(JSON.stringify({
                        type: 'login_result',
                        success: false,
                        message: 'Incorrect email or password'
                    }));
                }
            } catch (err) {
                console.error(err);
                ws.send(JSON.stringify({
                    type: 'login_result',
                    success: false,
                    message: 'Server error'
                }));
            }

            return;
        }

        // ======================
        // REGISTER
        // ======================
        if (data.type === 'register') {
            const { email, username, password } = data;

            try {
                const check = await pool.query(
                    'SELECT 1 FROM account WHERE email = $1 OR username = $2',
                    [email, username]
                );

                if (check.rowCount > 0) {
                    ws.send(JSON.stringify({
                        type: 'register',
                        success: false,
                        message: 'Email or username already in use'
                    }));
                    return;
                }

                await pool.query(
                    'INSERT INTO account (email, username, password_hash) VALUES ($1, $2, $3)',
                    [email, username, password]
                );

                ws.send(JSON.stringify({
                    type: 'register',
                    success: true,
                    message: 'Account created successfully'
                }));

            } catch (err) {
                console.error(err);
                ws.send(JSON.stringify({
                    type: 'register',
                    success: false,
                    message: 'Server error'
                }));
            }

            return;
        }

        // ======================
        // SEND FRIEND REQUEST
        // ======================
        if (data.type === 'send_friend_request') {
            if (!currentUser) {
                ws.send(JSON.stringify({
                    type: 'friend_request_result',
                    success: false,
                    message: 'Not logged in'
                }));
                return;
            }

            const { sender, receiver } = data;

            try {
                // Get sender ID
                const senderRes = await pool.query(
                    'SELECT id FROM account WHERE username = $1',
                    [sender]
                );

                if (senderRes.rows.length === 0) {
                    ws.send(JSON.stringify({
                        type: 'friend_request_result',
                        success: false,
                        message: 'Sender not found!'
                    }));
                    return;
                }

                const receiverRes = await pool.query(
                    'SELECT id FROM account WHERE username = $1',
                    [receiver]
                );

                if (receiverRes.rows.length === 0) {
                    ws.send(JSON.stringify({
                        type: 'friend_request_result',
                        success: false,
                        message: 'Receiver not found!'
                    }));
                    return;
                }

        const requester_id = senderRes.rows[0].id;
        const receiver_id = receiverRes.rows[0].id;

        // 🔥 do not allow self-add
        if (requester_id === receiver_id) {
            ws.send(JSON.stringify({
                type: 'friend request result',
                success: false,
                message: 'You cannot add yourself!'
            }));
            return;
        }

        // Check if relationship already exists
        const existing = await pool.query(
            `SELECT 1 FROM friendships
             WHERE (requester_id = $1 AND receiver_id = $2)
                OR (requester_id = $2 AND receiver_id = $1)`,
            [requester_id, receiver_id]
        );

        if (existing.rows.length > 0) {
            ws.send(JSON.stringify({
                type: 'friend request result',
                success: false,
                message: 'Friend request already exists!'
            }));
            return;
        }

        // Insert the request
        await pool.query(
            `INSERT INTO friendships
             (requester_id, receiver_id, status, created_at, user1accepted, user2accepted)
             VALUES ($1, $2, 'pending', NOW(), true, false)`,
            [requester_id, receiver_id]
        );

        ws.send(JSON.stringify({
            type: 'friend request result',
            success: true,
            message: 'Friend request sent!'
        }));

    } catch (err) {
        console.error(err);
        ws.send(JSON.stringify({
            type: 'friend request result',
            success: false,
            message: 'Server error'
        }));
    }

    return;
        }
        // ======================
        // get friend requests
        // ======================
        if (data.type === 'get_friend_requests') {
        const { user_id } = data;
    

    try {
        const result = await pool.query(`
            SELECT fr.requester_id, ac.username
            FROM friendships fr
            JOIN account ac ON fr.requester_id = ac.id
            WHERE fr.receiver_id = $1
            AND fr.status = 'pending'
        `, [user_id]);

        
        ws.send(JSON.stringify({
            type: 'get_friend_requests_result',
            success: true,
            friend_requests: result.rows
        }));

    } catch (err) {
        console.error(err);
    }
        }
       
        // ======================
        // RESPOND TO FRIEND REQUEST
        // ======================
        if (data.type === 'friend request response') {

    const { requester_username, responder_username, accepted } = data;

    try {

        const requesterRes = await pool.query(
            'SELECT id FROM account WHERE username = $1',
            [requester_username]
        );

        if (requesterRes.rows.length === 0) {
            ws.send(JSON.stringify({
                type: 'friend_request_response_result',
                success: false,
                message: 'Requester not found'
            }));
            return;
        }

        const responderRes = await pool.query(
            'SELECT id FROM account WHERE username = $1',
            [responder_username]
        );

        if (responderRes.rows.length === 0) {
            ws.send(JSON.stringify({
                type: 'friend_request_response_result',
                success: false,
                message: 'Responder not found'
            }));
            return;
        }

        const requesterId = requesterRes.rows[0].id;
        const responderId = responderRes.rows[0].id;

        if (accepted) {

            const result = await pool.query(
                `UPDATE friendships
                 SET status = 'accepted',
                     user1accepted = true,
                     user2accepted = true
                 WHERE requester_id = $1
                   AND receiver_id = $2
                   AND status = 'pending'`,
                [requesterId, responderId]
            );

            if (result.rowCount === 0) {
                ws.send(JSON.stringify({
                    type: 'friend_request_response_result',
                    success: false,
                    message: 'Friend request not found'
                }));
                return;
            }

            ws.send(JSON.stringify({
                type: 'friend_request_response_result',
                success: true,
                message: 'Friend request accepted'
            }));

        } else {

            const result = await pool.query(
                `DELETE FROM friendships
                 WHERE requester_id = $1
                   AND receiver_id = $2
                   AND status = 'pending'`,
                [requesterId, responderId]
            );

            if (result.rowCount === 0) {
                ws.send(JSON.stringify({
                    type: 'friend_request_response_result',
                    success: false,
                    message: 'Friend request not found'
                }));
                return;
            }

            ws.send(JSON.stringify({
                type: 'friend_request_response_result',
                success: true,
                message: 'Friend request rejected'
            }));
        }

    } catch (err) {
        console.error(err);

        ws.send(JSON.stringify({
            type: 'friend_request_response_result',
            success: false,
            message: 'Server error'
        }));
    }

    return;
        }       
        // ======================
        // get friends list
        // ======================

// get friends list
if(data.type === 'get_friends') {
    const { userId } = data;
    try {
        const result = await pool.query(`
            SELECT 
                CASE
                    WHEN requester_id = $1 THEN receiver_id
                    ELSE requester_id
                END AS friend_id
            FROM friendships
            WHERE (requester_id = $1 OR receiver_id = $1)
              AND status = 'accepted'
        `, [userId]);

        const friendIds = result.rows.map(r => r.friend_id);
        let friends = [];

        if(friendIds.length > 0){
            const resUsers = await pool.query(
                `SELECT username FROM account WHERE id = ANY($1::bigint[])`,
                [friendIds]
            );
            friends = resUsers.rows.map(r => r.username);
        }

        ws.send(JSON.stringify({
            type: 'get_friends_result',
            success: true,
            friends: friends
        }));

    } catch(err) {
        console.error(err);
        ws.send(JSON.stringify({
            type: 'get_friends_result',
            success: false,
            message: 'Server error'
        }));
    }
}

         // ======================
        // GET MESSAGES
        // ======================
        if (data.type === 'get_messages') {

    const myUser = data.myUser;
    const friendUser = data.friendUser;

    try {

        const result = await pool.query(
            `SELECT sender_user, receiver_user, content, sent_at
             FROM messages
             WHERE 
             (sender_user = $1 AND receiver_user = $2)
             OR
             (sender_user = $2 AND receiver_user = $1)
             ORDER BY sent_at`,
            [myUser, friendUser]
        );

        ws.send(JSON.stringify({
            type: "messages_list",
            messages: result.rows
        }));

    } catch (err) {
        console.error("Error loading messages:", err);

        ws.send(JSON.stringify({
            type: "messages_list",
            messages: []
        }));
    }
        }
        // ======================
        // NORMAL MESSAGE
        // ======================
        if (data.type === 'message') {

    const { sender_username, receiver_username, text } = data;

    try {
        await pool.query(
            `INSERT INTO messages(sender_user, receiver_user, content, sent_at)
             VALUES($1, $2, $3, NOW())`,
            [sender_username, receiver_username, text]
        );
    } catch (err) {
        console.error('Error inserting message:', err.stack);
        return;
    }

    // trimitem mesajul doar utilizatorilor relevanți
    wss.clients.forEach(client => {
        if (client.readyState === WebSocket.OPEN) {
            client.send(JSON.stringify({
                type: 'message',
                sender_user: sender_username,
                receiver_user: receiver_username,
                content: text
            }));
        }
    });

    return;
}

    });

    ws.on('close', () => {
        console.log('Client disconnected');
    });
});