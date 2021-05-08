CMAKE_MINIMUM_REQUIRED(VERSION 3.19)

project("TripleTriad" VERSION 1.0.0)

add_library(tt src/Board.cpp src/Card.cpp src/CardFactory.cpp src/Game.cpp src/Hand.cpp src/Keyboard.hpp src/Player.hpp src/PlayerAI.cpp src/PlayerHuman.cpp)

add_executable(main main.cpp)
target_link_libraries(main tt)