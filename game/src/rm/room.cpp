#include "rm/room.h"

Room::Room(RoomName id, Vector2 size) : 
          id(id), size(size) {}

void Room::update() {}
void Room::draw() {}

void Room::nextReset() {}
void Room::prevReset() {}

RoomName Room::getId() {
    return id;
}
