#include "stab.h"

#include <cmath>

#include "actor.h"
#include "engine.h"
#include "hit.h"
#include "swing.h"

constexpr int duration = 4;

Stab::Stab(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{duration},
      sprite{sprite},
      copy{sprite},
      defender{defender},
      damage{damage},
      starting_angle{sprite.angle} {
    if (direction == Vec{1, 0}) {
        starting_angle = 90;
        x_start = 1;
        y_start = -35;
        x_shift = 5 / (duration - 1);
        y_shift = 0;
    } else if (direction == Vec{-1, 0}) {
        starting_angle = 270;
        x_start = 1;
        y_start = -35;
        x_shift = -5 / (duration - 1);
        y_shift = 0;
    } else if (direction == Vec{0, 1}) {
        starting_angle = 0;
        x_start = 1;
        y_start = -35;
        x_shift = 0;
        y_shift = -5 / (duration - 1);
        ;
    } else {
        starting_angle = 180;
        x_start = 1;
        y_start = -35;
        x_shift = 0;
        y_shift = 5 / (duration - 1);
        ;
    }
}

void Stab::execute(Engine& engine) {
    // modify the sprite
    sprite.angle = starting_angle;
    sprite.shift.x = x_start + x_shift * frame_count;
    sprite.shift.y = y_start + y_shift * frame_count;
}

//     if (direction == Vec{1, 0}) {
//         sprite.shift.x -= 1 * frame_count;
//     }
//     if (direction == Vec{-1, 0}) {
//         sprite.shift.x += 1 * frame_count;
//     }
//     if (direction == Vec{0, 1}) {
//         sprite.shift.y += 1 * frame_count;
//     }
//     if (direction == Vec{0, -1}) {
//         sprite.shift.x -= 1 * frame_count;
//     }
// }

void Stab::when_done(Engine& engine) {
    sprite = copy;
    engine.events.add(Hit{defender, damage});
}