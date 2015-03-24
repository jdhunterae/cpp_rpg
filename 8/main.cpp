#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <cstdlib>
#include <ctime>

#include "dialogue.hpp"
#include "item.hpp"
#include "weapon.hpp"
#include "armour.hpp"
#include "inventory.hpp"
#include "creature.hpp"
#include "area.hpp"
#include "atlas.hpp"


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

  std::vector<Creature> creatureAtlas;
  std::vector<Item> itemAtlas;
  std::vector<Weapon> weaponAtlas;
  std::vector<Armour> armourAtlas;
  std::vector<Area> areaAtlas;

  buildatlas_creature(creatureAtlas);
  buildatlas_item(itemAtlas);
  buildatlas_weapon(weaponAtlas);
  buildatlas_armour(armourAtlas);
  buildatlas_area(areaAtlas, itemAtlas, weaponAtlas, armourAtlas, creatureAtlas);

  Area* currentArea = &(areaAtlas[0]);

  while (1) {
    if (player.health <= 0) {
      std::cout << "\t----YOU DIED----" << std::endl;
      std::cout << "\t    GAME OVER" << std::endl;
      return 0;
    }

    result = currentArea->dialogue.activate();

    if (currentArea == &(areaAtlas[0])) {
      switch (result) {
        case 1:
          currentArea = &(areaAtlas[1]);
          break;
        case 2:
          currentArea->search(player);
          break;
        default:
          break;
      }
    } else if (currentArea == &(areaAtlas[1])) {
      switch (result) {
        case 1:
          currentArea = &(areaAtlas[0]);
          break;
        case 2:
          currentArea->search(player);
          break;
        default:
          break;
      }
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
