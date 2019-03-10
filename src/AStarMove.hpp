#ifndef _ASTARMOVE_HPP
#define _ASTARMOVE_HPP
#include "WorldRenderer.hpp"
class AStarMove : public VisitorGhostMove{

    void visite(WorldRenderer * wr);

};

#endif
