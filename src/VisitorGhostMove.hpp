#ifndef _VISITORGHOSTMOVE_HPP
#define _VISITORGHOSTMOVE_HPP

#include "WorldRenderer.hpp"


class VisitorGhostMove{
public :
    virtual void visite(WorldRenderer * world) = 0;
};
#endif
