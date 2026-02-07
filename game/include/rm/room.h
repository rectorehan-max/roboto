#pragma once
#include <raylib.h>

enum RoomName {
    NONE,
    TEST_1, TEST_2
};

class Room {

protected:
    Room(RoomName id, Vector2 size);

    RoomName id;
    Vector2 size;

public:
    virtual void update();
    virtual void draw();

    virtual void nextReset();
    virtual void prevReset();

    virtual ~Room() = default;

    RoomName getId();

};
