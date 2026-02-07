#pragma once
#include "rm/room.h"
#include "ent/player.h"
#include "tool/warper.h"
#include "ent/wall.h"

#include <vector>

class Player;

class Test1 : public Room {
    
public:
    Test1();
    void draw() override;
    void update() override;

private:
    Player* globalPlayer_p;
    Warper warper;
    Wall wall;
    Wall wall2;
    Wall wall3;

    std::vector<Entity*> ents_p;
};

