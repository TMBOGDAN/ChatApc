cmake_minimum_required(VERSION 3.16)

project(ChatApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


set(CMAKE_AUTOUIC_SEARCH_PATHS
    ${CMAKE_SOURCE_DIR}/ui
)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Widgets
    WebSockets
)

qt_add_executable(ChatApp
    MANUAL_FINALIZATION

    # main
    main.cpp

    # src
    src/mainwindow.cpp
    src/loginwindow.cpp
    src/chatwindow.cpp
    src/profilewidget.cpp
    src/serverconnection.cpp
    src/user.cpp
    src/friendmanage.cpp
    src/friendrequestitem.cpp
    src/friendwidget.cpp
    src/message.cpp

    # headers
    headers/mainwindow.h
    headers/loginwindow.h
    headers/chatwindow.h
    headers/profilewidget.h
    headers/serverconnection.h
    headers/user.h
    headers/friendmanage.h
    headers/friendrequestitem.h
    headers/friendwidget.h
    headers/message.h

    # ui
    ui/mainwindow.ui
    ui/loginwindow.ui
    ui/chatwindow.ui
    ui/profilewidget.ui
    ui/friendmanage.ui
    ui/friendrequestitem.ui
    ui/friendwidget.ui
    ui/message.ui
)


target_include_directories(ChatApp PRIVATE
    ${CMAKE_SOURCE_DIR}/headers
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
