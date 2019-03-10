#include <cstdlib>
#include <ctime>
#include "RandomMove.hpp"
#include "WorldRenderer.hpp"
#include "PElement.hpp"
#include "ChoixSommet.hpp"


void RandomMove::visite(WorldRenderer * wr){
    
    Sommet<InfoSommet> * sommetChoisi = ChoixSommet<InfoSommet>::choixRandom(wr->_labyrinthe->getGraphe(), wr->_labyrinthe->getSommetGhost());
    Vecteur2D direction = this->direction(wr->_world->getGhost()->getPosition(), sommetChoisi->v.vSommet.pos);
    wr->_world->getGhost()->move(direction);
    wr->_labyrinthe->setSommetGhost(sommetChoisi);
}


