#include <random>
#include <vector>
class CodeKeeper {
public:
  static void set_code(std::vector<int> input_code);
  static void compare_code(std::vector<int> input_code);
  static std::vector<int> generate_code();

private:
  static std::vector<int> code;
  static bool validate_input_code(std::vector<int> input_code);
};