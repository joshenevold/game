#include "sword_rusty.h"

#include "engine.h"
#include "hit.h"
#include "swing.h"

Sword_rusty::Sword_rusty(int damage) : Weapon{"sword_rusty", damage} {}

void Sword_rusty::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
    // engine.events.add(Hit{defender, damage});
}