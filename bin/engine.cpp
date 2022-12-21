#include "engine.h"
#include "code_breaker.h"
#include <iostream>
#include <ostream>
#include <vector>

int Engine::user_game_mode_selection() {
  std::cout << "Select the desired game mode" << std::endl;
  std::cout << "0: Code Breaker" << std::endl;
  std::cout << "1: Code Master" << std::endl;
  int game_mode_selection;
  while (std::cin >> game_mode_selection &&
         !(game_mode_selection == 1 || game_mode_selection == 0)) {
    std::cout << "Incorrect selection" << std::endl;
  }
  return game_mode_selection;
}

void Engine::engine_loop() {
  if(user_game_mode_selection())
  {
    CodeBreaker::game_loop();
  }
}