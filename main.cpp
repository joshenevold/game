#include "engine.h"
#include "heros.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::guy);
    engine.run();
    // while game is running cin an input
    // pass imput into perform
}
