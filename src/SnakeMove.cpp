
#include "SnakeMove.hpp"
#include "ChoixSommet.hpp"
    void SnakeMove::visite(WorldRenderer * wr){

        Sommet<VSommet> * sommetChoisi = ChoixSommet<VSommet>::choixSnake(wr->_labyrinthe->getGraphe(), wr->_labyrinthe->getSommetGhost());
        Vecteur2D direction = this->direction(wr->_world->getGhost()->getPosition(), sommetChoisi->v.pos);
        wr->_world->getGhost()->move(direction);
        wr->_labyrinthe->setSommetGhost(sommetChoisi);
    }

   /* void SnakeMove::visite(WorldRenderer * wr)
    {   if(wr->_labyrinthe->getSommetCourant() != wr->_labyrinthe->getSommetPrecedent())
            wr->_labyrinthe->getGraphe()->getAreteParSommets(wr->_labyrinthe->getSommetCourant(),wr->_labyrinthe->getSommetPrecedent())->v.devant=0x00FF0000;
    }*/

 /*Vecteur2D SnakeMove::poursuite(Vecteur2D sommetGhost Vecteur2D sommetPacman) {
    if(sommetGhost.x == sommetPacman.x)
        if(sommetGhost.x < sommetPacman.x)
          return  Vecteur2D(1,0);
           else return Vecteur2D(-1,0);

    if(sommetGhost.y == sommetPacman.y)
        if(sommetGhost.y < sommetPacman.y)
            return Vecteur2D(0,1);
        else return VecteurD(0,-1);

   //      Vecteur2D direction = this->poursuite(wr->_world->getGhost()->getPosition(), wr->_world->getPacman()->getPosition());
     //   wr->_world->getGhost()->move(direction);
     //   wr->_labyrinthe->setSommetGhost();
}*/




