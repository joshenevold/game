# Notes on the game

Each step for adding a feature
* Define what you want to do, e.g. Add a hero
* Investigate parts of the engine that you need
* Make notes on these parts
* Make a detailed TODO list of what code to write
* Write Code
* Add your results to notes (code of schreenshot)

## Step one - make my hero show up
Lookin in 'main.cpp' I see 
```C++ 
#include "engine.h"
#include "heros.h"

 engine.create_hero(Heros::nobody);
 ```

 Carecters are in 'content/actors/heros.h'
 ```const HeroType nobody{"none", default_speed, 1, std::make_shared<None>(), {}};```

 - "none" is the name of a sprite in 'assets/heros.txt'
 
 TODO aka HOMEWORK:
 - Look up shared_ptr in Tour of C++ or C++ reference
 - understand relationship with shared_pt and make_shared. Where do i specify the type
 - unordered_map? string & Reaction
 - Reaction = std::function<std::unique_ptr<action>()>;, what is a function.
