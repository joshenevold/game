#include "opendoor.h"

#include "updatefov.h"

// move constructor
Opendoor::Opendoor(const Vec& position) : position{position} {};

Result Opendoor::perform(Engine& engine) {
    Door& door = engine.dungeon.doors.at(position);
    Tile& tile = engine.dungeon.tiles(position);
    door.open();
    engine.events.add(UpdateFOV{});
    tile.walkable = true;
    return success();
}