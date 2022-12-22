#include "game_mode.h"
#include <vector>
class CodeMaster : private GameMode {
public:
  static void game_loop();

private:
  static std::vector<int> digit_pool;
  static std::vector<int> generate_guess();
  static std::vector<int> generate_primary_guess();
  static void code_master_cycle();
  static int comparison_sum(std::vector<int> comparison_results);
};