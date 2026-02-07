#include <tile/tileset.h>
#include "fio.h"

Tileset::Tileset(Vector2 tilesetSize, Vector2 tileSize, std::vector<int> vec) :
                tilesetSize(tilesetSize), tileSize(tileSize),
                fmap(tilesetSize.x, tilesetSize.y) {

    fmap.setGrid(vec);

}

Tileset::Tileset(Vector2 tilesetSize, Vector2 tileSize, const std::string& path) :
                tilesetSize(tilesetSize), tileSize(tileSize),
                fmap(tilesetSize.x, tilesetSize.y) {

    fio::in::load_fmap_int(path, this->fmap);
}

