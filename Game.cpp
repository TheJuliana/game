#include "inputs.hpp"
#include "Game.hpp"

namespace game {
    void Game::initWindow() {
        window.create(sf::VideoMode(1200, 800),"ThePeppaPig: Apples!");
        window.setFramerateLimit(60);
        if(!icon.loadFromFile("../assets/icon.png")) {
            std::cout << "ERROR: cannot load 'icon.png' file" << std::endl;
        } else {
            window.setIcon(351, 325, icon.getPixelsPtr());
        }
    }

    Game::Game() {
        initWindow(); //инициализация
        initBackground();
        initPlayer();
        initApples();
        initScore();
    }

    Game::~Game() {
        delete player; //удаление
        for (const auto& apple : apples) {
            delete apple;
        };
        apples.clear();
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
        updateApples();
        updateCollision();
        updateScore();
    }

    void Game::render() {
        window.clear();
        //рендер игры
        window.draw(background);
        renderApples();
        renderPlayer();
        renderScore();
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
            player->setPosition(0, player->getPosition().y);
        };
        if (player->getPosition().x + player->getGlobalBounds().width < 0) {
            player->setPosition(window.getSize().x- player->getGlobalBounds().width, player->getPosition().y);
        };

        for (const auto& apple : apples) {
            if (apple->getPosition().y + apple->getGlobalBounds().height > window.getSize().y) {
                apple->resetVelocityY();
                apple->setPosition(apple->getPosition().x, 0.f);
                apple->setVelocity(rand() % 5 + 1);
                apple->onFloor = true;
            } else {apple->onFloor = false;};
        }

        //собирание яблок
        for (const auto& apple : apples) {
            if ((apple->getPosition().y > (player->getPosition().y - apple->getGlobalBounds().height + 1)
            && apple->getPosition().y < (player->getPosition().y + player->getGlobalBounds().height + apple->getGlobalBounds().height - 1))
            && (apple->getPosition().x > (player->getPosition().x - apple->getGlobalBounds().width + 1)
             && apple->getPosition().x < (player->getPosition().x + player->getGlobalBounds().width + apple->getGlobalBounds().width - 1))) {
                apple->resetVelocityY();
                apple->setPosition(apple->getPosition().x, 0.f);
                apple->setVelocity(rand() % 5 + 1);
                caughtApples++;
            }
        }
    }

    void Game::initBackground() {
        if (!background_image.loadFromFile("../assets/background.png")) {
            std::cout << "ERROR::Player: cannot load 'background.png' file " << std::endl;
        } else {
            background.setTexture(background_image);
        }
    }

    void Game::initApples() {
        //появление яблок
        caughtApples = 0;
        numbOfApples = 5;
        for (int i = 0; i < window.getSize().x; i+= window.getSize().x / numbOfApples) {
            apples.push_back(new apples::Apples((float)i, 0.f, rand() % 5 + 1));
        }
    }

    void Game::updateApples() {
        for (const auto& apple : apples) {
            apple->update();
        }
    }

    void Game::renderApples() {
        for (const auto& apple : apples) {
            apple->render(window);
        }
    }

    void Game::initScore() {
        //создание текста с количеством собранных яблок
        if(!font.loadFromFile("../assets/Fuzzy.ttf")) {
            std::cout << "ERROR: cannot load 'Fuzzy.ttf' file" << std::endl;
        }
        score.setPosition(0.f, 0.f);
        score.setFont(font);
        score.setCharacterSize(24);
        score.setFillColor(sf::Color::Red);
        score.setStyle(sf::Text::Bold);
    }

    void Game::renderScore() {
        window.draw(score);
    }

    void Game::updateScore() {
        //обновление количества собранных яблок
        score.setString(std::string("Apples: x") + std::to_string(caughtApples));
        score.setPosition(0.f, 0.f);
    };

}


