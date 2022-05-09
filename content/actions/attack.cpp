#include "attack.h"

Attack::Attack(Actor& defender) : defender{defender} {}
// Die::Die(Actor& actor) : actor{actor} {}

Result Attack::perform(Engine& engine) {
    actor->attack(defender);
    return success();
    // Weapon& weapon = type.weapon ->use(engine, *this, defender);
    // actor.weapon.use(engine, attacker, defender);
}