#pragma once
#include "attr/attribute.h"
#include <vector>

class PushoutCollision : public Attribute {

public:
    PushoutCollision(Entity& user, Vector2& vel);

    void collideWithRec_p(Rectangle* rec_p);
    void collideWithEnt_p(Entity* ent_p);

    void collideWithRecs_p(std::vector<Rectangle*> recs_p);
    void collideWithEnts_p(std::vector<Entity*> ents_p);

private:
    Vector2& vel;

    void stopUser(Rectangle& a, Rectangle& b);

};
