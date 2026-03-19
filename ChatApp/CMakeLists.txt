cmake_minimum_required(VERSION 3.16)

project(ChatApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt 6
find_package(Qt6 REQUIRED COMPONENTS
    Core
    Widgets
    WebSockets
)

set(PROJECT_SOURCES
    main.cpp

    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    loginwindow.cpp
    loginwindow.h
    loginwindow.ui

    chatwindow.cpp
    chatwindow.h
    chatwindow.ui





    profilewidget.cpp
    profilewidget.h
    profilewidget.ui

    serverconnection.cpp
    serverconnection.h
)

qt_add_executable(ChatApp
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
    user.h user.cpp
    friendmanage.h friendmanage.cpp friendmanage.ui
    friendrequestitem.h friendrequestitem.cpp friendrequestitem.ui
    friendwidget.h friendwidget.cpp friendwidget.ui
    message.h message.cpp message.ui

)

target_link_libraries(ChatApp PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::WebSockets
)

set_target_properties(ChatApp PROPERTIES
    WIN32_EXECUTABLE TRUE
)

qt_finalize_executable(ChatApp)
