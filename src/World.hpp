#ifndef _WORLD_HPP
#define _WORLD_HPP

#include "GameElement.hpp"
#include "Pacman.hpp"
#include "Ghost.hpp"

class World{
    GameElement * _pacman, * _ghost;
public:
    World(){
        _pacman = new Pacman();
        _ghost = new Ghost();
    }

    GameElement * getPacman() const {return _pacman;}
    GameElement * getGhost() const {return _ghost;}
    
};
#endif