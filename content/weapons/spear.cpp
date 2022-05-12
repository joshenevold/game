#include "spear.h"

#include "engine.h"
#include "hit.h"
#include "stab.h"

Spear::Spear(int damage) : Weapon{"spear", damage} {}

void Spear::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Stab{sprite, direction, defender, damage});
}