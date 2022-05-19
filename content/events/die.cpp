#include "die.h"

#include "iostream"
#include "spawn_monster.h"

Die::Die(Actor& actor) : actor{actor} {}

void Die::execute(Engine& engine) {
    // tile.actor = nullptr;
    // remove actor from its tile
    engine.dungeon.remove_actor(actor.get_position());

    // remove it from live actors
    actor.health = 0;
    actor.alive = false;

    // calls spawn monster so everytime one dies two new ones are spawned
    engine.events.add(Spawn_monster{});
    // added tallies really quickly so my frieds could see who was better at the
    // game
    std::cout << "I" << std::flush;
}