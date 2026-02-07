#pragma once
#include <raylib.h>
#include <cstdint>

enum EntityName {
    PLAYER,
    WALL,
    BULLET,
};

class Entity {
    
protected:
    Entity(EntityName name);

    EntityName name;
    
    uint32_t id;

    Rectangle collision;
    int health;
    int maxHealth;
    bool collidable;

    void drawCollision(Color color);
    void printId();
    void setHealths(int val);

public:
    virtual void update();
    virtual void drawAction();
    virtual void draw();

    virtual void setPos(Vector2 pos);
    virtual void setHealth(int health);
    virtual void damageHealth(int damage);

    bool isAlive();
    bool isCollidable();

    Rectangle getCollision();
    Rectangle* getCollision_p();
    Vector2 getPos();
    int getHealth();

    uint32_t getId();

    virtual ~Entity() = default;

};

