#include "inputs.hpp"
#include "Player.hpp"

namespace player {
    Player::Player() {
        initVariables();
        initTexture();
        initSprite();
        initAnimations();
        initPhysics();
    }

    Player::~Player() {}

    void Player::update() {
        updateMovement();
        updateAnimations();
        updatePhysics();
    }

    void Player::render(sf::RenderTarget &target) {
        target.draw(sprite); //отрисовка спрайта
    }

    void Player::initTexture() {
        if (!textureSheet.loadFromFile("../assets/allpeppas.png")) { //загрузка текстуры персонажа
            std::cout << "ERROR::Player: cannot load 'allpeppas.png' file " << std::endl;
        }
    }

    void Player::initSprite() {
        sprite.setTexture(textureSheet); //устанавливаем полную текстуру персонажа
        currentFrame = sf::IntRect(0, 0, 219, 219);
        sprite.setTextureRect(currentFrame); //устанавливаем только кусок текстуры
        sprite.setScale(0.8f, 0.8f); //подгонка персонажа под адекватный размер
    }

    void Player::updateMovement() {
        animState = IDLE;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            move(-1.f, 0.f); //движение игрока налево
            animState = MOVING_LEFT;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                if (onFloor) {
                    move(-1.f, -50.f);
                    onFloor = false;
                }
                animState = LEFT_JUMPING;
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            move(1.f, 0.f); //движение направо
            animState = MOVING_RIGHT;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                if (onFloor) {
                    move(1.f, -50.f);
                    onFloor = false;
                }
                animState = RIGHT_JUMPING;
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            if (onFloor) {
                    move(0, -50.f);
                    onFloor = false;
            }
            animState = RIGHT_JUMPING;
        };
    }

    void Player::updateAnimations() {
        if (animState == IDLE) {
            if (animationTimer.getElapsedTime().asMilliseconds() >=
                250.f) { //задержка анимации//смена анимаций движения персонажа
                currentFrame.top = 0.f;
                currentFrame.left += 219.f;
                if (currentFrame.left >= 876.f) {
                    currentFrame.left = 0;
                }
                animationTimer.restart();
                sprite.setTextureRect(currentFrame); //установка конкретного куска текстуры движения
            }
        } else if (animState == MOVING_RIGHT) {
            if (animationTimer.getElapsedTime().asMilliseconds() >=
                100.f) { //задержка анимации//смена анимаций движения персонажа
                currentFrame.top = 219.f;
                currentFrame.left += 219.f;
                if (currentFrame.left >= 1533.f) {
                    currentFrame.left = 0;
                }
                animationTimer.restart();
                sprite.setTextureRect(currentFrame); //установка конкретного куска текстуры движения
                sprite.setScale(0.8f, 0.8f);
                sprite.setOrigin(0.f, 0.f);
            }
            sprite.setScale(0.8f, 0.8f);
            sprite.setOrigin(0.f, 0.f);

        } else if (animState == MOVING_LEFT) {
            if (animationTimer.getElapsedTime().asMilliseconds() >=
                100.f) { //задержка анимации//смена анимаций движения персонажа
                currentFrame.top = 219.f;
                currentFrame.left += 219.f;
                if (currentFrame.left >= 1533.f) {
                    currentFrame.left = 0;
                }
                animationTimer.restart();
                sprite.setTextureRect(currentFrame); //установка конкретного куска текстуры движения
            }
            sprite.setScale(-0.8f, 0.8f);
            sprite.setOrigin(sprite.getGlobalBounds().width / 0.5f, 0.f);
        } else if (animState == LEFT_JUMPING) {
            if (animationTimer.getElapsedTime().asMilliseconds() >=
                100.f) { //задержка анимации//смена анимаций движения персонажа
                currentFrame.top = 438.f;
                currentFrame.left += 219.f;
                if (currentFrame.left >= 1314.f) {
                    currentFrame.left = 1095.f;
                }
                animationTimer.restart();
                sprite.setTextureRect(currentFrame); //установка конкретного куска текстуры движения
            }
            sprite.setScale(-0.8f, 0.8f);
            sprite.setOrigin(sprite.getGlobalBounds().width / 0.5f, 0.f);
        } else if (animState == RIGHT_JUMPING) {
            if (animationTimer.getElapsedTime().asMilliseconds() >=
                100.f) { //задержка анимации//смена анимаций движения персонажа
                currentFrame.top = 438.f;
                currentFrame.left += 219.f;
                if (currentFrame.left >= 1314.f) {
                    currentFrame.left = 1095.f;
                }
                animationTimer.restart();
                sprite.setTextureRect(currentFrame); //установка конкретного куска текстуры движения
            }
            sprite.setScale(0.8f, 0.8f);
            sprite.setOrigin(0.f, 0.f);
        } else {
            animationTimer.restart();
        }
    }

    void Player::initAnimations() {
        animationTimer.restart();
        animationSwitch = true;
    }

    void Player::initVariables() {
        animState = IDLE;
    }

    void Player::initPhysics() {
        velocityMax = 0.8f;
        velocityMin = 0.5f;
        acceleration = 2.f;
        drag = 0.9f;
        gravity = 2.f;
        velocityMaxY = 15.f;
        onFloor = false;

    }

    void Player::updatePhysics() {
        if(!onFloor) {
            velocity.y += gravity;
        }//гравитация

        //торможение
        velocity *= drag;
        //ограничение торможения
        if (std::abs(velocity.x) < velocityMin) {
            velocity.x = 0.f;
        }
        if (std::abs(velocity.y) < velocityMin) {
            velocity.y = 0.f;
        }

        sprite.move(velocity);
    }

    void Player::move(const float dir_x, const float dir_y) {
        velocity.x += dir_x;
        velocity.y += dir_y;

    }

    sf::FloatRect Player::getGlobalBounds() {
        return sprite.getGlobalBounds();
    }

    void Player::resetVelocityY() {
        velocity.y = 0.f;
    }

    void Player::setPosition(const float x, const float y) {
        sprite.setPosition(x, y);
    }

    sf::Vector2f Player::getPosition() {
        return sprite.getPosition();
    }


}



