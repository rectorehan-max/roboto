#pragma once
#include "ent/entity.h"
#include "tool/sspr.h"
#include "tool/aspr.h"
#include "tool/cooldown.h"

class Wall : public Entity {

public:
    Wall();

    void drawAction() override;
    void update() override;

    void damageHealth(int damage) override;


private:
    Color color;

    SingleSprite idleWall;
    SingleSprite damWall;
    AnimatedSprite desWall;

    CooldownTimer damageTimer;
};
