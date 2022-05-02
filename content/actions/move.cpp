#include "move.h"

#include <iostream>
#include <memory>

#include "actor.h"
#include "door.h"
#include "engine.h"
#include "hero.h"
#include "opendoor.h"

// move constructor
Move::Move(const Vec& direction) : direction{direction} {};

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position() + direction;
    Tile& tile = engine.dungeon.tiles(position);
    actor->change_direction(direction);
    if (tile.is_wall()) {
        // std::cout << "cant go there" << std::flush;
        return failure();
    } else if (tile.actor) {
        return failure();  // alternative(Attack{*tile.actor})
        //                                      Actor& actor
        //                                      actor.attack(defender);
    }

    else if (tile.is_door()) {
        Door& door = engine.dungeon.doors.at(position);
        if (door.is_open()) {
            actor->move_to(position);
            return success();
        } else {
            return alternative(Opendoor{position});
                }
        return success();
    } else {
        // std::cout << "move there" << std::flush;
        actor->move_to(position);
        return success();
    }
};

// Move::Move(const Vec& direction) : direction{direction} {};

// Result Move::perform(Engine& engine) {
//     Vec position = actor->get_position() + direction;
//     Tile& tile = engine.dungeon.tiles(position);
//     actor->change_direction(direction);
//     if (tile.is_wall() || tile.actor) {
//        // std::cout << "cant go there" << std::flush;
//         return failure();
//     } else if (tile.is_door()) {
//         Door& door = engine.dungeon.doors.at(position);
//         if (door.is_open()) {
//             actor->move_to(position);
//         } else {
//             door.open();
//             tile.walkable = true;
//         }
//         return success();
//     } else {
//        // std::cout << "move there" << std::flush;
//         actor->move_to(position);
//         return success();
//     }
// };