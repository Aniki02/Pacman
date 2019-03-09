
#include <stdio.h>
#include "Game.hpp"
#include "GameScreen.hpp"

using namespace sf;
int main(){

    Game * game = new Game();
    Screen * gameScreen = new GameScreen(game->_window);
    game->setScreen(gameScreen);
    game->run();
    return 0;
}
