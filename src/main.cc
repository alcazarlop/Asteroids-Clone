#include "game_controller.h"
int main() {
  GameController* game = new GameController();
  return game->loop();
}