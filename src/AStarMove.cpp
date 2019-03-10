#include "AStarMove.hpp"
#include "ChoixSommet.hpp"


void AStarMove::visite(WorldRenderer * wr){
    Sommet<InfoSommet> * sommetChoisi = ChoixSommet<InfoSommet>::choixAStar(wr->_labyrinthe->getGraphe(), wr->_labyrinthe->getSommetGhost(), wr->_labyrinthe->getSommetCourant());
    Vecteur2D direction = this->direction(wr->_world->getGhost()->getPosition(), sommetChoisi->v.vSommet.pos);
    wr->_world->getGhost()->move(direction);
    wr->_labyrinthe->setSommetGhost(sommetChoisi);
}