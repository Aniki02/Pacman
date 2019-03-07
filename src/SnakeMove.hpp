#ifndef _SNAKEMOVE_HPP
#define _SNAKEMOVE_HPP
#include "WorldRenderer.hpp"
class SnakeMove : public VisitorGhostMove{

void visite(WorldRenderer * world);

};

#endif
