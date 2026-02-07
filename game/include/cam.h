#pragma once
#include <raylib.h>

namespace cam {
    void begin();
    void end();
    
    void follow(Vector2 focus);
    void clampToDimension(Vector2 dim);

    void setOffset(Vector2 offset);
    void setZoom(float zoom);
    void setRotation(float rotation);

    bool recIsVisible(Rectangle rec);

}
