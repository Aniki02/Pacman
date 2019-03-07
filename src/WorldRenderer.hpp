#ifndef _WORLDRENDERER_HPP
#define _WORLDRENDERER_HPP

#include <SFML/Graphics.hpp>
#include "World.hpp"
#include "TextureFactory.hpp"
#include "PeutSeDeplacer.hpp"
#include "LevelGenerator.hpp"
#include "VisitorGhostMove.hpp"

class VisitorGhostMove;

using namespace sf;

class WorldRenderer{
public:
    World * _world;
    sf::Sprite spritePacman, spriteGhost;
    LevelGenerator * labyrinthe;
public:
    WorldRenderer(){
        _world = new World();
        spritePacman.setTexture(TextureFactory::getInstance()->getTexture(_world->getPacman()->getName()));
        spriteGhost.setTexture(TextureFactory::getInstance()->getTexture(_world->getGhost()->getName()));

        unsigned int magenta = Color::Magenta.toInteger();		// récupère la couleur Magenta au format nombre entier non signé
        unsigned int turquoise = 0x00CED1FF;	// couleur turquoise opaque. préfixe 0x pour héxadécimal. format RGBA
        unsigned int vertCitron = 0x00FF00FF;
        this->labyrinthe = new LevelGenerator(7,magenta, turquoise, vertCitron);
    }
    virtual ~WorldRenderer(){delete _world;}
    void handleInput(sf::Event event);
    void update(sf::Event event);

    template<class FENETRE>
    void render(FENETRE & window){
        bool ok = labyrinthe->getGraphe()->dessine(window);
        Vecteur2D posPacman = window.t.applique(_world->getPacman()->getPosition());
        spritePacman.setPosition(posPacman.x - TextureFactory::getInstance()->getTexture("pacman").getSize().x / 2, posPacman.y + TextureFactory::getInstance()->getTexture("pacman").getSize().y);
        Vecteur2D posGhost = window.t.applique(_world->getGhost()->getPosition());
        spriteGhost.setPosition(posGhost.x - TextureFactory::getInstance()->getTexture("ghost").getSize().x / 2, posGhost.y + TextureFactory::getInstance()->getTexture("ghost").getSize().y);
        window.fenetre.draw(spritePacman);
        window.fenetre.draw(spriteGhost);
    }

    void movePacman(sf::Event event);
    void moveGhost(sf::Event event);

    void accepteMove(VisitorGhostMove * v){
        v->visite(this);
    }
    private:

        /*void move(Vecteur2D deplacement, PElement<Sommet<VSommet>> * voisins, PeutSeDeplacer & foncteur, void (*fonctMove)() ){
            foncteur.setDeplacement(deplacement);
            PElement<Sommet <VSommet> > * newSommet = PElement<Sommet<VSommet> >::appartient(voisins, foncteur);
            if(newSommet != nullptr){
                fonctMove();
                labyrinthe->setSommetCourant(newSommet->valeur);
            }
        }*/

};
#endif
