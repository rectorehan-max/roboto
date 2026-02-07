#include "ent/wall.h"
#include "globalprp.h"
#include "global.h"
#include "fio.h"

Wall::Wall() : 
          Entity(WALL),
          idleWall(globalprp::getSpr_p("idleWall")),
          damWall(globalprp::getSpr_p("damWall")),
          desWall(globalprp::getSprsheet_p("desWall"), 
                  fio::in::loadGen_int("../res/ent/wall/info.txt", "deathanim"), 
                  NO_CYCLE),

          damageTimer(30) {
    
    Vector2 size = fio::in::loadGen_vec2("../res/ent/wall/info.txt", "size");
    collision = { 0, 0, size.x, size.y };

    this->setHealths(fio::in::loadGen_int("../res/ent/wall/info.txt", "health"));

    collidable = true;
    color = WHITE;

    idleWall.setOriginCenter();
    damWall.setOriginCenter();

    desWall.setOriginCenter();
}

void Wall::update() {
    if (damageTimer.isReady()) color = WHITE;
    else color = RED;

    idleWall.setPos({ global::getCenter(this->collision) });
    damWall.setPos({ global::getCenter(this->collision) });

    desWall.setPos({ global::getCenter(this->collision) });
    if (!this->isAlive()) desWall.update();

    damageTimer.update();
}

void Wall::drawAction() {
    if (!this->isAlive()) {
        if (!desWall.atLastFrame()) desWall.draw(color);
    } else if (health < maxHealth) {
        damWall.draw(color);
    } else {
        idleWall.draw(color);
    }
}

void Wall::damageHealth(int damage) {
    if (!this->isAlive()) return;

    damageTimer.run([this, damage] () {
        if (health <= 0) return;
        health -= damage;
    });
}
