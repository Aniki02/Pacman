#ifndef _SCREEN_HPP
#define _SCREEN_HPP

#include "SFML/Graphics.hpp"
#include "Game.hpp"


class Screen{
protected:
    FaxeRepereMonde * _window;
    Screen(FaxeRepereMonde * window):_window(window){}
public:
    
    virtual void update(sf::Event event) = 0;
    virtual void render(sf::Time elapsedTime) = 0;

};
#endif