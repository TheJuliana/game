#pragma once
enum PLAYER_ANIMATION_STATES {
    IDLE = 0, MOVING_LEFT, MOVING_RIGHT, LEFT_JUMPING, RIGHT_JUMPING
};

namespace player {
    class Player {
    private:
        sf::Sprite sprite;
        sf::Texture textureSheet;
        sf::Clock animationTimer; //таймер задержки анимации
        // анимация
        short animState;
        sf::IntRect currentFrame;
        bool animationSwitch;
        //физика
        sf::Vector2f velocity;

        float velocityMin;
        float drag;
        float gravity;


        //инициализация характеристик
        void initPhysics();

        void initVariables();

        void initTexture();

        void initSprite();

        void initAnimations();

    public:
        Player();

        ~Player();

        sf::Vector2f getPosition();

        sf::FloatRect getGlobalBounds();

        void setPosition(float x, float y);

        void resetVelocityY();

        //функции

        void move(float dir_x, float dir_y);

        void updatePhysics();

        void updateMovement();

        void updateAnimations();

        void update();

        void render(sf::RenderTarget &target);

        bool onFloor;
    };
}

