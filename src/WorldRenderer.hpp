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
    float time;
    int  score;

public:
    WorldRenderer();
    virtual ~WorldRenderer(){delete _world;}
    void handleInput(sf::Event event);
    void update(sf::Event event);

    template<class FENETRE, class TIME>
    void render(FENETRE & window, TIME elapsedTime){
            if(_labyrinthe->getGraphe()->dessine(window)){
                time+=elapsedTime.asSeconds();
                this->moveGhost();
                Vecteur2D posPacman = window.t.applique(_world->getPacman()->getPosition());
                Vecteur2D posGhost = window.t.applique(_world->getGhost()->getPosition());
                _spritePacman.setPosition(posPacman.x - TextureFactory::getInstance()->getTexture("pacman").getSize().x / 2, posPacman.y + TextureFactory::getInstance()->getTexture("pacman").getSize().y);
                _spriteGhost.setOrigin(TextureFactory::getInstance()->getTexture("ghost").getSize().x / 2, TextureFactory::getInstance()->getTexture("ghost").getSize().y);
                _spriteGhost.setPosition(posGhost.x, posGhost.y);
                window.fenetre.draw(_spritePacman);
                window.fenetre.draw(_spriteGhost);
            }  
    }
    
    void movePacman(sf::Event event);
    void accepteMove(VisitorGhostMove * v){v->visite(this);}
    void moveGhost();
private:
    void move(Vecteur2D direction, PElement<Sommet<VSommet>> * voisins);
    void updateScore();
    void updateArete();

};
#endif
