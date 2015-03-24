#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <cstdlib>
#include <ctime>

#include "dialogue.hpp"
#include "creature.hpp"


Creature dialogue_newchar();

int main() {
  Creature player;
  srand(time(NULL));

  int result = Dialogue(
    "Welcome!",
    {"New Game"}).activate();

  switch(result) {
    case 1: player = dialogue_newchar(); break;
    default: return 0; break;
  }

  int count = 0;

  while (1 && count <= 10) {
    count++;

    if (player.health <= 0) {
      std::cout << "\t----YOU DIED----\n\t    GAME OVER\n";
      return 0;
    }
  }

  return 0;
}

Creature dialogue_newchar() {
  std::cout << "Choose your name" << std::endl;
  std::string name;
  std::cin >> name;

  int result = Dialogue(
    "Choose your class",
    {"Fighter", "Rogue"}).activate();

  switch(result) {
    case 1:
      return Creature(name, 35, 20, 10, 5, 10.0, 1, "Fighter");
      break;
    case 2:
      return Creature(name, 30, 5, 10, 20, 15.0, 1, "Rogue");
      break;
    default:
      return Creature(name, 30, 10, 10, 10, 10.0, 1, "Adventurer");
      break;
  }
}
