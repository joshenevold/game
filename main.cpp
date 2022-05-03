#include "engine.h"
#include "heros.h"
#include "monsters.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::guy);
    MonsterType gob = Monsters::goblin();
    engine.create_monster(gob);
    MonsterType shaman = Monsters::orc_shaman();
    engine.create_monster(shaman);
    MonsterType skel = Monsters::skeleton();
    engine.create_monster(skel);
    engine.run();
    // while game is running cin an input
    // pass imput into perform
}
