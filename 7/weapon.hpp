#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

#include "item.hpp"


class Weapon : public Item {
public:
  unsigned damage;
  double hitRate;

  Weapon() {
  }

  Weapon(std::string name, std::string description, int damage, double hitRate)
    : Item(name, description) {
    this->damage = damage;
    this->hitRate = hitRate;
  }
};

#endif /* WEAPON_HPP */
