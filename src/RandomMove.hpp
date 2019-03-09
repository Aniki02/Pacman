#ifndef _RANDOMMOVE_HPP
#define _RANDOMMOVE_HPP

#include "WorldRenderer.hpp"
#include "VisitorGhostMove.hpp"

class WorldRenderer;

class RandomMove : public VisitorGhostMove{
public:
    void visite(WorldRenderer * world);
};

#endif
