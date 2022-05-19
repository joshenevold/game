#pragma once
#include "actor.h"
#include "engine.h"
#include "event.h"
#include "hit.h"
#include "weapon.h"

class Spiked_club : public Weapon {
   public:
    Spiked_club(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};