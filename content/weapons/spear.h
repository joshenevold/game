
#pragma once
#include "actor.h"
#include "engine.h"
#include "event.h"
#include "hit.h"
#include "weapon.h"

class Spear : public Weapon {
   public:
    Spear(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};