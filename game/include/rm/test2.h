#pragma once
#include "rm/room.h"
#include "ent/player.h"
#include "ent/wall.h"
#include "tool/warper.h"
#include "tile/coltile.h"
#include <vector>

class Player;

class Test2 : public Room {

public:
    Test2();
    void update() override;
    void draw() override;

private:
    Player* globalPlayer_p;
    Wall wall;
    Wall wall2;
    Wall wall3;
    Wall wall4;

    Warper warper;

    CollisionTileset coltile;

    std::vector<Entity*> ents_p;
};
