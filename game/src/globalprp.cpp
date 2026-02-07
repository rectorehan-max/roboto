#include "globalprp.h"
#include "fio.h"
#include <iostream>

namespace globalprp {
    std::unordered_map<std::string, Entity*> entMap;
    std::unordered_map<std::string, Sprite*> sprMap;
    std::unordered_map<std::string, SpriteSheet*> sprsheetMap;
}

void globalprp::createProps() {

    // always add this the last motherfucker
    ent::add();
}

void globalprp::deleteProps() {
    sprMap.clear();
    sprsheetMap.clear();
    entMap.clear();
}

Entity* globalprp::getEnt_p(std::string name) {
    auto it = entMap.find(name);

    if (it == entMap.end()) {
        std::cout << name << " : entity not found, returning nullptr \n";
        return nullptr;
    }
    return it->second;
}

Sprite* globalprp::getSpr_p(const std::string& name) {
    auto it = sprMap.find(name);

    if (it != sprMap.end()) {
        std::cout << name << " : sprite has been found. \n";
        return it->second;
    }

    Sprite* sprite_p = fio::in::loadGen_spr_p_h(name);

    if (sprite_p == nullptr) {
        std::cout << name << " does not exist in the addspr. \n";
        std::cout << "Returning nullptr. \n";
        return nullptr;
    }

    ::spr::users.try_emplace(name, 0);
    sprMap.try_emplace(name, sprite_p);

    std::cout << "Created sprite: " << name << std::endl;

    return sprite_p;
}

SpriteSheet* globalprp::getSprsheet_p(const std::string& name) {
    auto it = sprsheetMap.find(name);

    if (it != sprsheetMap.end()) {
        std::cout << name << " : sprite sheet has been found. \n";
        return it->second;
    }

    SpriteSheet* spritesheet_p = fio::in::loadGen_sprsheet_p_h(name);

    if (spritesheet_p == nullptr) {
        std::cout << name << "does not exist in addsprsheet. \n";
        std::cout << "Returning nullptr. \n";

        return nullptr;
    }

    ::sprsheet::users.try_emplace(name, 0);
    sprsheetMap.try_emplace(name, spritesheet_p);

    std::cout << "Created sprite sheet: " << name << std::endl;

    return spritesheet_p;
}
