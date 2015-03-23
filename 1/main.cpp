#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <cstdlib>
#include <ctime>

#include "dialogue.hpp"


int main() {
  int result = Dialogue(
    "Choose your class",
    {"Fighter", "Rogue"}).activate();

  switch (result) {
    case 1:
      std::cout << "You chose 'Fighter'" << std::endl;
      break;
    case 2:
      std::cout << "You chose 'Rogue'" << std::endl;
      break;
    default:
      std::cout << "Dialogue is broken." << std::endl;
      break;
  }

  return 0;
}
