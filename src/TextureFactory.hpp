#ifndef _TEXTUREFACTORY_HPP
#define _TEXTUREFACTORY_HPP

#include "Singleton.hpp"
#include "SFML/Graphics.hpp"
#include "Erreur.hpp"
#include <iostream>
#include <string>
#include <map>

using namespace std;
class TextureFactory : public Singleton<TextureFactory>{
    friend class Singleton<TextureFactory>;
    sf::Texture _pacman, _ghost;
    map<string, sf::Texture> _textures;
private:
    TextureFactory(){
        if (!_pacman.loadFromFile("texture/pacman.png"))
            throw Erreur("impossible de charger pacman");

        if (!_ghost.loadFromFile("texture/ghost.png"))
            throw Erreur("impossible de charger ghost");

        _textures["pacman"] = _pacman;
        _textures["ghost"] = _ghost;
    }
    ~TextureFactory(){}
public:
    const sf::Texture & getTexture(string textureName) const {return _textures.at(textureName);}
};
#endif
