#include <stdexcept>
#include "handler.h"

#include "rm/test1.h"
#include "rm/test2.h"

void handle::room::addRoom() {
    switch (currRoom) {
        case TEST_1: 
            universe.try_emplace(TEST_1, new Test1());
            break;
        
        case TEST_2:
            universe.try_emplace(TEST_2, new Test2());
            break;

        default:
            throw std::runtime_error("Room name not found or added.");
    } 
}
