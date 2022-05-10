#include "monsters.h"

#include <memory>

#include "actor.h"
#include "cleaver.h"
#include "engine.h"
#include "hammer_big.h"
#include "monstertype.h"
#include "move.h"
#include "none.h"
#include "randomness.h"
#include "rest.h"
#include "staff_green.h"
#include "wander.h"

namespace Monsters {
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me) {
    // pursue Hero if monster can see him (If Hero sees me, I see him)
    if (me.is_visible() && engine.hero) {
        Vec from = me.get_position();
        Vec to = engine.hero->get_position();
        std::vector<Vec> path = engine.dungeon.calculate_path(from, to);
        if (path.size() > 1) {
            Vec direction = path.at(1) - path.at(0);
            return std::make_unique<Move>(direction);
        }
    }
    // Monster doesn't see Hero
    if (probability(66)) {
        return std::make_unique<Wander>();
    } else {
        return std::make_unique<Rest>();
    }
}
MonsterType goblin() {
    int health = 2;
    return {"goblin", default_speed, health, std::make_shared<Cleaver>(2),
            default_behavior};
}

MonsterType orc_shaman() {
    int health = 4;
    return {"orc_shaman", default_speed, health,
            std::make_shared<Staff_green>(1), default_behavior};
}

MonsterType skeleton() {
    int health = 4;
    return {"skeleton", default_speed, health, std::make_shared<Hammer_big>(3),
            default_behavior};
}
}  // namespace Monsters