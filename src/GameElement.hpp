#ifndef _GAMEELEMENT_HPP
#define _GAMEELEMENT_HPP
/**
 * \file GameElement.hpp
 * \brief représente les différent élément du jeux
 * \author zitoun-diallo-sid
 */

#include <string>
#include "Vecteur2D.hpp"


class GameElement{
    Vecteur2D _position;
    string _name;
protected:
    /**
     *  \brief Constructeur
     *
     *  Constructeur de la classe GameElement
     *
     *  \param name : nom du GameElement
     */
    GameElement(const string & name);
    virtual ~GameElement(){}
public:
    const string & getName() const {return _name;}
    Vecteur2D getPosition() const {return _position;}
    void setPosition(Vecteur2D newPosition);
    void setPosition(float x, float y);

};
#endif