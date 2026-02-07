#include <raylib.h>
#include "handler.h"
#include <iostream>

namespace handle {
    namespace room {
        Room* currRoom_p;
        RoomName prevRoom = NONE;

        std::unordered_map<RoomName, Room*> universe;
        RoomName currRoom = TEST_1;
    }
}

void handle::room::changeRoom(RoomName toRoom) {
    currRoom = toRoom;
}

void handle::room::roomSwitch() {
    auto it = universe.find(currRoom);

    if (it == universe.end()) {
        addRoom();
        it = universe.find(currRoom);
    }

    currRoom_p = it->second;
}

void handle::room::roomResets() {
    if (currRoom != prevRoom) {
        currRoom_p->nextReset();

        auto it = universe.find(prevRoom);
        if (it != universe.end()) {
            it->second->prevReset();
        }

        prevRoom = currRoom;
    }     
}

void handle::room::update() {
    if (currRoom_p == nullptr) return;
    currRoom_p->update();
}

void handle::room::draw() {
    if (currRoom_p == nullptr) return;
    currRoom_p->draw();
}

void handle::room::delRoom() {
    for (const auto& pair : universe) {
        std::cout << pair.second->getId() << " Room deleted. \n";
        delete pair.second;
    }
    universe.clear();
    currRoom_p = nullptr;
}
