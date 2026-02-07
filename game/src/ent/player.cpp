#include "ent/player.h"
#include "globalprp.h"
#include "global.h"
#include "fio.h"
#include <cmath>

#include <iostream>

Player::Player() : 
              Entity(PLAYER),
              maxSpeed(fio::in::loadGen_flt("../res/ent/player/info.txt", "speed")),
              acc(fio::in::loadGen_flt("../res/ent/player/info.txt", "acc")),
              fric(fio::in::loadGen_flt("../res/ent/player/info.txt", "fric")),
              pushcol(*this, vel),

              idlePlayer_down(globalprp::getSpr_p("idlePlayer_down")),
              idlePlayer_left(globalprp::getSpr_p("idlePlayer_left")),
              idlePlayer_leftDown(globalprp::getSpr_p("idlePlayer_leftDown")),
              idlePlayer_right(globalprp::getSpr_p("idlePlayer_right")),
              idlePlayer_rightDown(globalprp::getSpr_p("idlePlayer_rightDown")),
              idlePlayer_up(globalprp::getSpr_p("idlePlayer_up")), 
              idlePlayer_upLeft(globalprp::getSpr_p("idlePlayer_upLeft")),
              idlePlayer_upRight(globalprp::getSpr_p("idlePlayer_upRight")),

              playerRun_down(globalprp::getSprsheet_p("playerRun_down"), 10, CYCLE),
              playerRun_downRight(globalprp::getSprsheet_p("playerRun_downRight"), 8, CYCLE),
              playerRun_downLeft(globalprp::getSprsheet_p("playerRun_downLeft"), 8, CYCLE),
              playerRun_right(globalprp::getSprsheet_p("playerRun_right"), 8, CYCLE),
              playerRun_left(globalprp::getSprsheet_p("playerRun_left"), 8, CYCLE),
              playerRun_upRight(globalprp::getSprsheet_p("playerRun_upRight"), 8, CYCLE),
              playerRun_upLeft(globalprp::getSprsheet_p("playerRun_upLeft"), 8, CYCLE), 
              playerRun_up(globalprp::getSprsheet_p("playerRun_up"), 10, CYCLE),

              bullet({ 10, 10 }, 4.5f) {

    Vector2 size = fio::in::loadGen_vec2("../res/ent/player/info.txt", "size");
    collision = { 0, 0, size.x, size.y};
    this->setHealths(fio::in::loadGen_int("../res/ent/player/info.txt", "health"));
    collidable = fio::in::loadGen_bool("../res/ent/player/info.txt", "collidable");

    idlePlayer_down.setOriginCenter();
    idlePlayer_left.setOriginCenter();
    idlePlayer_leftDown.setOriginCenter();
    idlePlayer_right.setOriginCenter();
    idlePlayer_rightDown.setOriginCenter();
    idlePlayer_up.setOriginCenter();
    idlePlayer_upLeft.setOriginCenter();
    idlePlayer_upRight.setOriginCenter();

    playerRun_down.setOriginCenter();
    playerRun_downRight.setOriginCenter();
    playerRun_downLeft.setOriginCenter();
    playerRun_right.setOriginCenter();
    playerRun_left.setOriginCenter();
    playerRun_upRight.setOriginCenter();
    playerRun_upLeft.setOriginCenter();
    playerRun_up.setOriginCenter();
}

void Player::move() {
    if (IsKeyDown(KEY_W)) vel.y -= acc;
    if (IsKeyDown(KEY_A)) vel.x -= acc;
    if (IsKeyDown(KEY_S)) vel.y += acc;
    if (IsKeyDown(KEY_D)) vel.x += acc;

    
    if (!IsKeyDown(KEY_A) && !IsKeyDown(KEY_D)) vel.x *= (1.0f - fric);
    if (!IsKeyDown(KEY_W) && !IsKeyDown(KEY_S)) vel.y *= (1.0f - fric);

    float length = sqrtf(vel.x * vel.x + vel.y * vel.y);
    if (length > maxSpeed) {
        vel.x = (vel.x / length) * maxSpeed;
        vel.y = (vel.y / length) * maxSpeed;
    }

    collision.x += vel.x;
    collision.y += vel.y;

}

void Player::interactsWith(Rectangle* rec_p) {
    pushcol.collideWithRec_p(rec_p);
}

void Player::interactsWith(Entity* ent_p) {
    pushcol.collideWithEnt_p(ent_p);
}

