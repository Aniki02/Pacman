#ifndef _RANDOMMOVE_HPP
#define _RANDOMMOVE_HPP
/**
 * \file RandomMove.hpp
 * \brief représente les mouvement d'un ghost de façon aléatoire
 * \author zitoun-diallo-sid
 */

#include "WorldRenderer.hpp"
#include "VisitorGhostMove.hpp"

class WorldRenderer;

class RandomMove : public VisitorGhostMove{
public:
    void visite(WorldRenderer * world);
};

#endif
