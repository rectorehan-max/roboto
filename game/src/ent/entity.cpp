#include "ent/entity.h"
#include "global.h"
#include <iostream>
#include "cam.h"

uint32_t numOfInstance = 0;

Entity::Entity(EntityName name) : 
              name(name), 
              id(numOfInstance) {

    numOfInstance++;
   
    maxHealth = 0;
    health = 0;
    collision = { 0 };

    printId();
}

void Entity::update() {}
void Entity::drawAction() {}

void Entity::draw() {
    if (!cam::recIsVisible(this->collision)) return;
    drawAction();
}

void Entity::drawCollision(Color color) {
    DrawRectangleRec(collision, color);
}

void Entity::setHealths(int val) {
    this->maxHealth = val;
    this->health = val;
}

void Entity::setPos(Vector2 pos) {
    this->collision.x = pos.x;
    this->collision.y = pos.y;
}

void Entity::setHealth(int health) {
    this->health = health;
}

void Entity::damageHealth(int damage) {
    this->health -= damage;
}

bool Entity::isAlive() {
    return health > 0;
}

bool Entity::isCollidable() {
    return collidable;
}

Rectangle Entity::getCollision() {
    return collision;
}

Rectangle* Entity::getCollision_p() {
    return &collision;
}

Vector2 Entity::getPos() {
    return { this->collision.x, this->collision.y };
}

uint32_t Entity::getId() {
    return id;
}

int Entity::getHealth() {
    return health;
}

void Entity::printId() {
    std::cout << "Entity: " << id << std::endl;
}

