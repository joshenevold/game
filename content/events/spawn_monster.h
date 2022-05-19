#pragma once

#include "actor.h"
#include "engine.h"
#include "event.h"

class Spawn_monster : public Event {
   public:
    Spawn_monster();
    void execute(Engine& engine) override;
    MonsterType random_monster();
    int randint(int min, int max);
};
