#include "stdfx.hpp"
#include "Player.hpp"
#include "TileMap.hpp"
#pragma once
//extern bool onGround;
namespace game {
    class Game {
    private:
        sf::RenderWindow window;
        sf::Texture background_image;
        sf::Sprite background;
        sf::Event ev;
        player::Player *player;

        //TileMap map;

        void initWindow();

        //void initMap();
        void initPlayer();

        void initBackground();

    public:
        Game();

        virtual ~Game();

        //функции
        void updateCollision();

        void updatePlayer();

        void renderPlayer();

        void update();

        void render();

        const sf::RenderWindow &getWindow();

    };

}
