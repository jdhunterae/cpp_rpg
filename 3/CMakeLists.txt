project(penguinProgrammerRPGTutorial)
cmake_minimum_required(VERSION 2.6)

add_definitions(-std=c++11)

set(sources main.cpp dialogue.hpp creature.hpp)
add_executable(game ${sources})
