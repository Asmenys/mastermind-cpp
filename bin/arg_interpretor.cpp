#include "arg_interpretor.h"
#include <iostream>
#include <vector>

std::vector<std::vector<std::string>> Arg_Interpretor::commands = {
    {"h", "Prints this page"}, {"p", "Starts the game"}};

void Arg_Interpretor::interpret_args(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    start_engine(argv[i][0]);
  }
}

void Arg_Interpretor::start_engine(char command) {
  if (command == 'p' || command == 'P') {
    std::cout << "start the game\n";
  } else if (command == 'h' || command == 'H') {
    help();
  }
}
void Arg_Interpretor::help() {
  std::cout << "[OPTION] :: DESCRIPTION" << std::endl;
  for (int i = 0; i < commands.size(); i++) {
    std::cout << "[" << commands[i][0] << "] :: "
              << " " << commands[i][1] << std::endl;
  }
}
