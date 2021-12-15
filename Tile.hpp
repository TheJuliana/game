#pragma once

enum class TileType {
    SOLID, TRANSPARENT
};
class Tile {
private:
    sf::Sprite sprite;
    const bool damaging;
public:
    TileType tileType;
    Tile(sf::Texture& texture_sheet, sf::IntRect texture_rect, const TileType tileType, bool damaging = false);
    const sf::FloatRect getGlobalBounds();

    void update();
    void render(sf::RenderTarget& target);
};

