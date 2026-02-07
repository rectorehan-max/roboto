#pragma once
#include "tile/tileset.h"
#include <vector>

class CollisionTileset : public Tileset {

public:
    CollisionTileset(Vector2 tilesetSize, Vector2 tileSize, const std::string& path);

    void draw();

    std::vector<Rectangle*> getRecs_p();

private:
    Color color;

    std::vector<Rectangle> recs;
    std::vector<Rectangle*> recs_p;

    void generateRecs();
    void generateRecs_p();

};

