#ifndef _PACMAN_HPP
#define _PACMAN_HPP


#include "GameElementMove.hpp"
class Pacman : public GameElementMove{
public:
    Pacman():GameElementMove("pacman", 1){}
};
#endif