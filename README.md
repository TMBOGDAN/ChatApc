ChatApp
Overview

ChatApp is a desktop messaging application built with C++ and Qt 6, providing a simple and intuitive interface for real-time communication. It supports user authentication, friend management, and WebSocket-based chat functionality. The application is designed as a learning project for exploring client-server architecture, GUI development, and database integration.

Features
User registration and login
Friend management (add/search friends)
Real-time messaging using WebSockets
Display of chat history with friends
User interface components for profile, friends list, and chat windows
Support for future enhancements like logout, notifications, and multimedia messages

Technologies
C++17 – core application logic
Qt 6 – GUI, widgets, signals/slots, WebSockets
WebSockets – real-time communication between client and server
JSON – data exchange format
SQL – database integration for user and friend management


Installation
Prerequisites
Qt 6 (with Core, Widgets, and WebSockets modules)
CMake 3.16+
C++17 compatible compiler

Project Structure
ChatApp/
├─ main.cpp                # Application entry point
├─ loginwindow.h/.cpp      # Login and registration logic
├─ mainwindow.h/.cpp       # Main chat window and UI
├─ profilewidget.h/.cpp    # User profile display
├─ friendwidget.h/.cpp     # Friend list items
├─ serverconnection.h/.cpp # WebSocket client implementation
├─ ui/                     # Qt Designer-generated UI files
├─ CMakeLists.txt          # Build configuration

