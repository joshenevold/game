#include "staff_green.h"

#include "engine.h"
#include "hit.h"
#include "swing.h"

Staff_green::Staff_green(int damage) : Weapon{"staff_green", damage} {}

void Staff_green::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
    // engine.events.add(Hit{defender, damage});
}