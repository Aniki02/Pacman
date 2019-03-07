#include "WorldRenderer.hpp"
#include <iostream>
#include "PElement.hpp"
#include "VisitorGhostMove.hpp"
#include "RandomMove.hpp"


static const Vecteur2D NORTH(0,1), NORTHEAST(1, 1), EAST(1,0),SOUTHEAST(1, -1), SOUTH(0, -1), SOUTHWEST(-1, -1),
                        WEST(-1,0), NORTHWEST(-1, 1);

WorldRenderer::WorldRenderer(){
    _world = new World();
    _spritePacman.setTexture(TextureFactory::getInstance()->getTexture(_world->getPacman()->getName()));
    _spriteGhost.setTexture(TextureFactory::getInstance()->getTexture(_world->getGhost()->getName()));

    unsigned int magenta = Color::Magenta.toInteger();		// récupère la couleur Magenta au format nombre entier non signé
    unsigned int turquoise = 0x00CED1FF;	// couleur turquoise opaque. préfixe 0x pour héxadécimal. format RGBA
    unsigned int vertCitron = 0x00FF00FF;
    this->_labyrinthe = new LevelGenerator(7,magenta, turquoise, vertCitron);
}

void WorldRenderer::handleInput(sf::Event event){
    VisitorGhostMove * visiteur = new RandomMove();
    this->accepteMove(visiteur);
    this->movePacman(event);
}
void WorldRenderer::update(sf::Event event){
    this->handleInput(event);

}


void WorldRenderer::movePacman(sf::Event event){
    if(event.type == sf::Event::EventType::KeyPressed){

        PElement<Sommet<VSommet> > * voisins = _labyrinthe->getGraphe()->voisins(_labyrinthe->getSommetCourant());

        if(event.key.code == sf::Keyboard::A){this->move(NORTHWEST, voisins);}
        if(event.key.code == sf::Keyboard::Z){this->move(NORTH, voisins);}
        if(event.key.code == sf::Keyboard::E){this->move(NORTHEAST, voisins);}
        if(event.key.code == sf::Keyboard::D){this->move(EAST, voisins);}
        if(event.key.code == sf::Keyboard::C){this->move(SOUTHEAST, voisins);}
        if(event.key.code == sf::Keyboard::X){this->move(SOUTH, voisins);}
        if(event.key.code == sf::Keyboard::W){this->move(SOUTHWEST, voisins);}
        if(event.key.code == sf::Keyboard::Q){this->move(WEST, voisins);}
    }
}

void WorldRenderer::move(Vecteur2D direction, PElement<Sommet<VSommet>> * voisins){
    PeutSeDeplacer foncteur(_labyrinthe->getSommetCourant()->v.pos, -direction);
    PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
    if(newSommet != nullptr){
        _world->getPacman()->move(direction);
        _labyrinthe->setSommetCourant(newSommet->valeur);
    }
}

