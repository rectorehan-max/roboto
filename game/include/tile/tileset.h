#pragma once
#include <raylib.h>
#include "tool/flatmap.h"
#include <string>

class Tileset {

protected:
    Tileset(Vector2 tilesetSize, Vector2 tileSize, std::vector<int> vec);
    Tileset(Vector2 tilesetSize, Vector2 tileSize, const std::string& path);

    Vector2 tilesetSize;
    Vector2 tileSize;
    Flatmap<int> fmap;

};
