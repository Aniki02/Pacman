#ifndef _SINGLETON_HPP
#define _SINGLETON_HPP

#include <iostream>

/////////////////////////////////////////////////////////////////////////////
//
// Singleton - modèle Singleton applicable à n'importe quelle classe.
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
class Singleton {
    //Unique instance
    static T * _singleton;
protected:
    Singleton(){}
    ~Singleton(){std::cout << "detroying singleton" << std::endl;}
public:
    static T * getInstance(){
        if(_singleton == nullptr)
            _singleton = new T;
        return _singleton;
    }

    static void kill(){
        if(_singleton != nullptr)
            delete _singleton;
            _singleton = nullptr;
    }
};
template<class T>
T * Singleton<T>::_singleton = nullptr;
#endif