#include "globalprp.h"
#include "ent/player.h"

void addToEntMap(std::string name, Entity* ent_p) {
    globalprp::entMap.try_emplace(name, ent_p);
}

void globalprp::ent::add() {
    static Player player;
    addToEntMap("global_player", &player);
}

