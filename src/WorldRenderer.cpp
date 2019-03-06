#include "WorldRenderer.hpp"
#include <iostream>
#include "PElement.hpp"
static const Vecteur2D NORTH(0,-1), NORTHEAST(-1, -1), EAST(-1,0), 
                        SOUTHEAST(-1, 1), SOUTH(0, 1), SOUTHWEST(1, 1),
                        WEST(1,0), NORTHWEST(1, -1);

void WorldRenderer::handleInput(sf::Event event){
    this->movePacman(event);
}
void WorldRenderer::update(sf::Event event){
    this->handleInput(event);
}





void WorldRenderer::movePacman(sf::Event event){
    if(event.type == sf::Event::EventType::KeyPressed){

        PElement<Sommet<VSommet> > * voisins = labyrinthe->getGraphe()->voisins(labyrinthe->getSommetCourant());

        if(event.key.code == sf::Keyboard::A){
            PeutSeDeplacer foncteur(labyrinthe->getSommetCourant()->v.pos, NORTHWEST);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                
                _world->getPacman()->moveNorthWest();
                labyrinthe->setSommetCourant(newSommet->valeur);
            }

        }

        if(event.key.code == sf::Keyboard::Z){

            PeutSeDeplacer foncteur(labyrinthe->getSommetCourant()->v.pos, NORTH);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                _world->getPacman()->moveNorth();
                labyrinthe->setSommetCourant(newSommet->valeur);
            }

        }
        
        if(event.key.code == sf::Keyboard::E){
            PeutSeDeplacer foncteur(labyrinthe->getSommetCourant()->v.pos, NORTHEAST);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                _world->getPacman()->moveNorthEast();
                labyrinthe->setSommetCourant(newSommet->valeur);
            }
        }
       
        if(event.key.code == sf::Keyboard::D){
            PeutSeDeplacer foncteur(labyrinthe->getSommetCourant()->v.pos, EAST);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                _world->getPacman()->moveEast();
                labyrinthe->setSommetCourant(newSommet->valeur);
            }
        }
        if(event.key.code == sf::Keyboard::C){
            PeutSeDeplacer foncteur(labyrinthe->getSommetCourant()->v.pos, SOUTHEAST);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                _world->getPacman()->moveSouthEast();
                labyrinthe->setSommetCourant(newSommet->valeur);
            }
        }
        if(event.key.code == sf::Keyboard::X){
            PeutSeDeplacer foncteur(labyrinthe->getSommetCourant()->v.pos, SOUTH);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                _world->getPacman()->moveSouth();
                labyrinthe->setSommetCourant(newSommet->valeur);
            }
        }
        if(event.key.code == sf::Keyboard::W){
            PeutSeDeplacer foncteur(labyrinthe->getSommetCourant()->v.pos, SOUTHWEST);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                _world->getPacman()->moveSouthWest();
                labyrinthe->setSommetCourant(newSommet->valeur);
            }
        }
        if(event.key.code == sf::Keyboard::Q){
            PeutSeDeplacer foncteur(labyrinthe->getSommetCourant()->v.pos, WEST);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                _world->getPacman()->moveWest();
                labyrinthe->setSommetCourant(newSommet->valeur);
            }
        }
    }
}
// void WorldRenderer::moveGhost(sf::Event event){}
