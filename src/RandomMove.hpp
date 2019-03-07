#ifndef _RANDOMMOVE_HPP
#define _RANDOMMOVE_HPP

#include "WorldRenderer.hpp"
#include "VisitorGhostMove.hpp"

class WorldRenderer;

class RandomMove : public VisitorGhostMove{
public:
    void visite(WorldRenderer * world);
    Vecteur2D direction(Vecteur2D sommetDepart, Vecteur2D sommetArrive);

};

#endif
