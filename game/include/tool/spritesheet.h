#pragma once
#include <raylib.h>
#include "tool/loadable.h"
#include <unordered_map>
#include <string>

namespace sprsheet {
    extern std::unordered_map<std::string, int> users;
}

class SpriteSheet : public Loadable {

public:
    SpriteSheet(const std::string name, std::string path,
               const int frameWidth, const int frameHeight,
               const int numRows, const int numCols,
               const int maxFrames);

    Texture2D texture;
    const std::string name;
    const std::string path_storage;
    const char* path;

    const int frameWidth;
    const int frameHeight;
    const int numCols;
    const int numRows;
    const int maxFrames;

    void smartLoad();
    void smartUnload();
    void forceUnload();
    
    void addUserTally();
    void removeUserTally();
};
