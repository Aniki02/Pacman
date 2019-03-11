#ifndef _PEUTSEDEPLACER_HPP
#define _PEUTSEDEPLACER_HPP
/**
 * \file PeutSeDeplacer.hpp
 * \brief représente un predicat qui dis si on peut se deplacer ou non sur un sommet
 * \author zitoun-diallo-sid
 */

#include "Vecteur2D.hpp"
#include "Sommet.hpp"
#include "InfoSommet.hpp"

class PeutSeDeplacer{
public:
    Vecteur2D deplacement, posActuel;
    PeutSeDeplacer(Vecteur2D d, Vecteur2D pa) : deplacement(d), posActuel(pa){}
public: 
    bool operator () ( Sommet<InfoSommet> * sommet) const {return sommet->v.vSommet.pos == deplacement + posActuel; }
    void setDeplacement(Vecteur2D newDeplacement){deplacement = newDeplacement;}
};

#endif