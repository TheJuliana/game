#include "inputs.hpp"
#include "Game.hpp"

int main() {
    game::Game game;
    while(game.getWindow().isOpen()){
        game.update();
        game.render();
    }
    return 0;
}
