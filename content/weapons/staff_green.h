
#pragma once
#include "actor.h"
#include "engine.h"
#include "event.h"
#include "hit.h"
#include "weapon.h"

class Staff_green : public Weapon {
   public:
    Staff_green(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};