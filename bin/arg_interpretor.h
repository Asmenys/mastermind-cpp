#include <iostream>
#include <vector>
class Arg_Interpretor {
public:
  static void interpret_args(int argc, char *argv[]);
  static std::vector<std::vector<std::string>> commands;

private:
  static void start_engine(char argv);
  static void help();
};