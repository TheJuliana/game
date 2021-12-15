#pragma once
#include "Tile.hpp"
#include "stdfx.hpp"

namespace tilemap {
    class TileMap {
    private:
        std::vector<std::vector<tile::Tile*>> tiles;
    public:
        TileMap();

        ~TileMap();

        //функции
        void addTile(unsigned x, unsigned y);

        void removeTile(unsigned x, unsigned y);

        void update();

        void render();
    };
}



