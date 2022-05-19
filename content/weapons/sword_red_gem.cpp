#include "sword_red_gem.h"

#include "engine.h"
#include "hit.h"
#include "swing.h"

Sword_red_gem::Sword_red_gem(int damage) : Weapon{"sword_red_gem", damage} {}

void Sword_red_gem::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
    // engine.events.add(Hit{defender, damage});
}