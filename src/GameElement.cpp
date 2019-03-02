#include "GameElement.hpp"
#include "Erreur.hpp"

GameElement::GameElement(const string & name){
    if (name == "") throw Erreur("Nom vide");
    _name = name;
    _position = Vecteur2D(0,0);
}

void GameElement::setPosition(Vecteur2D newPosition){
    _position = newPosition;
}
void GameElement::setPosition(float x, float y){
    _position = Vecteur2D(x, y);
}