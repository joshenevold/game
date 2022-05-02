#pragma once
#include "actor.h"
#include "event.h"

class Hit : public Event {
   public:
    Hit(Actor& defender, int amount);
    void execute(Engine& engine) override;

   private:
    Actor& defender;
    int amount;
};