void Player::interactsWith(std::vector<Rectangle*> recs_p) {
    pushcol.collideWithRecs_p(recs_p);
}
void Player::interactsWith(std::vector<Entity*> ents_p) {
    pushcol.collideWithEnts_p(ents_p);

    for (Entity*& ent_p : ents_p) {
        if (ent_p->getId() == this->id) continue;
        if (!ent_p->isAlive()) continue;
        if (bullet.hasHit(ent_p)) {
            ent_p->damageHealth(1);
            bullet.reset(this->getPos());
        }
    }
}

void Player::update() {
    move();
    updateSprites();
    shootSys();
}

void Player::drawAction() {
    drawCollision(RED);
    drawSprites();
    if (bullet.isAlive()) bullet.draw();
}

void Player::shootSys() {
    if (!bullet.isAlive()) bullet.setPos(this->getPos());
    if (IsKeyPressed(KEY_ENTER)) bullet.fire({ 1, 0 });
    if (IsKeyPressed(KEY_R)) bullet.reset(this->getPos());

    bullet.update();
}

// ALL ABOUT SPRITES

void Player::updateSprites() {
    playerRun_down.update();
    playerRun_downRight.update();
    playerRun_downLeft.update();
    playerRun_right.update();
    playerRun_left.update();
    playerRun_upRight.update();
    playerRun_upLeft.update();
    playerRun_up.update();

    idlePlayer_down.setPos({ global::getCenter(this->collision) });
    idlePlayer_left.setPos({ global::getCenter(this->collision) });
    idlePlayer_leftDown.setPos({ global::getCenter(this->collision) });
    idlePlayer_right.setPos({ global::getCenter(this->collision) });
    idlePlayer_rightDown.setPos({ global::getCenter(this->collision) });
    idlePlayer_up.setPos({ global::getCenter(this->collision) });
    idlePlayer_upLeft.setPos({ global::getCenter(this->collision) });
    idlePlayer_upRight.setPos({ global::getCenter(this->collision) });

    playerRun_down.setPos({ global::getCenter(this->collision) });
    playerRun_downRight.setPos({ global::getCenter(this->collision) });
    playerRun_downLeft.setPos({ global::getCenter(this->collision) });
    playerRun_right.setPos({ global::getCenter(this->collision) });
    playerRun_left.setPos({ global::getCenter(this->collision) });
    playerRun_upRight.setPos({ global::getCenter(this->collision) });
    playerRun_upLeft.setPos({ global::getCenter(this->collision) });
    playerRun_up.setPos({ global::getCenter(this->collision) });
}

void Player::drawSprites() {

    if (IsKeyDown(KEY_S) && IsKeyDown(KEY_D)) detDir(false, true, false, true);
    else if (IsKeyDown(KEY_S) && IsKeyDown(KEY_A)) detDir(false, true, true, false);
    else if (IsKeyDown(KEY_W) && IsKeyDown(KEY_D)) detDir(true, false, false, true);
    else if (IsKeyDown(KEY_W) && IsKeyDown(KEY_A)) detDir(true, false, true, false);
    else if (IsKeyDown(KEY_W)) detDir(true, false, false, false);
    else if (IsKeyDown(KEY_S)) detDir(false, true, false, false);
    else if (IsKeyDown(KEY_D)) detDir(false, false, false, true);
    else if (IsKeyDown(KEY_A)) detDir(false, false, true, false);
    
    if (!this->isMoving()) {
        if (down && right) idlePlayer_rightDown.draw(WHITE);
        else if (down && left) idlePlayer_leftDown.draw(WHITE);
        else if (up && right) idlePlayer_upRight.draw(WHITE);
        else if (up && left) idlePlayer_upLeft.draw(WHITE);
        else if (down) idlePlayer_down.draw(WHITE);
        else if (up) idlePlayer_up.draw(WHITE);
        else if (right) idlePlayer_right.draw(WHITE);
        else if (left) idlePlayer_left.draw(WHITE);
        else idlePlayer_down.draw(WHITE);
    } else {
        if (down && right) playerRun_downRight.draw(WHITE);
        else if (down && left) playerRun_downLeft.draw(WHITE);
        else if (up && right) playerRun_upRight.draw(WHITE);
        else if (up && left) playerRun_upLeft.draw(WHITE);
        else if (down) playerRun_down.draw(WHITE);
        else if (up) playerRun_up.draw(WHITE);
        else if (right) playerRun_right.draw(WHITE);
        else if (left) playerRun_left.draw(WHITE);
    }

}

void Player::detDir(bool up, bool down, bool left, bool right) {
    this->up = up;
    this->down = down;
    this->left = left;
    this->right = right;
}

bool Player::isMoving() {
    return vel.x != 0 || vel.y != 0;
}
