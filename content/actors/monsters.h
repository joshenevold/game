#pragma once
#include <memory>

#include "engine.h"
#include "monster.h"

namespace Monsters {

constexpr int default_speed{4};

MonsterType goblin();
MonsterType orc_shaman();
MonsterType skeleton();
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me);

}  // namespace Monsters
