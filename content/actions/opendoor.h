#pragma once
#include "action.h"
#include "engine.h"

class Opendoor : public Action {
   public:
    Opendoor(const Vec& position);
    Result perform(Engine& engine) override;

   private:
    Vec position;
};