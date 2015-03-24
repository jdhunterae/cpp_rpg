#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <list>
#include <utility>
#include <iostream>

#include "item.hpp"
#include "weapon.hpp"
#include "armour.hpp"


class Inventory {
public:
  std::list<std::pair<Item*, int>> items;
  std::list<std::pair<Weapon*, int>> weapons;
  std::list<std::pair<Armour*, int>> armour;

  Inventory() {
  }

  Inventory(std::list<std::pair<Item*, int>> items,
    std::list<std::pair<Weapon*, int>> weapons,
    std::list<std::pair<Armour*, int>> armour) {
    this->items = items;
    this->weapons = weapons;
    this->armour = armour;
  }

  void add_item(Item* item, int count) {
    for (auto& it : this->items) {
      if (it.first == item) {
        it.second += count;
        return;
      }
    }

    this->items.push_back(std::make_pair(item, count));
  }

  void remove_item(Item* item, int count) {
    for (auto& it : this->items) {
      if (it.first == item) it.second -= count;
    }

    this->items.remove_if([](std::pair<Item*, int>& element) {
      return element.second < 1;
    });
  }

  void add_weapon(Weapon* weapon, int count) {
    for (auto& it : this->weapons) {
      if (it.first == weapon) {
        it.second += count;
        return;
      }
    }

    this->weapons.push_back(std::make_pair(weapon, count));
  }

  void remove_weapon(Weapon* weapon, int count) {
    for (auto& it : this->weapons) {
      if (it.first == weapon) it.second -= count;
    }

    this->weapons.remove_if([](std::pair<Weapon*, int>& element) {
      return element.second < 1;
    });
  }

  void add_armour(Armour* armour, int count) {
    for (auto& it : this->armour) {
      if (it.first == armour) {
        it.second += count;
        return;
      }
    }

    this->armour.push_back(std::make_pair(armour, count));
  }

  void remove_armour(Armour* armour, int count) {
    for (auto& it : this->armour) {
      if (it.first == armour) it.second -= count;
    }

    this->armour.remove_if([](std::pair<Armour*, int>& element) {
      return element.second < 1;
    });
  }

  void merge(Inventory* inventory) {
    if (inventory == this) return;

    for (auto it : inventory->items) {
      this->add_item(it.first, it.second);
    }

    for (auto it : inventory->weapons) {
      this->add_weapon(it.first, it.second);
    }

    for (auto it : inventory->armour) {
      this->add_armour(it.first, it.second);
    }

    return;
  }

  void clear() {
    this->items.clear();
    this->weapons.clear();
    this->armour.clear();
  }

  int print_items(bool label=false) {
    unsigned int i = 1;

    for (auto it : this->items) {
      if (label) std::cout << i++ << ": ";

      std::cout << it.first->name << "(" << it.second << ") - ";
      std::cout << it.first->description << std::endl;
    }

    return this->items.size();
  }

  int print_weapons(bool label=false) {
    unsigned int i = 1;

    for (auto it : this->weapons) {
      if (label) std::cout << i++ << ": ";

      std::cout << it.first->name << "(" << it.second << ") - ";
      std::cout << it.first->description << std::endl;
    }

    return this->weapons.size();
  }

  int print_armour(bool label=false) {
    unsigned int i = 1;

    for (auto it : this->armour) {
      if (label) std::cout << i++ << ": ";

      std::cout << it.first->name << "(" << it.second << ") - ";
      std::cout << it.first->description << std::endl;
    }

    return this->armour.size();
  }

  void print(bool label=false) {
    if (this->items.size() == 0 &&
      this->weapons.size() == 0 &&
      this->armour.size() == 0) {
      std::cout << "Nothing" << std::endl;
    } else {
      this->print_items(label);
      this->print_weapons(label);
      this->print_armour(label);
    }

    return;
  }
};

#endif /* INVENTORY_HPP */
