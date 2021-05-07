cmake_minimum_required(VERSION 3.19)
project(node_addon_redux VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(node_modules/node-addon-api)
include(NodeJS.cmake)
nodejs_init()

add_nodejs_module(${PROJECT_NAME}
        main.cpp
        src/Board.cpp
        src/Board.h
        src/Card.cpp
        src/Card.h
        src/CardFactory.cpp
        src/CardFactory.h
        src/Game.cpp
        src/Game.h
        src/Hand.cpp
        src/Hand.h
        src/Keyboard.hpp
        src/Player.hpp
        src/PlayerAI.cpp
        src/PlayerAI.h
        src/PlayerHuman.cpp
        src/PlayerHuman.h
)