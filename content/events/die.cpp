#include "die.h"

Die::Die(Actor& actor) : actor{actor} {}

void Die::execute(Engine& engine) {
    // tile.actor = nullptr;
    // remove actor from its tile
    engine.dungeon.remove_actor(actor.get_position());

    // remove it from live actors
    actor.health = 0;
    actor.alive = false;
}