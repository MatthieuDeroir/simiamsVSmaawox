cmake_minimum_required(VERSION 3.20.2)
project(simiamsVSmaawox)

set(CMAKE_CXX_STANDARD 14)

add_executable(simiamsVSmaawox main.cpp include/header.h src/Player.cpp src/Enemy.cpp include/Enemy.h include/Player.h src/Game.cpp include/Game.h src/utils.cpp src/Champion.cpp include/Champion.h src/Spell.cpp include/Spell.h)
