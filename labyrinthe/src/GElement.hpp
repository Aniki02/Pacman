#ifndef __GELEMENT__
#define __GELEMENT__
    #include <string>
    #include <ostream>
    #include <sstream>

    #include "AElement.hpp"
    template<class T>
    class GElement : public AElement
    {
    
        public:
            T v;
            GElement<T>(const int clef, const T val):AElement(clef),v(val){};
            operator std::string()const{
                std::ostringstream os;
                os<<this->AElement::operator std::string()<<std::endl<<"La valeur GElement : "
                <<v<<std::endl;
                return os.str();
            }
            friend std::ostream & operator <<(std::ostream &o, const GElement<T> &ge){
                return o<<(std::string)ge;
            }
            ~GElement(){};
    };
#endif