#include "tool/sprite.h"
#include <iostream>
#include "global.h"

namespace spr {
    std::unordered_map<std::string, int> users;
}

Sprite::Sprite(const std::string name, std::string path,
              const int width, const int height) : 

              name(name), path_storage(std::move(path)), path(path_storage.c_str()),
              width(width), height(height) {
    
    global::printIsValidFile(path);

}

void Sprite::smartLoad() {
    if (this->isValidLoad()) {
        texture = LoadTexture(path);
        this->finishedLoading(); 
        std::cout << this->name << " has been loaded " << 
                  spr::users.at(this->name) << std::endl;
    }
}

void Sprite::smartUnload() {
    if (spr::users.at(this->name) == 0 && this->isLoaded()) {
        UnloadTexture(texture);
        std::cout << this->name << " has been unloaded \n";
        this->resetLoadingState(); 
    }
}

void Sprite::forceUnload() {
    UnloadTexture(texture);
}

void Sprite::addUserTally() {
    spr::users.at(this->name)++; 
    std::cout << this->name << " num of users: " << 
              spr::users.at(this->name) << std::endl;
}

void Sprite::removeUserTally() {
    auto it = spr::users.find(this->name);
    if (it == spr::users.end() || it->second <= 0) return;

    it->second--; 
    std::cout << this->name << " (removed users) num of users: " <<
              spr::users.at(this->name) << std::endl;
    if (it->second <= 0) {
        delete this;
        std::cout << "ptr of: " << name << " was deleted. \n";
    }
}

