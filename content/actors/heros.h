#pragma once

#include "cleaver.h"
#include "closedoor.h"
#include "herotype.h"
#include "move.h"
#include "none.h"
#include "rest.h"
#include "sword_red_gem.h"

namespace Heros {

std::unordered_map<std::string, Reaction> key_bindings = {
    {"A",
     []() {
         return std::make_unique<Move>(Vec{-1, 0});
     }},
    {"D",
     []() {
         return std::make_unique<Move>(Vec{1, 0});
     }},
    {"W",
     []() {
         return std::make_unique<Move>(Vec{0, 1});
     }},
    {"S",
     []() {
         return std::make_unique<Move>(Vec{0, -1});
     }},
    {"R", []() { return std::make_unique<Rest>(); }},
    {"C", []() { return std::make_unique<CloseDoor>(); }},
};

constexpr int default_speed{8};
const HeroType nobody{"none", default_speed, 1, std::make_shared<None>(), {}};
const HeroType guy{"dragon", default_speed, 25,
                   std::make_shared<Sword_red_gem>(3), key_bindings};
}  // namespace Heros
