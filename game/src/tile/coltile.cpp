#include "tile/coltile.h"
#include "cam.h"

CollisionTileset::CollisionTileset(Vector2 tilesetSize, Vector2 tileSize, 
                                  const std::string& path) :

                                  Tileset(tilesetSize, tileSize, path) {

    color = BLUE;

    generateRecs();
    generateRecs_p();
}

void CollisionTileset::generateRecs() {
    fmap.forEachPlace([this](int x, int y, int num) {
        if (num != 0) {
            Rectangle rec = { x * tileSize.x, y * tileSize.y, tileSize.x, tileSize.y }; 
            recs.push_back(rec);
        }
    });
}

void CollisionTileset::generateRecs_p() {
    for (Rectangle& rec : recs) {
        recs_p.push_back(&rec);
    }
}

void CollisionTileset::draw() {
    for (Rectangle& rec : recs) {
        if (!cam::recIsVisible(rec)) continue;
        
        DrawRectangleRec(rec, color);
    }
}

std::vector<Rectangle*> CollisionTileset::getRecs_p() {
    return recs_p;
}
