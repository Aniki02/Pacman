#include <cstdlib>
#include <ctime>
#include "RandomMove.hpp"
#include "WorldRenderer.hpp"
#include "PElement.hpp"


void RandomMove::visite(WorldRenderer * wr){
    srand(time(0));
    // On recherche les voisins
    PElement<Sommet<VSommet> > * voisins = wr->_labyrinthe->getGraphe()->voisins(wr->_labyrinthe->getSommetGhost());
    int numSommetAlea = rand() % (PElement<Sommet<VSommet>>::taille(voisins));
    while(numSommetAlea > 0 && voisins->suivant != nullptr){
        voisins = voisins->suivant;
        numSommetAlea--;
    }
    Vecteur2D direction = this->direction(wr->_world->getGhost()->getPosition(), voisins->valeur->v.pos);
    wr->_world->getGhost()->move(direction);
    wr->_labyrinthe->setSommetGhost(voisins->valeur);
}

 Vecteur2D RandomMove::direction(Vecteur2D sommetDepart, Vecteur2D sommetArrive) {
    
    int x(0), y(0);
    
    if(sommetArrive.x > sommetDepart.x)
        x = 1;
    else{
        if(sommetArrive.x < sommetDepart.x)
            x = -1;
    }

    if(sommetArrive.y > sommetDepart.y)
        y = 1;
    else{
        if(sommetArrive.y < sommetDepart.y)
            y = -1;
    }
    return Vecteur2D(x,y);
    

}

