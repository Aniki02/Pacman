#ifndef _WORLD_HPP
#define _WORLD_HPP

#include "GameElement.hpp"
#include "Pacman.hpp"
#include "Ghost.hpp"

class World{
    Pacman * _pacman; 
    Ghost * _ghost;
public:
    World(){
        _pacman = new Pacman();
        _ghost = new Ghost();
        
    }

    Pacman * getPacman() const {return _pacman;}
    Ghost * getGhost() const {return _ghost;}
    
};
#endif