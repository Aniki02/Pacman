#ifndef __SOMMET__
#define __SOMMET__
/**
 * \file Sommet.hpp
 * \brief représente un sommet generique d'un graphe
 * \author zitoun-diallo-sid
 */
    #include "GElement.hpp"

    template <class T>
    class Sommet : public GElement<T>
    {
        public:
            int degre;
        public:
            Sommet(const int clef,const T v): GElement<T>(clef,v), degre(0){}
            operator std::string()const{
                std::ostringstream os;
                os<<this->GElement<T>::operator std::string()<<"le degre du sommet égale : "
                << degre<<std::endl;
                return os.str();
            }
            friend std::ostream& operator <<(std::ostream& o, const Sommet<T>& s){
                return o<<(std::string)s;
            }
            ~Sommet(){};
    };
    
#endif