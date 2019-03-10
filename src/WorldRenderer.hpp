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
    float _time;
    int  _score, _nbVie;
    

public:
    WorldRenderer();
    virtual ~WorldRenderer(){delete _world;}
    void handleInput(sf::Event event);
    void update(sf::Event event);

    template<class FENETRE, class TIME>
    void render(FENETRE & window, TIME elapsedTime){
        if(_labyrinthe->getGraphe()->dessine(window)){
            _time+=elapsedTime.asSeconds();
            this->moveGhost();

            Vecteur2D posPacman = window.t.applique(_world->getPacman()->getPosition());
            Vecteur2D posGhost = window.t.applique(_world->getGhost()->getPosition());

            _spritePacman.setPosition(posPacman.x - TextureFactory::getInstance()->getTexture("pacman").getSize().x / 2, posPacman.y - TextureFactory::getInstance()->getTexture("pacman").getSize().y/2);
            _spriteGhost.setOrigin(TextureFactory::getInstance()->getTexture("ghost").getSize().x / 2, TextureFactory::getInstance()->getTexture("ghost").getSize().y/2);
            _spriteGhost.setPosition(posGhost.x, posGhost.y);

            
            this->displayInfoGame(window);
            window.fenetre.draw(_spritePacman);
            window.fenetre.draw(_spriteGhost);
        }  
    }
    
    void movePacman(sf::Event event);
    void accepteMove(VisitorGhostMove * v){v->visite(this);}
    void moveGhost();
    bool loseGame(){
        
        if(_spritePacman.getGlobalBounds().intersects(_spriteGhost.getGlobalBounds())){
            if(_nbVie > 1){
                std::cout << "nombre de vie avant : " << _nbVie << std::endl;
                _nbVie--;
                std::cout << "nombre de vie apres : " << _nbVie << std::endl;
                _labyrinthe->initSommet();
                _spritePacman.setPosition(100,0);
                _spriteGhost.setPosition(300,300);
                _world->getGhost()->setPosition(_labyrinthe->getSommetGhost()->v.pos);
                _world->getPacman()->setPosition(_labyrinthe->getSommetCourant()->v.pos);
                return false;
            }
            return true;
        }
        return false;
        
    }
private:
    void move(Vecteur2D direction, PElement<Sommet<VSommet>> * voisins);
    void updateScore();
    void updateArete();
    template<class FENETRE>
    void displayInfoGame(FENETRE & window){
        // INFO VIE
        sf::Text texteVie, texteScore;
        sf::Font font;
        std::stringstream ss1;
        ss1 << "Vie : " << _nbVie;
        std::string s = ss1.str();
        font.loadFromFile("font/arial.ttf");
        texteVie.setString(s);
        texteVie.setPosition(0,0);
        texteVie.setCharacterSize(30);
        texteVie.setFont(font);
        texteVie.setFillColor(sf::Color::White);

        // INFO SCORE
        std::stringstream ss2;
        ss2 << "Score : " << _score;
        std::string s1 = ss2.str();
        font.loadFromFile("font/arial.ttf");
        texteScore.setString(s1);
        texteScore.setPosition(0,35);
        texteScore.setCharacterSize(30);
        texteScore.setFont(font);
        texteScore.setFillColor(sf::Color::White);

        
        window.fenetre.draw(texteVie);
        window.fenetre.draw(texteScore);
    }

};
#endif
