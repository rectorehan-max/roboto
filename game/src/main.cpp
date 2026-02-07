#include <raylib.h>
#include "global.h"
#include "handler.h"
#include "globalprp.h"
#include "cam.h"

int main() {
    InitWindow(global::SCREEN_WIDTH, global::SCREEN_HEIGHT, "Raylib Project Template_2");
    SetTargetFPS(60);

    globalprp::createProps();
    cam::setOffset(global::CAMERA_CENTER);
    cam::setRotation(0.0f);
    cam::setZoom(1.0f);   
    
    while (!WindowShouldClose()) {
        // update here
  
        handle::room::roomSwitch();
        handle::room::roomResets();
        handle::room::update();

        BeginDrawing();
        // draw here
        
        ClearBackground(BLACK);
        handle::room::draw();

        EndDrawing();
    }

    globalprp::deleteProps();
    handle::room::delRoom();

    CloseWindow();

    return 0;
}
