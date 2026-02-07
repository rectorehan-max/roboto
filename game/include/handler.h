#pragma once
#include "rm/room.h"
#include <unordered_map>

namespace handle {
    namespace room {
        extern std::unordered_map<RoomName, Room*> universe;
        extern RoomName currRoom;

        void changeRoom(RoomName toRoom);

        void roomSwitch();
        void roomResets();
        void update();
        void draw();

        void addRoom();
        void delRoom();
    }
}
