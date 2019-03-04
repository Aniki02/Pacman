#ifndef __PEINTURE__
#define __PEINTURE__

    #include <iostream>
    #include <sstream>
    #include <string>

    class Peinture
    {
        public:
           unsigned int fond;
           unsigned int devant;
        public:
            Peinture(const unsigned int f, const unsigned int d):fond(f), devant(d){}

            virtual operator std::string()const{
                std::ostringstream os;
                os<<"( "<<fond<<", "<<devant<<")";

                return os.str();
            }

            friend std::ostream & operator<<(std::ostream &o, const Peinture &p){
                return o<<(std::string)p;
            }
            ~Peinture(){}
    };
    
#endif