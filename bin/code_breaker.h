#include "game_mode.h"
class CodeBreaker: private GameMode {
public:
  static void game_loop();

private:
  static int code_breaker_cycle();
};