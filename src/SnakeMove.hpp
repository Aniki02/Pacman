#ifndef _SNAKEMOVE_HPP
#define _SNAKEMOVE_HPP
/**
 * \file SnakeMove.hpp
 * \brief représente les mouvement d'un ghost grace au flair du serpent et a la vue
 * \author zitoun-diallo-sid
 */
#include "WorldRenderer.hpp"
class SnakeMove : public VisitorGhostMove{

void visite(WorldRenderer * world);

};

#endif
