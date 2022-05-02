#include "engine.h"
#include "heros.h"
#include "monsters.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::guy);
    MonsterType type = Monsters::goblin();
    engine.create_monster(type);
    engine.run();
    // while game is running cin an input
    // pass imput into perform
}
