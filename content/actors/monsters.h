#pragma once
#include <memory>

#include "engine.h"
#include "monster.h"

namespace Monsters {

constexpr int default_speed{4};

MonsterType goblin();
MonsterType orc_shaman();
MonsterType skeleton();
MonsterType zombie_small();
MonsterType zombie();
MonsterType zombie_big();
MonsterType muddy();
MonsterType orc();
MonsterType orc_masked();
MonsterType demon_big();
MonsterType ogre();
MonsterType necromancer();
MonsterType demon_tiny();
MonsterType demon();

std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me);

}  // namespace Monsters
