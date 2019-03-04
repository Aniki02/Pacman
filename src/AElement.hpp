#ifndef __AELEMENT__
#define __AELEMENT__
    #include <string>
    #include <ostream>
    #include <sstream>

    class AElement
    {
        public:
            int clef;
            AElement(const int c):clef(c){};
            operator std::string()const{
                std::ostringstream os;
                os<<std::endl<<"la clef de AElement : "<<clef<<std::endl; 
                return os.str();
            }
            friend std::ostream & operator<<(std::ostream &o, const AElement &ae){
                return o<<(std::string)ae;
            }
            ~AElement(){};
    };
#endif