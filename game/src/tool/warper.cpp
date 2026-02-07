#include "tool/warper.h"
#include "handler.h"

Warper::Warper() {
    collision = { 0 };
}

void Warper::setCollision(Rectangle collision) {
    this->collision = collision;
}

void Warper::warp(Player& player, RoomName toRoom) {
    if (CheckCollisionRecs(player.getCollision(), this->collision)) {
        handle::room::changeRoom(toRoom);
    }
}

void Warper::warp(Player& player, RoomName toRoom, Vector2 toCoords) {
    if (CheckCollisionRecs(player.getCollision(), this->collision)) {
       handle::room::changeRoom(toRoom);
       player.setPos(toCoords);
    }
}
void Warper::draw() {
    DrawRectangleRec(collision, MAGENTA);
}
