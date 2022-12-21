#include <vector>
class Engine {
public:
  static void game_loop();
  static void code_breaker_loop();

private:
  static int user_game_mode_selection();
  static int code_breaker_cycle();
  static void code_master_cycle();
  static void print_guess_results(std::vector<int> guess_comparison_results);
  static bool win_condition_check(std::vector<int> guess_comparison_results);
  static void print_vector(std::vector<int> input_vector);
};