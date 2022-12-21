#include "code_keeper.h"
#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>
std::vector<int> CodeKeeper::code;
int CodeKeeper::code_length = 4;
void CodeKeeper::set_code(std::vector<int> input_code) { code = input_code; }

bool CodeKeeper::validate_input_code(std::vector<int> input_code) {
  bool valid = true;
  if (input_code.size() == code_length) {
    for (int i = 0; i < input_code.size(); i++) {
      if (input_code.at(i) > 9 || input_code.at(i) < 0) {
        valid = false;
        break;
      }
    }
  } else {
    valid = false;
  }
  return valid;
}

std::vector<int> CodeKeeper::generate_code() {
  std::vector<int> generated_code;
  std::vector<int> number_pool = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::random_device rdev;
  std::mt19937 gen(rdev());
  for (int i = 0; i < code_length; i++) {
    std::uniform_int_distribution<> distrib(0, number_pool.size());
    int rnd_index = distrib(gen);
    generated_code.push_back(number_pool.at(rnd_index));
    number_pool.erase(number_pool.begin() + rnd_index);
  }

  return generated_code;
}

std::vector<int> CodeKeeper::user_code_input() {
  std::vector<int> code_input;
  int digit_input;
  for (int i = 0; i < code_length; i++) {
    while (std::cin >> digit_input && digit_input < 0 && digit_input > 9) {
    }
    code_input.push_back(digit_input);
  }
  return code_input;
}

std::vector<int> CodeKeeper::compare_code(std::vector<int> input_code) {
  std::vector<int> comparison_results, tmp_code = code;
  for (int i = 0; i < tmp_code.size(); i++) {
    if (input_code.at(i) == tmp_code.at(i)) {
      tmp_code.at(i) = -1;
      comparison_results.push_back(1);
    }
  }
  for (int i = 0; i < code_length; i++) {
    for (int j = 0; j < code_length; j++) {
      if (input_code.at(i) == tmp_code.at(j)) {
        tmp_code.at(j) = -1;
        comparison_results.push_back(2);
      }
    }
  }
  for (int i = comparison_results.size(); i < code_length; i++) {
    comparison_results.push_back(0);
  }
  return comparison_results;
}