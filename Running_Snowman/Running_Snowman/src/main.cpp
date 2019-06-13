#include "global.h"
#include "Window.h"
#include "Menu.h"
#include "Game.h"

int main() {
  Game game;
  game.init();

  while (!game.isClose()) {
    game.processInput();
    game.clear();
    game.update();
    game.render();
  }

  return 0;
}