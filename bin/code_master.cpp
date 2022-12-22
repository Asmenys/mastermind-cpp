#include "code_master.h"
#include "code_keeper.h"
#include <iostream>
#include <vector>

std::vector<int> CodeMaster::digit_pool = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
void CodeMaster::game_loop() {
  clear_screen();
  // std::cout << "Come up with a secret code" << std::endl;
  // CodeKeeper::set_code(CodeKeeper::user_code_input());
  std::cout << "Tingiu algoritma (efektyvu) rasyti, taigi kompiuteris "
               "problemos nespres, sueis ir 8\n\n";
}

void CodeMaster::code_master_cycle() {
  std::vector<int> current_guess = generate_primary_guess();
  std::vector<int> comparison_results = CodeKeeper::compare_code(current_guess);
  while (comparison_sum(comparison_results) == 0) {
    digit_pool.erase(digit_pool.begin());
    digit_pool.erase(digit_pool.begin());
    current_guess = generate_primary_guess();
    comparison_results = CodeKeeper::compare_code(current_guess);
  }
}

std::vector<int> CodeMaster::generate_primary_guess() {
  std::vector<int> primary_guess = {digit_pool[0], digit_pool[0], digit_pool[1],
                                    digit_pool[1]};
  return primary_guess;
}

int CodeMaster::comparison_sum(std::vector<int> comparison_results) {
  int sum = 0;
  for (int i = 0; i < comparison_results.size(); i++) {
    sum += comparison_results.at(i);
  }
  return sum;
}
