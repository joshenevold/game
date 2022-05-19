#include "spiked_club.h"

#include "engine.h"
#include "hit.h"
#include "swing.h"

Spiked_club::Spiked_club(int damage) : Weapon{"spiked_club", damage} {}

void Spiked_club::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
    // engine.events.add(Hit{defender, damage});
}