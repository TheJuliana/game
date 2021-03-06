cmake_minimum_required(VERSION 3.15)
project(game)

set(CMAKE_CXX_STANDARD 14)

include_directories("ext/SFML/include/")
include_directories("inc/")

link_directories("ext/SFML/lib/")

add_executable(
        "${PROJECT_NAME}" main.cpp
        inputs.hpp
        Game.cpp
        Game.hpp
        Player.cpp
        Player.hpp
        Apples.cpp
        Apples.hpp
)

add_definitions(-DSFML_STATIC)

target_link_libraries("${PROJECT_NAME}" sfml-graphics-s
        sfml-window-s
        sfml-system-s
        opengl32
        freetype
        winmm
        gdi32
        sfml-audio-s
        openal32
        flac
        vorbisenc
        vorbisfile
        vorbis
        ogg)

target_link_libraries("${PROJECT_NAME}"
        debug sfml-graphics-s-d
        debug sfml-window-s-d
        debug sfml-system-s-d
        debug sfml-audio-s-d)

target_link_libraries("${PROJECT_NAME}"
        optimized sfml-graphics-s
        optimized sfml-window-s
        optimized sfml-system-s
        optimized sfml-audio-s)

target_link_libraries("${PROJECT_NAME}" opengl32 freetype winmm gdi32 openal32 flac vorbisenc vorbisfile vorbis ogg)

file(COPY "assets" DESTINATION "/")
