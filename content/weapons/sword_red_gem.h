#pragma once
#include "actor.h"
#include "engine.h"
#include "event.h"
#include "hit.h"
#include "weapon.h"

class Sword_red_gem : public Weapon {
   public:
    Sword_red_gem(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};