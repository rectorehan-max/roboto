#include "cam.h"
#include "global.h"
#include <raymath.h>

namespace cam {
    Camera2D camera = { 0 };
}

void cam::begin() {
    BeginMode2D(camera);
}

void cam::end() {
    EndMode2D();
}

void cam::follow(Vector2 focus) {
    camera.target = focus;
}

void cam::clampToDimension(Vector2 dim) {
    float halfWidth = camera.offset.x / camera.zoom;
    float halfHeight = camera.offset.y / camera.zoom;

    camera.target.x = Clamp(camera.target.x, halfWidth, dim.x - halfWidth);
    camera.target.y = Clamp(camera.target.y, halfHeight, dim.y - halfHeight);
}

void cam::setOffset(Vector2 offset) {
    camera.offset = offset;
}

void cam::setRotation(float rotation) {
    camera.rotation = rotation;
}

void cam::setZoom(float zoom) {
    camera.zoom = zoom;
}

bool cam::recIsVisible(Rectangle rec) {
    Vector2 pos = { rec.x, rec.y };

    return !(GetWorldToScreen2D(pos, camera).x > global::SCREEN_WIDTH || 
    (GetWorldToScreen2D(pos, cam::camera).x + rec.width < 0) ||          
    GetWorldToScreen2D(pos, camera).y > global::SCREEN_HEIGHT ||
    (GetWorldToScreen2D(pos, cam::camera).y + rec.height < 0));
}
