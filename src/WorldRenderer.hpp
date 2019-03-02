#ifndef _WORLDRENDERER_HPP
#define _WORLDRENDERER_HPP

#include <SFML/Graphics.hpp>
#include "World.hpp"
#include "TextureFactory.hpp"

class WorldRenderer{
    World * _world;
    sf::Sprite spritePacman, spriteGhost;
public: 
    WorldRenderer(){
        _world = new World();
        spritePacman.setTexture(TextureFactory::getInstance()->getTexture(_world->getPacman()->getName()));
        spriteGhost.setTexture(TextureFactory::getInstance()->getTexture(_world->getGhost()->getName()));
    }
    virtual ~WorldRenderer(){delete _world;}
    void handleInput(sf::Event event);
    void update(sf::Event event);

    template<class FENETRE>
    void render(FENETRE * window){
        window->draw(spritePacman);
        window->draw(spriteGhost);
    }

    void movePacman(sf::Event event);
    void moveGhost(sf::Event event);
};
#endif