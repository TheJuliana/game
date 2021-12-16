#include "inputs.hpp"
#include "Player.hpp"
#include "Apples.hpp"

#pragma once

namespace game {
    class Game {
    private:
        sf::RenderWindow window;
        sf::Texture background_image;
        sf::Sprite background;
        sf::Event ev;
        player::Player *player;

        std::vector<apples::Apples*> apples;
        int numbOfApples;

        void initWindow();

        void initPlayer();

        void initBackground();

        void initApples();

    public:
        Game();

        virtual ~Game();

        void updateCollision();

        void updatePlayer();

        void renderPlayer();

        void updateApples();

        void renderApples();

        void update();

        void render();

        const sf::RenderWindow &getWindow();

    };

}
