#include "inputs.hpp"
#include "Game.hpp"

namespace game {
    void Game::initWindow() {
        window.create(sf::VideoMode(1200, 800),"Just The Peppa Pig");
        window.setFramerateLimit(60);
    }

    Game::Game() {
        initWindow(); //вызов окна
        initBackground();
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

        }
        updatePlayer();
        updateCollision();
    }

    void Game::render() {
        window.clear();
        //рендер игры
        window.draw(background);
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
        //столкновение с нижней частью экрана
        if (player->getPosition().y + player->getGlobalBounds().height > window.getSize().y) {
            player->resetVelocityY();
            player->setPosition(player->getPosition().x,window.getSize().y - player->getGlobalBounds().height);
            player->onFloor = true;
        } else {player->onFloor = false;};
        if (player->getPosition().x + player->getGlobalBounds().width > window.getSize().x) {
            //player->resetVelocityY();
            player->setPosition(0, player->getPosition().y);
        };
        if (player->getPosition().x + player->getGlobalBounds().width < 0) {
            //player->resetVelocityY();
            player->setPosition(window.getSize().x- player->getGlobalBounds().width, player->getPosition().y);
        };
    }

    void Game::initBackground() {
        if (!background_image.loadFromFile("../assets/background.png")) {
            std::cout << "ERROR::Player: cannot load 'background.png' file " << std::endl;
        } else {
            background.setTexture(background_image);
        }
    }

}


