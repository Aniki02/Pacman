#ifndef _WORLDRENDERER_HPP
#define _WORLDRENDERER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "World.hpp"
#include "TextureFactory.hpp"
#include "PeutSeDeplacer.hpp"
#include "LevelGenerator.hpp"
#include "RandomMove.hpp"
#include "VisitorGhostMove.hpp"


class VisitorGhostMove;

using namespace sf;

class WorldRenderer{
public:

    World * _world;
    sf::Sprite _spritePacman, _spriteGhost;
    LevelGenerator * _labyrinthe;
public:
    WorldRenderer();
    virtual ~WorldRenderer(){delete _world;}
    void handleInput(sf::Event event);
    void update(sf::Event event);

    template<class FENETRE>
    void render(FENETRE & window){
        if(_labyrinthe->getGraphe()->dessine(window) && _labyrinthe->getPacGomme()->dessineToutSommets(window)){
           
            Vecteur2D posPacman = window.t.applique(_world->getPacman()->getPosition());
            _spritePacman.setPosition(posPacman.x - TextureFactory::getInstance()->getTexture("pacman").getSize().x / 2, posPacman.y + TextureFactory::getInstance()->getTexture("pacman").getSize().y);
            Vecteur2D posGhost = window.t.applique(_world->getGhost()->getPosition());
            _spriteGhost.setPosition(posGhost.x - TextureFactory::getInstance()->getTexture("ghost").getSize().x / 2, posGhost.y + TextureFactory::getInstance()->getTexture("ghost").getSize().y);
            window.fenetre.draw(_spritePacman);
            window.fenetre.draw(_spriteGhost);
        }
    }
    
    void movePacman(sf::Event event);
    void accepteMove(VisitorGhostMove * v){v->visite(this);}
private:
    void move(Vecteur2D direction, PElement<Sommet<VSommet>> * voisins);

};
#endif
