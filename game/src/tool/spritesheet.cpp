#include "tool/spritesheet.h"
#include <iostream>
#include "global.h"

namespace sprsheet {
    std::unordered_map<std::string, int> users;
}

SpriteSheet::SpriteSheet(const std::string name, std::string path,
                        const int frameWidth, const int frameHeight,
                        const int numRows, const int numCols, const int maxFrames) :

                        name(name), path_storage(std::move(path)), path(path_storage.c_str()),
                        frameWidth(frameWidth), frameHeight(frameHeight),
                        numRows(numRows), numCols(numCols),
                        maxFrames(maxFrames) {

    global::printIsValidFile(path);
}


void SpriteSheet::smartLoad() {
    if (this->isValidLoad()) {
        texture = LoadTexture(path);
        this->finishedLoading(); 
        std::cout << this->name << " has been loaded " << 
                  sprsheet::users.at(this->name) << std::endl;
    }
}

void SpriteSheet::smartUnload() {
    if (sprsheet::users.at(this->name) == 0 && this->isLoaded()) {
        UnloadTexture(texture);
        std::cout << this->name << " has been unloaded \n";
        this->resetLoadingState(); 
    }
}

void SpriteSheet::forceUnload() {
    UnloadTexture(texture);
}

void SpriteSheet::addUserTally() {
    sprsheet::users.at(this->name)++; 
    std::cout << this->name << " num of users: " << 
              sprsheet::users.at(this->name) << std::endl;
}
void SpriteSheet::removeUserTally() {
    auto it = sprsheet::users.find(this->name);
    if (it == sprsheet::users.end() || it->second <= 0) return;

    it->second--; 
    std::cout << this->name << " (removed users) num of users: " <<
              sprsheet::users.at(this->name) << std::endl;

    if (it->second <= 0) {
        std::cout << "ptr of : " << name << " was deleted. \n";
        delete this;
    }
}
