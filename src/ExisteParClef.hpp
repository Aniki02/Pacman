#ifndef __EXISTEPARCLEF__
#define __EXISTEPARCLEF__
    #include "Sommet.hpp"

    template<class T>
    class ExisteParClef
    {
    private:
        const Sommet<T> *sommet;
    public:
        ExisteParClef(const Sommet<T> *s){
            this->sommet = s;
        }
        bool operator()(const Sommet<T> *s)const{
            return this->sommet->clef == s->clef;
        }
        ~ExisteParClef(){}
    };
    
#endif