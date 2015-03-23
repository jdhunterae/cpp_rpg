#ifndef DIALOGUE_HPP
#define DIALOGUE_HPP

#include <string>
#include <vector>
#include <iostream>


class Dialogue {
private:
  std::string description;
  std::vector<std::string> choices;

public:
  Dialogue() {}

  Dialogue(std::string description, std::vector<std::string> choices) {
    this->description = description;
    this->choices = choices;
  }

  int activate() {
    std::cout << description << std::endl;

    for(int i = 0; i < this->choices.size(); ++i) {
      std::cout << i+1 << ": " << this->choices[i] << std::endl;
    }

    int userInput = -1;

    while(true) {
      std::cin >> userInput;
      if(userInput >= 0 && userInput <= choices.size()) {
        return userInput;
      }

      std::cout << "Please choose again." << std::endl;
    }

    return 0;
  }
};

#endif /* DIALOGUE_HPP */
