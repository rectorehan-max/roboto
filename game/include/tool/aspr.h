#pragma once
#include "tool/spritesheet.h"
#include "tool/intervaltimer.h"

enum AnimationMode {
    CYCLE, NO_CYCLE
};

class AnimatedSprite {

public:
    AnimatedSprite(SpriteSheet* sprsheet_p, int animspeed, AnimationMode mode);
    AnimatedSprite(SpriteSheet* sprsheet_p, AnimationMode mode);

    void update();
    void update(int animSpeed);
    void draw(Color color);

    void setOrigin(Vector2 origin);
    void setOriginCenter();
    void setPos(Vector2 pos);
    void setRotation(float rotation);

    bool atLastFrame();
    bool atFirstFrame();
    bool atFrame(int frameNum);
    int getCurrFrame();

    ~AnimatedSprite();

private:
    SpriteSheet* sprsheet_p;
    AnimationMode mode;
    IntervalTimer timer;

    Rectangle dest;
    Rectangle source;
    Vector2 origin;
    float rotation;

    int sheetFrame;
    bool finished;

    void animateActionCycle();
    void animateActionNoCycle();

    void init();
};
