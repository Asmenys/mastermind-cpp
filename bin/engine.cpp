#include "engine.h"
#include "code_breaker.h"
#include "code_master.h"
#include <iostream>
#include <ostream>
#include <vector>

void game_startup_message() {
  std::cout << "Select the desired game mode" << std::endl;
  std::cout << "1: Code Breaker" << std::endl;
  std::cout << "2: Code Master" << std::endl;
  std::cout << "Anything else to exit the program" << std::endl;
}

void direction_message() {
  std::cout << "Feel free to exit the game or continue playing it by giving \n"
               "the appropriate commannds [1/2/Any]"
            << std::endl;
}
int Engine::user_game_mode_selection() {
  int game_mode_selection;
  std::cin >> game_mode_selection;
  return game_mode_selection;
}

void Engine::engine_loop() {
  int gm_selection;
  game_startup_message();
  while ((gm_selection = user_game_mode_selection())) {
    std::cout << "\x1B[2J\x1B[H";
    if (gm_selection == 1) {
      CodeBreaker::game_loop();
    } else if (!gm_selection) {
      break;
    } else {
      CodeMaster::game_loop();
    }
    direction_message();
  }
}