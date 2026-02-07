#pragma once
#include <raylib.h>
#include <string>

namespace global {
    constexpr int SCREEN_WIDTH = 1280;
    constexpr int SCREEN_HEIGHT = 768;
    constexpr int DEFAULT_PIXEL_SIZE = 64;

    constexpr Vector2 DEFAULT_RECTANGLE_SIZE = { DEFAULT_PIXEL_SIZE, DEFAULT_PIXEL_SIZE };
    constexpr Vector2 CAMERA_CENTER = { SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };
    constexpr Vector2 DEFAULT_ROOM_SIZE = { SCREEN_WIDTH, SCREEN_HEIGHT };
    constexpr Vector2 DEFAULT_TILESET_SIZE = { DEFAULT_ROOM_SIZE.x / DEFAULT_PIXEL_SIZE, 
                                               DEFAULT_ROOM_SIZE.y / DEFAULT_PIXEL_SIZE };

    Vector2 getCenter(Rectangle rec);
    void printIsValidFile(const std::string& path_str);

}
