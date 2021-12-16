#include "inputs.hpp"
#include "Player.hpp"
#include "TileMap.hpp"
#pragma once

namespace game {
    class Game {
    private:
        sf::RenderWindow window;
        sf::Texture background_image;
        sf::Sprite background;
        sf::Event ev;
        player::Player *player;

        void initWindow();

        void initPlayer();

        void initBackground();

    public:
        Game();

        virtual ~Game();

        void updateCollision();

        void updatePlayer();

        void renderPlayer();

        void update();

        void render();

        const sf::RenderWindow &getWindow();

    };

}
