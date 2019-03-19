#ifndef _GAME_HPP
#define _GAME_HPP
/**
 * \file Game.hpp
 * \brief représente le jeux
 * \author zitoun-diallo-sid
 */

#include "FaxeRepereMonde.hpp"
#include "Vecteur2D.hpp"
#include "Screen.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Color.hpp"

class Game{
public:

    FaxeRepereMonde * _window;
    Screen * _screen = nullptr;

public:
    /**
     *  \brief Constructeur
     *
     *  Constructeur de la classe Game
     */
    Game(){
        _window = new FaxeRepereMonde("Pacman", 0xEFEFEFFF, Vecteur2D(-1, -1), Vecteur2D(9,9), 800, 500);
    }
    Screen * getScreen() const{return _screen;}
    void setScreen(Screen * newScreen){_screen = newScreen;}

    ~Game(){
        delete _window;
        delete _screen;

        _window = nullptr;
        _screen = nullptr;
    }
    void run(){
        sf::Clock clock;
        while (_window->fenetre.isOpen()){
            sf::Event event;
            sf::Time elapsedTime = clock.restart();
            while(_window->fenetre.pollEvent(event)){
                _screen->update(event);
                
                if(event.type == sf::Event::EventType::Closed)
                    _window->fenetre.close();
            }

            _window->fenetre.clear(sf::Color::Black);
            _screen->render(elapsedTime);
            _window->fenetre.display();
        }
    }
    

};
#endif