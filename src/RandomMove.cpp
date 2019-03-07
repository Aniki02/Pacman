#include "RandomMove.hpp"
#include "WorldRenderer.hpp"
#include "PElement.hpp"


static const Vecteur2D NORTH(0,-1), NORTHEAST(-1, -1), EAST(-1,0),
                        SOUTHEAST(-1, 1), SOUTH(0, 1), SOUTHWEST(1, 1),
                        WEST(1,0), NORTHWEST(1, -1);


void RandomMove::visite(WorldRenderer * world){
    int v1 = rand() % 8 ;
    PElement<Sommet<VSommet> > * voisins = world->labyrinthe->getGraphe()->voisins(world->labyrinthe->getSommetGhost());

        if(v1 == 0){
            PeutSeDeplacer foncteur(world->labyrinthe->getSommetGhost()->v.pos, NORTHWEST);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){

                world->_world->getGhost()->moveNorthWest();
                world->labyrinthe->setSommetGhost(newSommet->valeur);
            }
        }


        if(v1 == 1){

            PeutSeDeplacer foncteur(world->labyrinthe->getSommetGhost()->v.pos, NORTH);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                world->_world->getGhost()->moveNorth();
                world->labyrinthe->setSommetGhost(newSommet->valeur);
            }

        }

        if(v1 == 2){
            PeutSeDeplacer foncteur(world->labyrinthe->getSommetGhost()->v.pos, NORTHEAST);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                world->_world->getGhost()->moveNorthEast();
                world->labyrinthe->setSommetGhost(newSommet->valeur);
            }
        }

        if(v1 == 3){
            PeutSeDeplacer foncteur(world->labyrinthe->getSommetGhost()->v.pos, EAST);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                world->_world->getGhost()->moveEast();
                world->labyrinthe->setSommetGhost(newSommet->valeur);
            }
        }
        if(v1 == 4){
            PeutSeDeplacer foncteur(world->labyrinthe->getSommetGhost()->v.pos, SOUTHEAST);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                world->_world->getGhost()->moveSouthEast();
                world->labyrinthe->setSommetGhost(newSommet->valeur);
            }
        }
        if(v1 == 5){
            PeutSeDeplacer foncteur(world->labyrinthe->getSommetGhost()->v.pos, SOUTH);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                world->_world->getGhost()->moveSouth();
                world->labyrinthe->setSommetGhost(newSommet->valeur);
            }
        }
        if(v1 == 6){
            PeutSeDeplacer foncteur(world->labyrinthe->getSommetGhost()->v.pos, SOUTHWEST);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                world->_world->getGhost()->moveSouthWest();
                world->labyrinthe->setSommetGhost(newSommet->valeur);
            }
        }
        if(v1 == 7){
            PeutSeDeplacer foncteur(world->labyrinthe->getSommetGhost()->v.pos, WEST);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                world->_world->getGhost()->moveWest();
                world->labyrinthe->setSommetGhost(newSommet->valeur);
            }
        }
    }


