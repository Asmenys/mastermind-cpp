#include "../bin/arg_interpretor.h"
#include <iostream>
void Arg_Interpretor::interpret_args(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    call_comand(argv[i][0]);
  }
}

void Arg_Interpretor::call_comand(char command) {
  if (command == 'p' || command == 'P') {
    std::cout << "start the game\n";
  } else if (command == 'h' || 'H') {
    std::cout << "hello\n";
  }
}