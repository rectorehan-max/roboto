#include "attr/pushout.h"
#include "cam.h"

PushoutCollision::PushoutCollision(Entity& user, Vector2& vel) :
                                  Attribute(user),
                                  vel(vel) {}

void PushoutCollision::stopUser(Rectangle& a, Rectangle& b) {
    float overlapX = std::min(a.x + a.width, b.x + b.width) - std::max(a.x, b.x);
    float overlapY = std::min(a.y + a.height, b.y + b.height) - std::max(a.y, b.y);

    if (overlapX < overlapY) {
        if (a.x < b.x) user.getCollision_p()->x -= overlapX;
        else user.getCollision_p()->x += overlapX;
        vel.x = 0;
    } else {
        if (a.y < b.y) user.getCollision_p()->y -= overlapY;
        else user.getCollision_p()->y += overlapY;
        vel.y = 0;
    }
}

void PushoutCollision::collideWithRec_p(Rectangle* rec_p) {
    if (!cam::recIsVisible(*rec_p)) return;

    if (CheckCollisionRecs(user.getCollision(), *rec_p)) {

        Rectangle a = *user.getCollision_p();
        Rectangle b = *rec_p;

        stopUser(a, b);

    }
}

void PushoutCollision::collideWithEnt_p(Entity* ent_p) {
    if (!ent_p->isAlive() || !cam::recIsVisible(ent_p->getCollision()) || 
       !ent_p->isCollidable()) return;

    if (CheckCollisionRecs(user.getCollision(), ent_p->getCollision())) {
        Rectangle a = *user.getCollision_p();
        Rectangle b = *ent_p->getCollision_p();

        stopUser(a, b);
    }
}

void PushoutCollision::collideWithRecs_p(std::vector<Rectangle*> recs_p) {
    for (Rectangle*& rec_p : recs_p) {
        if (!cam::recIsVisible(*rec_p)) continue;

        if (CheckCollisionRecs(user.getCollision(), *rec_p)) {

            Rectangle a = user.getCollision();
            Rectangle b = *rec_p;

            stopUser(a, b);
        }
    }
}

void PushoutCollision::collideWithEnts_p(std::vector<Entity*> ents_p) {
    for (Entity*& ent_p : ents_p) {
        if (user.getId() == ent_p->getId() || !ent_p->isAlive() ||
            !ent_p->isCollidable() || !cam::recIsVisible(ent_p->getCollision())) continue;

        if (CheckCollisionRecs(user.getCollision(), ent_p->getCollision())) {
            Rectangle a = *user.getCollision_p();
            Rectangle b = *ent_p->getCollision_p();

            stopUser(a, b);
        }
    }
}
