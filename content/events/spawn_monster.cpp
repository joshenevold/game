#include "spawn_monster.h"

#include <iostream>
#include <random>
#include <vector>

#include "monster.h"
#include "monsters.h"

Spawn_monster::Spawn_monster() {}

// creates two randomized monsters
void Spawn_monster::execute(Engine& engine) {
    engine.create_monster(random_monster());
    engine.create_monster(random_monster());
}

// Random number generator
int Spawn_monster::randint(int min, int max) {
    static std::random_device rd;
    static std::default_random_engine ran{rd()};
    return std::uniform_int_distribution<>{min, max}(ran);
}

// fills vector with all monsters, then returns MonsterType reandom monster
MonsterType Spawn_monster::random_monster() {
    std::vector<MonsterType> monsters{
        Monsters::skeleton(),     Monsters::goblin(), Monsters::orc_shaman(),
        Monsters::zombie_small(), Monsters::zombie(), Monsters::zombie_big(),
        Monsters::muddy(),        Monsters::orc(),    Monsters::orc_masked(),
        Monsters::demon_big(),    Monsters::ogre(),   Monsters::necromancer(),
        Monsters::demon_tiny(),   Monsters::demon()};

    // std::cout << "this is the monster id " << std::flush;
    return monsters.at(randint(0, 13));
}