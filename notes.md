# Notes on the game

Each step for adding a feature
* Define what you want to do, e.g. Add a hero
* Investigate parts of the engine that you need
* Make notes on these parts
* Make a detailed TODO list of what code to write
* Write Code
* Add your results to notes (code of schreenshot)

## Step one - make my hero show up 4/20
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
 - Reaction = std::function<std::unique_ptr<action>()
 - what is a function.

unordered map, data structure like a vector, unordered maps work better for larger programs, 

## Make the hero move 4/22

- Action    What an Actor does for its turn
- Event    Something that happens

Inside of perform() We have access to the actor and the engine

Results
- success() Action worked, Actor finishes with turn
- Failure() Couldn't perform Action, give Actor another turn. 
 - alternative(AnotherAction{} 
 - actions, inherage, overides
 - Vec - a 2d vector class used for position and direction, operators overlodaed
    -  (x,y) tile location (0,0,) is bottom-life
 - Actor public member function, change direciton, move_to()
 Tiles 
 - Tile& tile =      engine.dungeon.tiles(position), 
 - Tile is wall(), bool walkable, Actor*actor
 - a 2D grid of class Tile inside class Dungeon (engion/map/dungeon)
 - walkable, is door() is wall()

 Keybindings


TODO for wednesday:
 - write the code to make the hero move
 - Bind Rest action to a key of your choice
 - Creat Move action 
    - Only move Hero to empty Tile(success())
    - Walls, doors and other actions block(failure())
    - Dont forget to send direction of actor
 - Vind Move to left, right, up, down


## More on actions 4/25 
- Move is bound to an actor?
- keybinding is in herotype 
- unordered map is a pair of types eg. name and phone number
    - The unordered map we have is a string and a reaction
- Reaction is a function that returns a unique_ptr to an action
- std::function 
    - The embodiment of a function as an object that you can pass around like any other variable
```C++ 
int summing( func, x){
    int sum = 0 ; 
    for (auto x : x){
        sum += func(x);
    }
    return sum;
}

 ```

 Making a function
 ```C++ 
square = [](int x){
    return x*x;
};
 ``` 

 - the game engine knows that when I press the left arrow it is inputing the string "Left"
- place move.h/cpp in content/actions/_______
- CMakeLast.txt move.cpp
- #include <memory> to get 

Move(Vec direction)

private
    vec direction

## making doors work, adding monsters 4/27
 - return alternative to open doors
 - we will have to write open door but not the wander function
 - get Door objec t at a specific postion
 - open it
 - if Door is now open, set the Tile that it sits on to walkable = true
 
 Wander(Action)
    dir = random()
    return Alternative(Move{dir})

Move(Action)
    if door(){
        return Alt(Opendoor)
    }

 - dungeon.h has an unordred_map with Vec, Door called doors
 - unordered map takes in a key, it returns a location of a door? 
 - use .at() to call the map

 Door class
 - Takes in 2 pictures and where vertical or horizontal
 - all we need to use is_open() 
 - void open();
 - void close();
 - it is just flipping a boolian to change the picture that shows