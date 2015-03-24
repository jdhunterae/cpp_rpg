project(penguinProgrammerRPGTutorial)
cmake_minimum_required(VERSION 2.6)

add_definitions(-std=c++11)

set(sources main.cpp dialogue.hpp
  item.hpp weapon.hpp armour.hpp
  inventory.hpp creature.hpp
  area.hpp)
add_executable(game ${sources})
