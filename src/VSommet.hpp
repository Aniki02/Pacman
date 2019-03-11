#ifndef __VSOMMET__
#define __VSOMMET__

/**
 * \file VSommet.hpp
 * \brief représente les valeur d'un sommet
 * \author zitoun-diallo-sid
 */
    #include <string>
    #include <iostream>
    #include <sstream>
    #include <SFML/Graphics/Color.hpp>
    #include "Vecteur2D.hpp"

    class VSommet
    {
        public:
            constexpr static int rayonDisquePixel = 10;
            constexpr static unsigned int couleurBord = 0xA10684FF; //couleur violine opaque
            std::string nom;
            unsigned int couleur; //format rgba
            Vecteur2D pos; //position 0 : posX; 1 : posY
            bool isVisited;
        public:
            VSommet(const std::string & nom, const Vecteur2D & p, const unsigned int couleur = 0xFF0000FF):
            nom(nom), couleur(couleur), pos(p), isVisited(false){}

            virtual operator std::string()const{
                std::ostringstream os;
                os<<"( "<<nom<<", "<<pos<<", "<<couleur<< ")";
                return os.str();
            }
            
            friend std::ostream & operator <<(std::ostream &o, const VSommet & vs){
                return o<<(std::string)vs;
            }
            virtual ~VSommet(){}
    };
    
#endif