#include "inputs.hpp"
#include "Game.hpp"

int main() {
    srand(time(0));
    game::Game game;

    while(game.getWindow().isOpen()){
        game.update();
        game.render();
    }
    return 0;
}
