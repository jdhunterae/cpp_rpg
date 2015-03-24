#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <iostream>

#include "dialogue.hpp"
#include "creature.hpp"
#include "armour.hpp"
#include "weapon.hpp"


class Battle {
public:
  Dialogue dialogue;
  Creature* creatures[2];

  Battle() {
  }

  Battle(Creature* player, Creature* b) {
    this->creatures[0] = player;
    this->creatures[1] = b;

    this->dialogue = Dialogue("What will you do?",
      {"Attack", "Defend"});
  }

  void attack(Creature* a, Creature* b) {
    std::cout << a->name << " attacks!" << std::endl;

    int damage = 0;

    double hitRate = a->hitRate;

    if (a->equippedWeapon != nullptr) {
      damage += a->equippedWeapon->damage;
      hitRate += a->equippedWeapon->hitRate;
    }

    damage += a->str / 2;

    int defense = 0;

    for (int i = 0; i < Armour::Slot::N; ++i) {
      if (b->equippedArmour[i] != nullptr)
        defense += b->equippedArmour[i]->defense;
    }

    damage -= defense;
    if (damage < 1) damage = 1;

    if (rand() % 201 <= 170 + hitRate - b->dex) {
      std::cout << b->name << " takes " << damage << " damage!" << std::endl;
      b->health -= damage;
    } else {
      std::cout << a->name << " missed!" << std::endl;
    }

    return;
  }

  void playerTurn() {
    int result = this->dialogue.activate();

    switch (result) {
      case 1:
        attack(creatures[0], creatures[1]);
        break;
      case 2:
        std::cout << creatures[0]->name << " defends!" << std::endl;
        break;
      default:
        break;
    }

    return;
  }

  void enemyTurn() {
    attack(creatures[1], creatures[0]);

    return;
  }

  bool isdead(Creature* creature) {
    if (creature->health <= 0) {
      return true;
    }

    return false;
  }

  bool activate() {
    if (creatures[0]->dex >= creatures[1]->dex) {
      this->playerTurn();
      if (isdead(creatures[1])) {
        std::cout << creatures[1]->name << " was vanquished!" << std::endl;
        return true;
      }
      this->enemyTurn();
      if (isdead(creatures[0])) {
        std::cout << creatures[0]->name << " was vanquished!" << std::endl;
        return true;
      }
    } else {
      this->enemyTurn();
      if (isdead(creatures[0])) {
        std::cout << creatures[0]->name << " was vanquished!" << std::endl;
        return true;
      }
      this->playerTurn();
      if (isdead(creatures[1])) {
        std::cout << creatures[1]->name << " was vanquished!" << std::endl;
        return true;
      }
    }
    return false;
  }

  void run() {
    std::cout << creatures[1]->name << " appears!" << std::endl;

    while (!this->activate());

    if (isdead(creatures[1])) {
      unsigned int expGain = creatures[1]->expToLevel(creatures[1]->level+1) / 8;
      std::cout << "Gained " << expGain << " exp!" << std::endl;
      creatures[0]->exp += expGain;

      while(creatures[0]->levelUp());
    }

    return;
  }
};

#endif /* BATTLE_HPP */
