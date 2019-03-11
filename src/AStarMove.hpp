#ifndef _ASTARMOVE_HPP
#define _ASTARMOVE_HPP

/**
 * \file AStarMove.hpp
 * \brief représente les mouvement d'un ghost avec l'algortithme aStar
 * \author zitoun-diallo-sid
 */

#include "WorldRenderer.hpp"

class AStarMove : public VisitorGhostMove{

    void visite(WorldRenderer * wr);

};

#endif
