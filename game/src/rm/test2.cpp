#include "rm/test2.h"
#include "globalprp.h"
#include "global.h"
#include "cam.h"

Test2::Test2() :
            Room(TEST_2, global::DEFAULT_ROOM_SIZE),
            coltile(global::DEFAULT_TILESET_SIZE, 
                    global::DEFAULT_RECTANGLE_SIZE, "../res/rm/test2/coltile.txt") {

    globalPlayer_p = dynamic_cast<Player*>(globalprp::getEnt_p("global_player"));
    warper.setCollision({ 100, 100, 64, 64 });

    wall.setPos({ 400, 400 });
    wall2.setPos({ 400, 464 });
    wall3.setPos({ 400, 464 + 64 });
    wall4.setPos({ 400, 464 + 64 + 64 });

    ents_p = { &wall, &wall2, &wall3, &wall4 };
}


void Test2::update() {
    warper.warp(*globalPlayer_p, TEST_1, { 800, 800 });
    wall.update();
    wall2.update();
    wall3.update();
    wall4.update();

    globalPlayer_p->update();
    globalPlayer_p->interactsWith(coltile.getRecs_p());
    globalPlayer_p->interactsWith(ents_p);

}

void Test2::draw() {
    cam::follow(globalPlayer_p->getPos());
    cam::begin();

    warper.draw();
    wall.draw();
    wall2.draw();
    wall3.draw();
    wall4.draw();

    coltile.draw();
    globalPlayer_p->draw();

    cam::end();
}

