#pragma once

#include "actor.h"
#include "engine.h"
#include "event.h"
#include "hit.h"
#include "weapon.h"

class Sword_rusty : public Weapon {
   public:
    Sword_rusty(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};