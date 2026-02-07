#include "rm/test1.h"
#include "globalprp.h"
#include "cam.h"
#include "global.h"

Test1::Test1() : 
            Room(TEST_1, global::DEFAULT_ROOM_SIZE) { 

    globalPlayer_p = dynamic_cast<Player*>(globalprp::getEnt_p("global_player")); 
    warper.setCollision({ 400, 400, 64, 64 });    

    wall.setPos({ 100, 90 });
    wall2.setPos({ 200, 200 });
    wall3.setPos({ 300, 300 });

    ents_p = { globalPlayer_p, &wall, &wall2, &wall3 };
}

void Test1::update() {
    cam::follow(globalPlayer_p->getPos());
    cam::clampToDimension(this->size);

    warper.warp(*globalPlayer_p, TEST_2, { 500, 500 });
    wall.update();
    wall2.update();
    wall3.update();

    globalPlayer_p->update();
    globalPlayer_p->interactsWith(ents_p);
}

void Test1::draw() {
    cam::begin();

    warper.draw();
    wall.draw();
    wall2.draw();
    wall3.draw();
    globalPlayer_p->draw();

    cam::end();
}

