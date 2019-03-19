#ifndef _GHOST_HPP
#define _GHOST_HPP
/**
 * \file Ghost.hpp
 * \brief représente un ghost
 * \author zitoun-diallo-sid
 */


#include "GameElementMove.hpp"
class Ghost : public GameElementMove{
public:
    /**
     *  \brief Constructeur
     *
     *  Constructeur de la classe GameElementMove
     */
    Ghost():GameElementMove("ghost", 1){}
    ~Ghost(){}
};
#endif