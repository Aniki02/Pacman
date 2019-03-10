#include "WorldRenderer.hpp"
#include <iostream>
#include "PElement.hpp"
#include "VisitorGhostMove.hpp"
#include "RandomMove.hpp"
#include "SnakeMove.hpp"
#include "AStarMove.hpp"

//////////// Vecteur de direction //////////////
static const Vecteur2D NORTH(0,1), NORTHEAST(1, 1), EAST(1,0),SOUTHEAST(1, -1), SOUTH(0, -1), SOUTHWEST(-1, -1),
                        WEST(-1,0), NORTHWEST(-1, 1);

//////////////////////////////////////////// CONSTRUCTEUR ///////////////////////////////////////////////////////////////////////////
WorldRenderer::WorldRenderer(){
    _world = new World();
    _spritePacman.setTexture(TextureFactory::getInstance()->getTexture(_world->getPacman()->getName()));
    _spriteGhost.setTexture(TextureFactory::getInstance()->getTexture(_world->getGhost()->getName()));
    _time = 0;
    _score = 1;
    _nbVie = 3;

    unsigned int magenta = Color::Magenta.toInteger();		// récupère la couleur Magenta au format nombre entier non signé
    unsigned int turquoise = 0x00CED1FF;	// couleur turquoise opaque. préfixe 0x pour héxadécimal. format RGBA
    unsigned int rouge = 0xFF000000;  //rouge transparent

    this->_labyrinthe = new LevelGenerator(7,magenta, turquoise, rouge);
    _spritePacman.setPosition(0,0);
    _spriteGhost.setPosition(300,300);
    _world->getGhost()->setPosition(_labyrinthe->getSommetGhost()->v.vSommet.pos);
    _world->getPacman()->setPosition(_labyrinthe->getSommetCourant()->v.vSommet.pos);
}



///////////////////////////////////////////// METHODE //////////////////////////////////////////////////////////////////////////////


/////////////// HANDLE INPUT //////////////////
void WorldRenderer::handleInput(sf::Event event){
    this->movePacman(event);
}


/////////////// UPDATE //////////////////
void WorldRenderer::update(sf::Event event){
    this->handleInput(event);
}

/////////////// MOVE PACMAN //////////////////
void WorldRenderer::movePacman(sf::Event event){

    if(event.type == sf::Event::EventType::KeyPressed){

        PElement<Sommet<InfoSommet> > * voisins = _labyrinthe->getGraphe().voisins(_labyrinthe->getSommetCourant());

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

/////////////// MOVE GHOST //////////////////
void WorldRenderer::moveGhost(){
    if(_time > 1){
        // baisse l'opacité de la couleur de chaque arete tant qu'elle n'est pas transparente
        this->updateArete();
        VisitorGhostMove * visiteur = new SnakeMove();
        this->accepteMove(visiteur);
        _time = 0;
    }
}

/////////////// MOVE //////////////////
void WorldRenderer::move(Vecteur2D direction, PElement<Sommet<InfoSommet>> * voisins){
    PeutSeDeplacer foncteur(_labyrinthe->getSommetCourant()->v.vSommet.pos, direction);
    PElement<Sommet <InfoSommet> > * newSommet = PElement<Sommet<InfoSommet> >::appartient(voisins, foncteur);

    if(newSommet != nullptr){
        _world->getPacman()->move(direction);
        if(_labyrinthe->getSommetCourant() != newSommet->valeur)
            _labyrinthe->getGraphe().getAreteParSommets(_labyrinthe->getSommetCourant(),newSommet->valeur)->v.devant=0xFF0000FF;
        this->updateScore();
        _labyrinthe->setSommetCourant(newSommet->valeur);
    }
}

/////////////// UPDATE SCORE //////////////////
void WorldRenderer::updateScore(){
    // On augmente le score seulement si sommet n'a jamais étais visité
    if(!_labyrinthe->getSommetCourant()->v.vSommet.isVisited){
        _labyrinthe->getSommetCourant()->v.vSommet.couleur = 0x000000FF;
        _score++;
        _labyrinthe->getSommetCourant()->v.vSommet.isVisited = true;
    }
}

/////////////// UPDATE ARETE //////////////////
void WorldRenderer::updateArete(){
    PElement<Arete<Peinture, InfoSommet>> * aretes = _labyrinthe->getGraphe().lAretes;
    while(aretes != nullptr){
        if(aretes->valeur->v.devant > 0xFF000000 + 30)
            aretes->valeur->v.devant -= 30;
        aretes = aretes->suivant;
    }
}

