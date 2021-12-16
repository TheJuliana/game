cmake_minimum_required(VERSION 3.20)
project(game)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libstdc++ -static-libgcc")

include_directories("c:/SFML/include/")
include_directories("inc/")

link_directories("c:/SFML/lib/")

add_executable(
        game main.cpp
        inputs.hpp
        Game.cpp
        Game.hpp
        Player.cpp
        Player.hpp
        #Tile.cpp
        #Tile.hpp
        #TileMap.cpp
        #TileMap.hpp
)

add_definitions(-DSFML_STATIC)

target_link_libraries(game sfml-graphics-s-d
        sfml-window-s-d
        sfml-system-s-d
        opengl32
        freetype
        winmm
        gdi32
        sfml-audio-s-d
        openal32
        flac
        vorbisenc
        vorbisfile
        vorbis
        ogg)