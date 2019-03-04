#ifndef __ARETE__
#define __ARETE__
    #include "GElement.hpp"
    #include "Sommet.hpp"

    template <class S, class T>
    class Arete : public GElement<S>
    {
        public:
           Sommet<T> *_debut, *_fin; 
        public:
            Arete(const int clef, const S & v, Sommet<T> *debut, Sommet<T> *fin):GElement<S>(clef, v){
                /*Met à jour le degré des sommets que cette nouvelle arête va connecter*/
                _debut = debut;
                    _debut->degre++;
                _fin = fin;
                    _fin->degre++;
            }
           
            operator std::string()const{
                std::ostringstream os;
                os<<this->GElement<S>::operator std::string()
                <<_debut->Sommet<T>::operator std::string()
                <<_fin->Sommet<T>::operator std::string();

                return os.str();
            }
            friend std::ostream& operator<<(std::ostream& o, const Arete<T,S>& a){
                return o<<(std::string)a;
            }
            bool estEgal(const Sommet<T> *s1, const Sommet<T> *s2)const{
                if((_debut==s1 && _fin==s2) || (_debut==s2 && _fin==s1))
                    return true;
                else
                    return false;
            }
            ~Arete(){
                _debut->degre--;
                _fin->degre--;
            }
    };
    
#endif