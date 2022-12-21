#include <random>
#include <vector>
class CodeKeeper {
public:
  static void set_code(std::vector<int> input_code);
  static std::vector<int> compare_code(std::vector<int> input_code);
  static std::vector<int> generate_code();
  static std::vector<int> user_code_input();
  static int code_length;

private:
  static std::vector<int> code;
  static bool validate_input_code(std::vector<int> input_code);
};