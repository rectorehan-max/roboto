#pragma once
#include "ent/entity.h"

class Bullet : public Entity {

public:

    Bullet();
    Bullet(Vector2 size, float speed);

    void drawAction() override;
    void update() override;

    void fire(Vector2 direction); 
    void reset(Vector2 pos);
    bool hasHit(Rectangle* rec_p);
    bool hasHit(Entity* ent_p);

    void setSpeed(float speed);
    void setSize(Vector2 size);

private:
    float speed;
    Vector2 direction;
};
