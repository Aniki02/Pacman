#ifndef _GHOST_HPP
#define _GHOST_HPP


#include "GameElementMove.hpp"
class Ghost : public GameElementMove{
public:
    Ghost():GameElementMove("ghost", 1){}
};
#endif