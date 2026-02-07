#pragma once
#include <unordered_map>
#include <string>
#include "ent/entity.h"
#include "tool/sprite.h"
#include "tool/spritesheet.h"

namespace globalprp {
    extern std::unordered_map<std::string, Entity*> entMap; // For Global Entity Classes
    extern std::unordered_map<std::string, Sprite*> sprMap; // For Sprites 
    extern std::unordered_map<std::string, SpriteSheet*> sprsheetMap; // For Sprite Sheets

    void createProps();  
    void deleteProps();

    Entity* getEnt_p(std::string name);
    Sprite* getSpr_p(const std::string& name);
    SpriteSheet* getSprsheet_p(const std::string& name);

    namespace ent {
        void add();
    }
}
