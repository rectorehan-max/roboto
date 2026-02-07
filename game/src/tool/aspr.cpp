#include "tool/aspr.h"
#include "global.h"

#include <iostream>

AnimatedSprite::AnimatedSprite(SpriteSheet* sprsheet_p, int animspeed, AnimationMode mode) : 
                              sprsheet_p(sprsheet_p),
                              timer(animspeed),
                              mode(mode) {
    init();
}


AnimatedSprite::AnimatedSprite(SpriteSheet* sprsheet_p, AnimationMode mode) : 
                              sprsheet_p(sprsheet_p),
                              mode(mode) {
    init();              
}

void AnimatedSprite::init() {
    sprsheet_p->requestToLoad();
    sprsheet_p->addUserTally();

    origin = { 0, 0 };
    dest = { 0, 0, (float)(sprsheet_p->frameWidth), (float)(sprsheet_p->frameHeight) };
    source = { 0, 0, (float)sprsheet_p->frameWidth, (float)sprsheet_p->frameHeight };
    rotation = 0.0f;
    finished = false;
    sheetFrame = 0;

    sprsheet_p->smartLoad();
}

void AnimatedSprite::animateActionCycle() {
    sheetFrame++;

    if (sheetFrame >= sprsheet_p->maxFrames) sheetFrame = 0;

    int col = sheetFrame % sprsheet_p->numCols;
    int row = sheetFrame / sprsheet_p->numCols;

    source = {
        (float)(col * sprsheet_p->frameWidth),
        (float)(row * sprsheet_p->frameHeight),
        (float)sprsheet_p->frameWidth,
        (float)sprsheet_p->frameHeight
    };
}


void AnimatedSprite::animateActionNoCycle() {
    if (!finished) sheetFrame++;

    if (sheetFrame >= sprsheet_p->maxFrames) {
        finished = true;
        return;
    }

    int col = sheetFrame % sprsheet_p->numCols;
    int row = sheetFrame / sprsheet_p->numCols;

    source = {
        (float)(col * sprsheet_p->frameWidth),
        (float)(row * sprsheet_p->frameHeight), 
        (float)(sprsheet_p->frameWidth),
        (float)(sprsheet_p->frameHeight)
    };
}

void AnimatedSprite::update() {
    timer.go();
    switch (mode) {
        case CYCLE: 
            timer.run([this] () { this->animateActionCycle(); }); 
            break;
            
        case NO_CYCLE:
            timer.run([this] () { this->animateActionNoCycle(); });
            break;

        default: 
            break;
    }
}

void AnimatedSprite::update(int animSpeed) {
    timer.setFramePerSecond(animSpeed);
    timer.go();
    switch (mode) {
        case CYCLE: 
            timer.run([this] () { this->animateActionCycle(); }); 
            break;
            
        case NO_CYCLE:
            timer.run([this] () { this->animateActionNoCycle(); });
            break;

        default: 
            break;
    }
}

void AnimatedSprite::draw(Color color) {
    DrawTexturePro(sprsheet_p->texture, source, dest, origin, rotation, color);
}

void AnimatedSprite::setOrigin(Vector2 origin) {
    this->origin = origin;
}

void AnimatedSprite::setOriginCenter() {
    this->origin = global::getCenter({ 0.0f, 0.0f, 
                                    (float)sprsheet_p->frameWidth, 
                                    (float)sprsheet_p->frameHeight });
}
void AnimatedSprite::setPos(Vector2 pos) {
    dest = { pos.x, pos.y, (float)(sprsheet_p->frameWidth), (float)(sprsheet_p->frameHeight) };
}

void AnimatedSprite::setRotation(float rotation) {
    this->rotation = rotation;
}

bool AnimatedSprite::atLastFrame() {
    return sheetFrame == sprsheet_p->maxFrames;
}

bool AnimatedSprite::atFirstFrame() {
    return sheetFrame == 0;
}

bool AnimatedSprite::atFrame(int frameNum) {
    if (frameNum > sprsheet_p->maxFrames || frameNum < 0) return false;

    return frameNum == sheetFrame;
}

int AnimatedSprite::getCurrFrame() {
    return sheetFrame;
}

AnimatedSprite::~AnimatedSprite() {
    sprsheet_p->removeUserTally();
    sprsheet_p->smartUnload();
}

