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
        std::cout << "cant go there, that is wall \n" << std::flush;
        return failure();
    } else if (tile.actor) {
        std::cout << "tag you are it \n" << std::flush;
        return success();  // alternative(Attack{*tile.actor})
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
    } else {
        std::cout << "move there \n" << std::flush;
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