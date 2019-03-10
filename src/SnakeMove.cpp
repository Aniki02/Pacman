#include "SnakeMove.hpp"
#include "ChoixSommet.hpp"
    void SnakeMove::visite(WorldRenderer * wr){

        Sommet<InfoSommet> * sommetChoisi = ChoixSommet<InfoSommet>::choixSnake(wr->_labyrinthe->getGraphe(), wr->_labyrinthe->getSommetGhost());
        Vecteur2D direction =this->direction(wr->_world->getGhost()->getPosition(), sommetChoisi->v.vSommet.pos);
        Vecteur2D vue = Vecteur2D::poursuite(wr->_labyrinthe->getSommetCourant()->v.vSommet.pos, wr->_labyrinthe->getSommetGhost()->v.vSommet.pos);
        if (vue != Vecteur2D(0,0)){
            direction = vue;
            sommetChoisi = ChoixSommet<InfoSommet>::choixVue(wr->_labyrinthe->getGraphe(), wr->_labyrinthe->getSommetGhost(), direction);
        }
        wr->_world->getGhost()->move(direction);
        wr->_labyrinthe->setSommetGhost(sommetChoisi);
    }


