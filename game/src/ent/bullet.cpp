#include "ent/bullet.h"
#include <raymath.h>

#include <iostream>

Bullet::Bullet() : 
              Entity(BULLET) {

    speed = 0.0f;
    direction = { 0.0f, 0.0f };
    collision = { 0.0f, 0.0f, 0.0f, 0.0f };

}

Bullet::Bullet(Vector2 size, float speed) :
               Entity(BULLET) {

    this->speed = speed;
    direction = { 0.0f, 0.0f };
    collision = { 0.0f, 0.0f, size.x, size.y };
}

void Bullet::update() {
    if (!this->isAlive()) return;

    collision.x += direction.x * speed;
    collision.y += direction.y * speed;
}

void Bullet::drawAction() {
    drawCollision(RED);
}

void Bullet::fire(Vector2 direction) {
    if (Vector2Length(direction) < 0.001f) return;

    this->direction = Vector2Normalize(direction);

    health = 1;
}

void Bullet::reset(Vector2 pos) {
    this->setPos(pos);
    direction = { 0, 0 };
    health = 0;
}

bool Bullet::hasHit(Rectangle* rec_p) {
    return CheckCollisionRecs(this->collision, *rec_p);
}

bool Bullet::hasHit(Entity* ent_p) {
    return CheckCollisionRecs(this->collision, ent_p->getCollision());
}

void Bullet::setSpeed(float speed) {
    this->speed = speed;
}

void Bullet::setSize(Vector2 size) {
    this->collision.width = size.x;
    this->collision.height = size.y;
}
