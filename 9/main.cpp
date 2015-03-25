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
#include "battle.hpp"


Creature dialogue_newchar();
void dialogue_menu(Creature& player);

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

    if (currentArea->creatures.size() > 0) {
      for (int i = currentArea->creatures.size() - 1; i >= 0; --i) {
        Battle(&player, currentArea->creatures[i]).run();
        currentArea->creatures.pop_back();
      }
    }

    result = currentArea->dialogue.activate();

    if (currentArea == &(areaAtlas[0])) {
      switch (result) {
        case 0:
          dialogue_menu(player);
          break;
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
        case 0:
          dialogue_menu(player);
          break;
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

void dialogue_menu(Creature& player) {
  int result = Dialogue("Menu\n====",
    {"Items", "Equipment", "Character"}).activate();

  switch (result) {
    case 1:
      std::cout << "Items\n=====" << std::endl;
      player.inventory.print();
      std::cout << "------------" << std::endl;
      break;
    case 2:
      std::cout << "Equipment\n===========" << std::endl;
      std::cout << "HEAD:  "
        << (player.equippedArmour[Armour::Slot::HEAD] != nullptr ?
          player.equippedArmour[Armour::Slot::HEAD]->name : "Nothing")
        << std::endl;
      std::cout << "TORSO: "
        << (player.equippedArmour[Armour::Slot::TORSO] != nullptr ?
          player.equippedArmour[Armour::Slot::TORSO]->name : "Nothing")
        << std::endl;
      std::cout << "LEGS: "
        << (player.equippedArmour[Armour::Slot::LEGS] != nullptr ?
          player.equippedArmour[Armour::Slot::LEGS]->name : "Nothing")
        << std::endl;
      std::cout << "WEAP: "
        << (player.equippedWeapon != nullptr ?
          player.equippedWeapon->name : "Nothing")
        << std::endl;

      int result2 = Dialogue("",
        {"Equip Armour", "Equip Weapon", "Close"}).activate();

      if (result2 == 1) {
        int userInput = 0;
        int numItems = player.inventory.print_armour(true);
        if (numItems == 0) break;

        while (!userInput) {
          std::cout << "Equip which item?" << std::endl;
          std::cin >> userInput;

          if (userInput >= 1 && userInput <= numItems) {
            int i = 1;

            for (auto it : player.inventory.armour) {
              if (i++ == userInput) {
                player.equipArmour(it.first);
                break;
              }
            }
          }
        }
      } else if (result2 == 2) {
        int userInput = 0;
        int numItems = player.inventory.print_weapons(true);

        if (numItems == 0) break;

        while (!userInput) {
          std::cout << "Equip which item?" << std::endl;
          std::cin >> userInput;

          if (userInput >= 1 && userInput <= numItems) {
            int i = 1;
            for (auto it : player.inventory.weapons) {
              if (i++ == userInput) {
                player.equipWeapon(it.first);
                break;
              }
            }
          }
        }
      }
      std::cout << "-------------\n"
      break;
    case 3:
      std::cout << "Character\n==========" << std::endl;
      std::cout << player.name;
      if (player.className != "") std::cout << " the " << player.className;
      std::cout << std::endl;
      std::cout << "HP:  " << player.health << "/" << player.healthMax << std::endl;
      std::cout << "STR: " << player.str << std::endl;
      std::cout << "END: " << player.end << std::endl;
      std::cout << "DEX: " << player.dex << std::endl;
      std::cout << "LVL: " << player.level << "(" << player.exp << "/" << player.expToLevel(player.level+1) << ")" << std::endl;
      std::cout << "------------" << std::endl;
      break;
    default:
      break;
  }

  return;
}
