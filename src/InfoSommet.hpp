#pragma once
#include    "VSommet.hpp"
#include    "Peinture.hpp"
#include    "InfoAStar.hpp"

/**

Information associée à un lieu (donc un sommet) d'une carte géographique pour laquelle on veut faire "tourner" A*

*/

class InfoSommet
{
    public:
    VSommet vSommet;
    InfoAStar infoAStar;

    InfoSommet( const VSommet & vSommet, const InfoAStar & infoAStar) : vSommet(vSommet), infoAStar(infoAStar){}

    operator string() const { ostringstream oss; oss << vSommet << endl; oss << infoAStar; return oss.str(); }

    friend ostream & operator <<( ostream & os, const InfoSommet & infoSommet) { return os << (string)infoSommet; }
};




