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
    sf::Texture _pacman, _ghost, _winner;
    map<string, sf::Texture> _textures;
private:
    TextureFactory(){
        if (!_pacman.loadFromFile("texture/pacman.png"))
            throw Erreur("impossible de charger pacman");

        if (!_ghost.loadFromFile("texture/ghost.png"))
            throw Erreur("impossible de charger ghost");

        if (!_winner.loadFromFile("texture/winner.png"))
            throw Erreur("impossible de charger winner");

        _textures["pacman"] = _pacman;
        _textures["ghost"] = _ghost;
        _textures["winner"] = _winner;
    }
    
    ~TextureFactory(){}
public:
    const sf::Texture & getTexture(string textureName) const {return _textures.at(textureName);}
};
#endif
