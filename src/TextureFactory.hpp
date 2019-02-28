#ifndef _TEXTUREFACTORY_HPP
#define _TEXTUREFACTORY_HPP

#include "Singleton.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

class TextureFactory : public Singleton<TextureFactory>{
    friend class Singleton<TextureFactory>;
    sf::Texture pacman;
private: 
    TextureFactory(){
        if (!pacman.loadFromFile("texture/pacman.png"))
            std::cout << "impossible de charger pacman" << std::endl;
    }
    ~TextureFactory(){}
public:
    const sf::Texture & getPacman() const {return pacman;}
};
#endif