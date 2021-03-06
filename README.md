# C-Iniside - A new generation game developing
Hello and welcome to Iniside's RPG Game project for Unity 5.

Author: in1side

IMPORTANT:
Please do not use AttributeSystem module right now. It's going to be changed (again), because while current design is very flexible,
it's nearly impossible to create, effects of type Strongest Override and similar, which rely on checking which
effects are strongest or weakest. That is because every effect can modify multiple attributes.
One effect can Modify Strength by 10 and Stamina by 5, while other can modify Strength by 15 and Stamina 3.
Which effect should take precedence ? The one with higher strength, higher stamina, or just the one with single highest attribute ?
In new version, I will most likely (99%) change it, so one effect can modify only one attribute,
this will greatly simplify effect creation (and effects in general), and if you want to modify multiple attributes, you
will just need to apply multiple effects.

Goal of this project is to provide sample game framework for creating RPG game elements in any type of game.
There is also sample implementation of how you can intergate modules, to make them work together, inside
GameSystem module. 

Modules:

ActionRPGGame - main game module, which will implement very game specific parts of code. Like attributes.

GameAbilities - base implementation of Abilities for game. Abilities are simple instanced objects, which contain
state machine.

GameAnimations - nothing yet. In long run it's supposed to contain some basic animation functionality
like IK.

GameAttributes - Most core module of project. Contains implementation of attributes and effects.
Attributes are of two types. Primitive and Complex. Primitive are simple floats, while Complex, are structs,
which can self track their current state.
Effects, are the only safe way to interact with attributes. They implement you standard buff/debuff system
as well as damage system (they are simply categorized as instant effects, fire and forget).

GameInterfaces - an collection of interfaces shared between all modules.

GameSystem - sample itegration of all game modules except ActionRPGGame.

GameTrace - Standard implementation of some tracing objects, which can be easily added to other objects to
let designer easily set tracing (though care must be taken, on how exactly let designer setup tracing,
as those object do not provide any standard implementation, only basic hooks to retrieve data).

GameWeapons - base implementation of weapons. It's very similiar to Abilities, except, Weapons, are 
Actors, can exist in world, and can take care of their own network replication.
