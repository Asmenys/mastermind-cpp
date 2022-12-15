#include "../bin/arg_interpretor.h"
#include <vector>

std::vector<std::vector<std::string>> Arg_Interpretor::commands = {};

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
void Arg_Interpretor::help(){
  for(int i = 0; i<command_count; i++)
  {
    std::cout<<command_options[i]<<" "<<command_definitions[i]<<std::endl;
  }
}
