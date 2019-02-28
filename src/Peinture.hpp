#ifndef _PEINTURE_HPP
#define _PEINTURE_HPP

#include <sstream>
#include <iostream>

using namespace std;

class Peinture{
public:
    unsigned int fond;  //Couleur du fond 
    unsigned int devant;    // couleur masquant la couleur du fond
    
    Peinture(const unsigned int couleurFond, const unsigned int couleurDevant) : fond(couleurFond), devant(couleurDevant){}

    virtual operator string () const {
        ostringstream os;
        os << "( " << fond << ", " << devant << ")";
        return os.str();
    }

};

ostream & operator << (ostream & o, const Peinture & p){
    return o << (string) p;
}
#endif