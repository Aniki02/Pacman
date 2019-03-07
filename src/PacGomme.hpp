#ifndef __PACGOMME__
#define __PACGOMME__

    #include "Vecteur2D.hpp"
    #include <string>
    #include <iostream>

    class PacGomme
    {
       public:
            constexpr static int rayonDisquePixel = 5;
            constexpr static unsigned int couleurBord = 0xFFFFFF; //couleur violine opaque
            int number;
            unsigned int couleur; //format rgba
            Vecteur2D pos; //position 0 : posX; 1 : posY
        public:
            PacGomme(const int num, const Vecteur2D & p, const unsigned int couleur = 0xFFFFFF):
            number(num), couleur(couleur), pos(p){}

            virtual operator std::string()const{
                std::ostringstream os;
                os<<"( "<<number<<", "<<pos<<", "<<couleur<< ")";
                return os.str();
            }
            
            friend std::ostream & operator <<(std::ostream &o, const PacGomme & vs){
                return o<<(std::string)vs;
            }
            virtual ~PacGomme(){}
    };
    
#endif