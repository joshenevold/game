#include "closedoor.h"

#include <iomanip>
#include <iostream>

#include "engine.h"
#include "updatefov.h"

Result CloseDoor::perform(Engine& engine) {
    bool close_any_doors{false};
    std::vector<Vec> neighbors =
        engine.dungeon.neighbors(actor->get_position());
    for (const Vec& position : neighbors) {
        Tile& tile = engine.dungeon.tiles(position);
        // std::cout << position << " " << tile.is_door() << '\n';
        if (tile.is_door()) {
            Door& door = engine.dungeon.doors.at(position);
            if (door.is_open()) {
                door.close();
                engine.events.add(UpdateFOV{});
                tile.walkable = false;
                close_any_doors = true;
            }
        }
    }
    if (close_any_doors) {
        return success();
    } else {
        return failure();
    }
}
