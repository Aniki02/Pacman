#ifndef _GAMEELEMENTMOVE_HPP
#define _GAMEELEMENTMOVE_HPP
/**
 * \file GameElementMove.hpp
 * \brief représente les différent élément du jeux pouvant bouger 
 * \author zitoun-diallo-sid
 */


#include "GameElement.hpp"
#include "Constants.hpp"
class GameElementMove : public GameElement{
    int _speed;
protected: 
    GameElementMove(const string & name, int speed):GameElement(name), _speed(speed){}
    virtual ~GameElementMove(){}
public:
    void move(Vecteur2D direction){this->setPosition(this->getPosition() + direction*_speed);}
};
#endif