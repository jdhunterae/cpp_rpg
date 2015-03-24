#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>


class Item {
public:
  std::string name;
  std::string description;

  Item() {
  }

  Item(std::string name, std::string description) {
    this->name = name;
    this->description = description;
  }
};

#endif /* ITEM_HPP */
