#pragma once
#include "tool/sprite.h"

class SingleSprite {

private:
    Sprite* spr_p;

    Rectangle dest;
    Vector2 origin;
    float rotation;

public:
    SingleSprite(Sprite* spr_p); 
    
    void draw(Color color);

    void setOrigin(Vector2 origin);
    void setOriginCenter();
    void setPos(Vector2 pos);
    void setRotation(float rotation);

    ~SingleSprite();
};
