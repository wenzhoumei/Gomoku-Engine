# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(MyProject VERSION 1.0)

# Add an executable target
add_executable(kanazawa
	src/main.cpp
	src/human_player.cpp
	src/random_bot_player.cpp
	src/simple_bot_player.cpp
	src/minimax_bot_player.cpp
	src/game.cpp
	src/game_state.cpp
)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
