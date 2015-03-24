#ifndef AREA_HPP
#define AREA_HPP

#include <vector>

#include "dialogue.hpp"
#include "inventory.hpp"
#include "creature.hpp"


class Area {
public:
  Dialogue dialogue;
  Inventory items;
  std::vector<Creature*> creatures;

  Area() {
  }

  Area(Dialogue dialogue, Inventory items, std::vector<Creature*> creatures) {
    this->dialogue = dialogue;
    this->items = items;
    this->creatures = creatures;
  }

  void search(Creature& player) {
    std::cout << "You find:" << std::endl;

    this->items.print();
    player.inventory.merge(&(this->items));
    this->items.clear();

    return;
  }
};

#endif /* AREA_HPP */
