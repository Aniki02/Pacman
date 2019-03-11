#ifndef _TEXTUREFACTORY_HPP
#define _TEXTUREFACTORY_HPP
/**
 * \file TextureFactory.hpp
 * \brief représente la classe qui charge toute les textures
 * \author zitoun-diallo-sid
 */
#include "Singleton.hpp"
#include "SFML/Graphics.hpp"
#include "Erreur.hpp"
#include <iostream>
#include <string>
#include <map>

using namespace std;
class TextureFactory : public Singleton<TextureFactory>{
    friend class Singleton<TextureFactory>;
    sf::Texture _pacman, _ghost, _winner, _loser;
    map<string, sf::Texture> _textures;
private:
    TextureFactory(){
        if (!_pacman.loadFromFile("texture/pacman.png"))
            throw Erreur("impossible de charger pacman");

        if (!_ghost.loadFromFile("texture/ghost.png"))
            throw Erreur("impossible de charger ghost");

        if (!_winner.loadFromFile("texture/winner.png"))
            throw Erreur("impossible de charger winner");

        if (!_loser.loadFromFile("texture/loser.png"))
            throw Erreur("impossible de charger loser");

        _textures["pacman"] = _pacman;
        _textures["ghost"] = _ghost;
        _textures["winner"] = _winner;
        _textures["loser"] = _loser;
    }

    ~TextureFactory(){}
public:
    const sf::Texture & getTexture(string textureName) const {return _textures.at(textureName);}
};
#endif
