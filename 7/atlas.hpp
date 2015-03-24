#ifndef ATLAS_HPP
#define ATLAS_HPP

#include <vector>

#include "creature.hpp"
#include "item.hpp"
#include "weapon.hpp"
#include "armour.hpp"
#include "area.hpp"


void buildatlas_creature(std::vector<Creature>& atlas);
void buildatlas_item(std::vector<Item>& atlas);
void buildatlas_weapon(std::vector<Weapon>& atlas);
void buildatlas_armour(std::vector<Armour>& atlas);
void buildatlas_area(std::vector<Area>& atlas,
  std::vector<Item>& items, std::vector<Weapon>& weapons,
  std::vector<Armour>& armour, std::vector<Creature>& creatures);

void buildatlas_creature(std::vector<Creature>& atlas) {
  atlas.push_back(Creature("Rat", 8, 8, 8, 12, 2.0, 1));
  return;
}

void buildatlas_item(std::vector<Item>& atlas) {
  atlas.push_back(Item("Gold Coin", "A small disc made of lustrous metal"));
  atlas.push_back(Item("Iron Key", "A heavy iron key with a simple cut"));

  return;
}

void buildatlas_weapon(std::vector<Weapon>& atlas) {
  atlas.push_back(Weapon("Iron Dagger", "A short blade made of iron with a leather-bound hilt", 5, 10.0));
  atlas.push_back(Weapon("Excalibur", "The legendary blade, bestowed upon  you by the Lady of the Lake", 35, 35.0));

  return;
}

void buildatlas_armour(std::vector<Armour>& atlas) {
  atlas.push_back(Armour("Leather Cuirass", "Torso armour made of tanned hide", 4, Armour::Slot::TORSO));

  return;
}

void buildatlas_area(std::vector<Area>& atlas,
  std::vector<Item>& items, std::vector<Weapon>& weapons,
  std::vector<Armour>& armour, std::vector<Creature>& creatures) {
  atlas.push_back(Area(Dialogue(
    "You are in room 1",
    {"Go to room 2", "Search"}),
    Inventory({
      std::make_pair(&items[0], 5)
    }, {
      std::make_pair(&weapons[0], 1)
    }, {
      std::make_pair(&armour[0], 1)
    }), {}));
  atlas.push_back(Area(Dialogue(
    "You are in room 2",
    {"Go to room 1", "Search"}),
    Inventory({
      std::make_pair(&items[0], 10),
      std::make_pair(&items[1], 1),
    }, {}, {}), {
      &creatures[0]
    }));

  return;
}

#endif /* ATLAS_HPP */
