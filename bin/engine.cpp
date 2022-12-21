#include "engine.h"
#include "code_keeper.cpp"
#include <iostream>
#include <ostream>
#include <vector>

int Engine::user_game_mode_selection() {
  std::cout << "Select the desired game mode" << std::endl;
  std::cout << "1: Code Breaker" << std::endl;
  std::cout << "2: Code Master" << std::endl;
  int game_mode_selection;
  std::cin >> game_mode_selection;
  if (game_mode_selection == 1 || game_mode_selection == 2) {
    return game_mode_selection;
  } else {
    return 1;
  }
}

void Engine::code_breaker_loop() {
  CodeKeeper::set_code(CodeKeeper::generate_code());
  int turns = 0;
  while (code_breaker_cycle()) {
    turns++;
  }
  std::cout << "You took " << turns
            << " guesses, can you do it in fewer next time?";
}

int Engine::code_breaker_cycle() {
  std::vector<int> user_guess = CodeKeeper::user_code_input();
  std::vector<int> guess_comparison_results =
      CodeKeeper::compare_code(user_guess);
  print_guess_results(guess_comparison_results);
  if (win_condition_check(guess_comparison_results)) {
    std::cout << "Well done, the number was ";
    print_vector(user_guess);
    std::cout<<". ";
    return 0;
  } else {
    return 1;
  }
}

void Engine::print_guess_results(std::vector<int> guess_comparison_results) {
  print_vector(guess_comparison_results);
  std::cout << std::endl;
}

bool Engine::win_condition_check(std::vector<int> guess_comparison_results) {
  bool win = true;
  for (int i = 0; i < guess_comparison_results.size(); i++) {
    if (guess_comparison_results.at(i) != 1) {
      win = false;
      break;
    }
  }
  return win;
}

void Engine::print_vector(std::vector<int> input_vector) {
  for (int i = 0; i < input_vector.size(); i++) {
    std::cout << input_vector.at(i);
  }
}