#pragma once

#include "action.h"
#include "vec.h"
// Move in the desired direction
class Move : public Action {
   public:
    Move(const Vec& direction);
    Result perform(Engine& engine) override;

   private:
    Vec direction;
};