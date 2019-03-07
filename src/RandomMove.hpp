#ifndef _RANDOMMOVE_HPP
#define _RANDOMMOVE_HPP

#include "WorldRenderer.hpp"

class RandomMove : public VisitorGhostMove{

void visite(WorldRenderer * world);

};

#endif
