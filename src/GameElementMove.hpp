#ifndef _GAMEELEMENTMOVE_HPP
#define _GAMEELEMENTMOVE_HPP


#include "GameElement.hpp"
#include "Constants.hpp"
class GameElementMove : public GameElement{
    int _speed;
protected: 
    GameElementMove(const string & name, int speed):GameElement(name), _speed(speed){}
    virtual ~GameElementMove(){}
public:
   
    void moveNorth(){
        this->setPosition(this->getPosition().x, this->getPosition().y + Constants::step);
    }
    void moveNorthEast(){
        this->setPosition(this->getPosition().x + Constants::step, this->getPosition().y + Constants::step);
    }
    void moveEast(){
        this->setPosition(this->getPosition().x + Constants::step, this->getPosition().y );
    }
    void moveSouthEast(){
        this->setPosition(this->getPosition().x + Constants::step, this->getPosition().y - Constants::step );
    }
    void moveSouth(){
        this->setPosition(this->getPosition().x, this->getPosition().y - Constants::step );
    }
    void moveSouthWest(){
        this->setPosition(this->getPosition().x - Constants::step, this->getPosition().y - Constants::step );
    }
    void moveWest(){
        this->setPosition(this->getPosition().x - Constants::step, this->getPosition().y);
    }
    void moveNorthWest(){
        this->setPosition(this->getPosition().x - Constants::step, this->getPosition().y + Constants::step);
    }

};
#endif