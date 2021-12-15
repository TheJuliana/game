#include "stdfx.hpp"
#include "Game.hpp"
#include "Player.hpp"

namespace game {
    void Game::initWindow() {
        window.create(
                sf::VideoMode(1200, 800), //создание окна
                "Game", //название окна
                sf::Style::Close | sf::Style::Titlebar
        );// окно будет иметь кнопку закрытия и название
        window.setFramerateLimit(60);
        // this->window.setFramerateLimit(144);
    }

    Game::Game() {
        initWindow(); //вызов окна
        initBackground();
        //initMap();
        initPlayer();

    }

    Game::~Game() {
        delete player; //удаляет игрока
    }

    const sf::RenderWindow &Game::getWindow() {
        return window;
    }

    void Game::update() {
        //события окна спроса (poll)
        while (window.pollEvent(ev)) { //получает события с окна и отпраляет их в ev
            if (ev.type == sf::Event::Closed) {
                window.close();
            } else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape) {
                window.close(); //окно закрывается при нажатии на esc
            }

            /*if(this->ev.type == sf::Event::KeyPressed && (this->ev.key.code == sf::Keyboard::Escape ||
                    this->ev.key.code == sf::Keyboard::A ||
                    this->ev.key.code == sf::Keyboard::D ||
                    this->ev.key.code == sf::Keyboard::W ||
                    this->ev.key.code == sf::Keyboard::S)) {
               this->player->resetAnimationTimer();
            }*/
        }

        //for (int i =0; i < gridLength)

        updatePlayer();
        updateCollision();
    }

    void Game::render() {
        window.clear();
        //рендер игры
        window.draw(background);
        //map.Draw(window);
        renderPlayer();

        window.display();
    }

    void Game::updatePlayer() {
        player->update();
    }

    void Game::initPlayer() {
        player = new player::Player();
    }

    void Game::renderPlayer() {
        player->render(window);
    }

    void Game::updateCollision() {
        //collision bottom of screen
        if (player->getPosition().y + player->getGlobalBounds().height > window.getSize().y) {

            player->resetVelocityY();
            player->setPosition(player->getPosition().x,window.getSize().y - player->getGlobalBounds().height);
            player->onFloor = true;
            //onGround = true;
        } else {player->onFloor = false;};
    }

    void Game::initBackground() {
        if (!background_image.loadFromFile("../textures/background.png")) {
            std::cout << "ERROR::Player: cannot load 'background.png' file " << std::endl;
        } else {
            background.setTexture(background_image);
        }
    }
}
/*void Game::initMap() {
    if(!this->map.LoadFromFile("map.xml")) {
        std::cout << "ERROR::Player: cannot load 'map.xml' file " << std::endl;
    }
}*/

