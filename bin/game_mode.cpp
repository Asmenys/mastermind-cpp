#include "game_mode.h"
#include "iostream"

void GameMode::print_guess_results(std::vector<int> guess_comparison_results) {
  print_vector(guess_comparison_results);
  std::cout << std::endl;
}

bool GameMode::win_condition_check(std::vector<int> guess_comparison_results) {
  bool win = true;
  for (int i = 0; i < guess_comparison_results.size(); i++) {
    if (guess_comparison_results.at(i) != 1) {
      win = false;
      break;
    }
  }
  return win;
}

void GameMode::print_vector(std::vector<int> input_vector) {
  for (int i = 0; i < input_vector.size(); i++) {
    std::cout << input_vector.at(i);
  }
}