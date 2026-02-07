#pragma once
#include "ent/entity.h"

class Attribute {

public:
    virtual ~Attribute() = default;

protected:
    Attribute(Entity& user);
    Entity& user;

};
