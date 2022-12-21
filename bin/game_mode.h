#include <vector>
#ifndef GAMEMODE_H
#define GAMEMODE_H
class GameMode {
public:
  static void print_guess_results(std::vector<int> guess_comparison_results);
  static bool win_condition_check(std::vector<int> guess_comparison_results);
  static void print_vector(std::vector<int> input_vector);
};
#endif