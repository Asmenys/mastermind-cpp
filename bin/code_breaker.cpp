#include "code_breaker.h"
#include "code_keeper.h"
#include <iostream>
void CodeBreaker::game_loop() {
  clear_screen();
  CodeKeeper::set_code(CodeKeeper::generate_code());
  int turns = 0;
  while (code_breaker_cycle()) {
    turns++;
  }
  std::cout << "You took " << turns
            << " guesses, \ncan you do it in fewer next time?\n" << std::endl;
}

int CodeBreaker::code_breaker_cycle() {
  std::vector<int> user_guess = CodeKeeper::user_code_input();
  std::vector<int> guess_comparison_results =
      CodeKeeper::compare_code(user_guess);
  print_guess_results(guess_comparison_results);
  if (win_condition_check(guess_comparison_results)) {
    clear_screen();
    std::cout << "Well done, the number was ";
    print_vector(user_guess);
    std::cout << ". ";
    return 0;
  } else {
    return 1;
  }
}
