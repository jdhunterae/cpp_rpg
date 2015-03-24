#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>

#include "item.hpp"
#include "weapon.hpp"
#include "armour.hpp"
#include "inventory.hpp"


class Creature {
public:
  Inventory inventory;
  Weapon* equippedWeapon;
  Armour* equippedArmour[Armour::Slot::N];

  std::string name;
  std::string className;

  int health;
  int maxHealth;
  int str;
  int end;
  int dex;
  double hitRate;

  unsigned int level;
  unsigned int exp;

  Creature() {
    this->equippedWeapon = nullptr;
    this->equippedArmour[Armour::Slot::HEAD] = nullptr;
    this->equippedArmour[Armour::Slot::TORSO] = nullptr;
    this->equippedArmour[Armour::Slot::LEGS] = nullptr;

    this->level = 1;
    this->exp = 0;
  }

  Creature(std::string name, int health, int str, int end, int dex, double hitRate, unsigned int level = 1, std::string className = "") {
    this->name = name;
    this->health = health;
    this->maxHealth = health;
    this->str = str;
    this->end = end;
    this->dex = dex;
    this->hitRate = hitRate;
    this->className = className;

    this->equippedWeapon = nullptr;
    this->equippedArmour[Armour::Slot::HEAD] = nullptr;
    this->equippedArmour[Armour::Slot::TORSO] = nullptr;
    this->equippedArmour[Armour::Slot::LEGS] = nullptr;

    this->level = level;
    this->exp = 0;
  }

  unsigned int expToLevel(unsigned int level) {
    return 128 * level * level;
  }

  bool levelUp() {
    if(this->exp >= expToLevel(this->level+1)) {
      ++level;

      unsigned int healthBoost = 0;
      unsigned int strBoost = 0;
      unsigned int endBoost = 0;
      unsigned int dexBoost = 0;

      if(level % 3 == 0) {
        healthBoost = 10 + (rand() % 4) + this->end / 4;
      } else {
        healthBoost = this->end / 4;
      }

      if(this->className == "Fighter") {
        strBoost = 1;
        endBoost = 1;
        if(rand() % 2 == 0) dexBoost = 1;
      } else if(this->className == "Rogue") {
        endBoost = 1;
        dexBoost = 1;
        if(rand() % 2 == 0) strBoost = 1;
      }

      this->maxHealth += healthBoost;
      this->str += strBoost;
      this->end += endBoost;
      this->dex += dexBoost;

      std::cout << this->name << " grew to level " << level << "!\n";
      std::cout << "Health +" << healthBoost << " -> " << this->maxHealth << std::endl;
      std::cout << "Str +" << strBoost << " -> " << this->str << std::endl;
      std::cout << "End +" << endBoost << " -> " << this->end << std::endl;
      std::cout << "Dex +" << dexBoost << " -> " << this->dex<< std::endl;
      std::cout << "----------------\n";

      return true;
    }

    return false;
  }

  void equipWeapon(Weapon* weapon) {
    this->equippedWeapon = weapon;
    return;
  }

  void equipArmour(Armour* armour) {
    this->equippedArmour[(int)armour->slot] = armour;
    return;
  }
};

#endif /* CREATURE_HPP */
