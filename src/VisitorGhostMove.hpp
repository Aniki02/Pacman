#ifndef _VISITORGHOSTMOVE_HPP
#define _VISITORGHOSTMOVE_HPP

class WorldRenderer;


class VisitorGhostMove{
public :
    virtual void visite(WorldRenderer * world) = 0;
};
#endif
