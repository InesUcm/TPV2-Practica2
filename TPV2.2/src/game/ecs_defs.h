// This file is part of the course TPV2@UCM - Samir Genaim

// DO NOT USE/MODIFY THIS FILE, IT IS JUST AN EXAMPLE OF HOW YOUR
// game/ecs_defs.h SHOULD LOOK LIKE
//
// Note that the backslash \ after each line below is very important
// when using #define, if you remove it then put all at the same
// line of #define
//

#pragma once

// Components list - must have at least one element
//
class Transform;
class Image;
#define _CMPS_LIST_ \
	Transform, \
	Image

// Groups list - must have at least one element
//
#define _GRPS_LIST_ \
    GHOST, \
    FRUIT

// Handlers list - must have at least one element
//
#define _HDLRS_LIST_ \
    PACMAN

// Systems list - must have at least one element
//
class RenderSystem;
class CollisionsSystem;
class PacManSystem;
class GhostSystem;
class FoodSystem;

#define _SYS_LIST_ \
    PacManSystem,    \
    GhostSystem,     \
    FoodSystem,      \
    RenderSystem,    \
    CollisionsSystem