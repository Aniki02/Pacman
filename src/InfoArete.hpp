//#ifndef INFOARETE_H
//#define INFOARETE_H



#pragma once

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

/**

Information associ�e � une ar�te  (segment rectiligne) joignant 2 lieux d'une carte routi�re.

On ne stocke que le c�ut de l'ar�te, c-�-d sa longueur et sa couleur

*/


class InfoArete
{
public:

double cout1;
unsigned int couleur;

/**
Par d�faut, la couleur d'une ar�te est le bleu
*/
explicit InfoArete( const double & cout1, const unsigned int couleur = 0x0000FFFF):cout1(cout1), couleur(couleur){}

operator string() const;
friend ostream & operator << ( ostream & os, const InfoArete & infoArete) { return os << (string) infoArete; }
};

inline InfoArete::operator string() const
{
ostringstream oss;

oss << "cout = " << cout1 << ", " << couleur;

return oss.str();
}

//#endif // INFOARETE_H
