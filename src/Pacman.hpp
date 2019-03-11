#ifndef _PACMAN_HPP
#define _PACMAN_HPP

/**
 * \file Pacman.hpp
 * \brief représente pacman
 * \author zitoun-diallo-sid
 */

#include "GameElementMove.hpp"
class Pacman : public GameElementMove{
public:
    Pacman():GameElementMove("pacman", 1){}
};
#endif