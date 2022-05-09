#include "hit.h"

#include "die.h"
#include "engine.h"

Hit::Hit(Actor& defender, int amount) : defender{defender}, amount{amount} {}

void Hit::execute(Engine& engine) {
    defender.take_damage(amount);
    // could add a graphic for events.add(blood)
    if (defender.health <= 0) {
        engine.events.add(Die{defender});
    }
}