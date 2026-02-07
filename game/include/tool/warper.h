#pragma once
#include <raylib.h>
#include "ent/player.h"
#include "rm/room.h"

class Warper {
private:
    Rectangle collision;

public:
    Warper();
    void setCollision(Rectangle collision);
    void warp(Player& player, RoomName toRoom);
    void warp(Player& player, RoomName toRoom, Vector2 toCoords);
    void draw();

};
