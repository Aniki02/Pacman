#pragma once
/**
 * \file InfoSommet.hpp
 * \brief représente les informations d'un sommet
 * \author zitoun-diallo-sid
 */

#include "InfoAStar.hpp"
#include "VSommet.hpp"

/**

Information associ�e � un lieu (donc un sommet) d'une carte g�ographique pour laquelle on veut faire "tourner" A*

*/

using namespace std;
class InfoSommet
{
public:
VSommet vSommet;
InfoAStar infoAStar;

InfoSommet( const VSommet & vSommet, const InfoAStar & infoAStar) : vSommet(vSommet), infoAStar(infoAStar){}

operator string() const { ostringstream oss; oss << vSommet << endl; oss << infoAStar; return oss.str(); }

friend ostream & operator <<( ostream & os, const InfoSommet & infoSommet) { return os << (string)infoSommet; }
};




