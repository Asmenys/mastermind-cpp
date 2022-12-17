#include "../bin/code_keeper.h"
#include <vector>
std::vector<int> CodeKeeper::code;

void CodeKeeper::set_code(std::vector<int> input_code) { code = input_code; }

bool CodeKeeper::validate_input_code(std::vector<int> input_code) {
  bool valid = true;
  if (input_code.size() == 4) {
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
  std::random_device rdev;
  std::mt19937 gen(rdev());
  std::uniform_int_distribution<> distrib(1, 9);
  for (int i = 0; i < 4; i++) {
    generated_code.push_back(distrib(gen));
  }
  return generated_code;
}