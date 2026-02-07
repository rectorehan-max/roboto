#include "tool/sspr.h"
#include "global.h"
 
SingleSprite::SingleSprite(Sprite* spr_p) : spr_p(spr_p) {

    spr_p->requestToLoad();
    spr_p->addUserTally();

    dest = { 0 };
    origin = { 0 };
    rotation = 0.0f;

    spr_p->smartLoad();
}

void SingleSprite::draw(Color color) {
    DrawTexturePro(spr_p->texture, {
                  0.0f, 0.0f, (float)spr_p->width, (float)spr_p->height },
                  dest, origin, rotation, color);
}

void SingleSprite::setOrigin(Vector2 origin) {
    this->origin = origin;
}

void SingleSprite::setOriginCenter() {
    this->origin = global::getCenter({ 0.0f, 0.0f, 
                                    (float)spr_p->width, 
                                    (float)spr_p->height });
}

void SingleSprite::setPos(Vector2 pos) {
    dest = { pos.x, pos.y, (float)spr_p->width, (float)spr_p->height };
}

void SingleSprite::setRotation(float rotation) {
    this->rotation = rotation;
}

SingleSprite::~SingleSprite() {
    spr_p->removeUserTally();
    spr_p->smartUnload();
}
