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
    int time, score;

public:
    WorldRenderer();
    virtual ~WorldRenderer(){delete _world;}
    void handleInput(sf::Event event);
    void update(sf::Event event);

    template<class FENETRE>
    void render(FENETRE & window){
        if (score >= 49){
            sf::Sprite spriteWinner;
            spriteWinner.setTexture(TextureFactory::getInstance()->getTexture("winner"));
            window.fenetre.draw(spriteWinner);
        }else
        {
            if(_labyrinthe->getGraphe()->dessine(window)){
                time++;
                this->moveGhost();
                Vecteur2D posPacman = window.t.applique(_world->getPacman()->getPosition());
                _spritePacman.setPosition(posPacman.x - TextureFactory::getInstance()->getTexture("pacman").getSize().x / 2, posPacman.y + TextureFactory::getInstance()->getTexture("pacman").getSize().y);
                Vecteur2D posGhost = window.t.applique(_world->getGhost()->getPosition());
                _spriteGhost.setOrigin(TextureFactory::getInstance()->getTexture("ghost").getSize().x / 2, TextureFactory::getInstance()->getTexture("ghost").getSize().y);
                //_spriteGhost.setPosition(posGhost.x - TextureFactory::getInstance()->getTexture("ghost").getSize().x / 2, posGhost.y + TextureFactory::getInstance()->getTexture("ghost").getSize().y);
                _spriteGhost.setPosition(posGhost.x, posGhost.y);
                window.fenetre.draw(_spritePacman);
                window.fenetre.draw(_spriteGhost);
            }
        }
        
        
    }
    
    void movePacman(sf::Event event);
    void accepteMove(VisitorGhostMove * v){v->visite(this);}
    void moveGhost();
private:
    void move(Vecteur2D direction, PElement<Sommet<VSommet>> * voisins);

};
#endif
