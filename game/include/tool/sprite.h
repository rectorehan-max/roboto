#pragma once
#include <raylib.h>
#include "tool/loadable.h"
#include <string>
#include <unordered_map>

namespace spr {
    extern std::unordered_map<std::string, int> users;
}

class Sprite : public Loadable {

public:
    Sprite(const std::string name, std::string path,
           const int width, const int height);

    Texture2D texture;
    const std::string name;
    const std::string path_storage; 
    const char* path;

    const int width;
    const int height;

    void smartLoad();
    void smartUnload();
    void forceUnload();
    
    void addUserTally();
    void removeUserTally();
};
