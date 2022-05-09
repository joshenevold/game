#include "cleaver.h"

#include "engine.h"
#include "hit.h"
#include "swing.h"

Cleaver::Cleaver(int damage) : Weapon{"cleaver", damage} {}

void Cleaver::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
    // engine.events.add(Hit{defender, damage});
}