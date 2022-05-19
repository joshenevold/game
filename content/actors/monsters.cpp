#include "monsters.h"

#include <memory>

#include "actor.h"
#include "cleaver.h"
#include "engine.h"
#include "hammer_big.h"
#include "knife.h"
#include "monstertype.h"
#include "move.h"
#include "none.h"
#include "randomness.h"
#include "rest.h"
#include "spear.h"
#include "spiked_club.h"
#include "staff_green.h"
#include "sword_rusty.h"
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
    return {"skeleton", default_speed, health, std::make_shared<Knife>(1),
            default_behavior};
}

MonsterType zombie_small() {
    int health = 4;
    return {"zombie_small", default_speed, health, std::make_shared<Spear>(3),
            default_behavior};
}

MonsterType zombie() {
    int health = 4;
    return {"zombie", default_speed, health, std::make_shared<Sword_rusty>(3),
            default_behavior};
}

MonsterType zombie_big() {
    int health = 4;
    return {"zombie_big", default_speed, health,
            std::make_shared<Spiked_club>(3), default_behavior};
}

MonsterType muddy() {
    int health = 4;
    return {"muddy", default_speed, health, std::make_shared<Spear>(3),
            default_behavior};
}

MonsterType orc() {
    int health = 4;
    return {"orc", default_speed, health, std::make_shared<Spiked_club>(3),
            default_behavior};
}

MonsterType orc_masked() {
    int health = 4;
    return {"orc_masked", default_speed, health, std::make_shared<Cleaver>(3),
            default_behavior};
}

MonsterType ogre() {
    int health = 4;
    return {"ogre", default_speed, health, std::make_shared<Spiked_club>(3),
            default_behavior};
}

MonsterType necromancer() {
    int health = 4;
    return {"necromancer", default_speed, health,
            std::make_shared<Staff_green>(3), default_behavior};
}

MonsterType demon_tiny() {
    int health = 4;
    return {"demon_tiny", default_speed, health, std::make_shared<Spear>(3),
            default_behavior};
}

MonsterType demon() {
    int health = 4;
    return {"demon", default_speed, health, std::make_shared<Sword_rusty>(3),
            default_behavior};
}

MonsterType demon_big() {
    int health = 4;
    return {"demon_big", default_speed, health,
            std::make_shared<Sword_rusty>(3), default_behavior};
}
}  // namespace Monsters