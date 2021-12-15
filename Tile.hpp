#pragma once

enum class TileType {
    SOLID, TRANSPARENT
};

namespace tile {
    class Tile {
    private:
        sf::Sprite sprite;
    public:

        Tile(sf::Texture &texture_sheet, sf::IntRect texture_rect, const TileType tileType);

        ~Tile();

        sf::FloatRect getGlobalBounds();

        void update();

        void render(sf::RenderTarget &target);
    };
}
