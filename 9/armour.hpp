#ifndef ARMOUR_HPP
#define ARMOUR_HPP

#include <string>

#include "item.hpp"


class Armour : public Item {
public:
  enum Slot { TORSO, HEAD, LEGS, N };

  Slot slot;
  int defense;

  Armour() {
  }

  Armour(std::string name, std::string description, int defense, Armour::Slot slot)
    : Item(name, description) {
    this->defense = defense;
    this->slot = slot;
  }
};

#endif /* ARMOUR_HPP */
