#pragma once
#include "inputs.hpp"

namespace apples {
    class Apples {
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        float gravity;
        float m_x, m_y, m_velocity;

    public:
        Apples(float x, float y, float velocity);

        ~Apples();
        sf::Vector2f getPosition();
        sf::FloatRect getGlobalBounds();


        void initSprite();
        void initPhysics();
        void initTexture();
        void setPosition(float x, float y);
        void resetVelocityY();
        void update();
        void render(sf::RenderTarget &target);

        bool onFloor;
    };
}


