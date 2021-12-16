#include "Apples.hpp"

namespace apples {

    Apples::Apples(float x, float y, float velocity) {
        m_x = x;
        m_y = y;
        m_velocity = velocity;
        initPhysics();
        initTexture();
        initSprite();
    }

    Apples::~Apples() {}

    sf::Vector2f Apples::getPosition() {
        return sprite.getPosition();
    }

    sf::FloatRect Apples::getGlobalBounds() {
        return sprite.getGlobalBounds();
    }

    void Apples::initSprite() {
        sprite.setPosition(m_x, m_y);
        sprite.setColor(sf::Color::Red);
        sprite.setTexture(texture);
        sprite.setScale(0.1f, 0.1f);
    }

    void Apples::initTexture() {
        if (!texture.loadFromFile("../assets/apple.png")) {
            std::cout << "ERRROR: cannot load 'apple.png' file" << std::endl;
        }
    }

    void Apples::initPhysics() {
        gravity = 0.2f;
    }

    void Apples::setPosition(float x, float y) {
        sprite.setPosition(x, y);
    }

    void Apples::resetVelocityY() {
        m_velocity = 0;
    }

    void Apples::update() {
        if(!onFloor) {
            m_velocity += gravity;
        }
        sprite.move(0, m_velocity);
    }

    void Apples::render(sf::RenderTarget &target) {
        target.draw(sprite);
    }

}
