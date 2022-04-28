#include "move.h"

#include <iostream>
#include <memory>

#include "actor.h"
#include "engine.h"
#include "hero.h"

// move constructor
Move::Move(const Vec& direction) : direction{direction} {};

Result Move::perform(Engine& engine) {
    Vec pos = actor->get_position() + direction;
    Tile& tile = engine.dungeon.tiles(pos);
    actor->change_direction(direction);
    if (tile.is_wall() || tile.actor) {
        std::cout << "cant go there" << std::flush;
        return failure();
    } else if (tile.is_door()) {
        std::cout << "it is locked" << std::flush;
        return failure();
    } else {
        std::cout << "move there" << std::flush;
        actor->move_to(pos);
        return success();
    }
};