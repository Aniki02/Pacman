#ifndef _GAMEELEMENT_HPP
#define _GAMEELEMENT_HPP

#include <string>
#include "Vecteur2D.h"


class GameElement{
    Vecteur2D _position;
    string _name;
protected:
    GameElement(const string & name);
    virtual ~GameElement(){}
public:
    const string & getName() const {return _name;}
    Vecteur2D getPosition() const {return _position;}
    void setPosition(Vecteur2D newPosition);
    void setPosition(float x, float y);

};
#endif