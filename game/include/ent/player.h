#pragma once
#include "ent/entity.h"
#include "tool/sspr.h"
#include "tool/aspr.h"
#include "attr/pushout.h"
#include "ent/bullet.h"

#include <vector>

class Player : public Entity {

public:
    Player();

    void update() override;
    void drawAction() override;

    void interactsWith(Rectangle* rec_p);
    void interactsWith(Entity* ent_p);

    void interactsWith(std::vector<Rectangle*> recs_p);
    void interactsWith(std::vector<Entity*> ents_p);

private:
    const float maxSpeed;
    const float acc;
    const float fric;

    Vector2 vel;

    SingleSprite idlePlayer_down;
    SingleSprite idlePlayer_left;
    SingleSprite idlePlayer_leftDown;
    SingleSprite idlePlayer_right;
    SingleSprite idlePlayer_rightDown;
    SingleSprite idlePlayer_up;
    SingleSprite idlePlayer_upLeft;
    SingleSprite idlePlayer_upRight;

    AnimatedSprite playerRun_down;
    AnimatedSprite playerRun_downRight; 
    AnimatedSprite playerRun_downLeft;
    AnimatedSprite playerRun_right;
    AnimatedSprite playerRun_left;
    AnimatedSprite playerRun_upRight;
    AnimatedSprite playerRun_upLeft;
    AnimatedSprite playerRun_up;

    PushoutCollision pushcol;

    Bullet bullet; 

    bool up;
    bool down;
    bool left;
    bool right;

    void move();
    bool isMoving();

    void detDir(bool up, bool down, bool left, bool right);
    void updateSprites();
    void drawSprites();

    void shootSys();
};
