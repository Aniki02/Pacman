#include <iostream>
#include <stdio.h>
#include "TextureFactory.hpp"
#include <SFML/Graphics.hpp>
using namespace std;
int main(){

    sf::RenderWindow window(sf::VideoMode(600, 800), "Test TextureFactory");
    sf::Sprite spritePacman;
    sf::Texture texturePacman;

    texturePacman = TextureFactory::getInstance()->getPacman();
    spritePacman.setTexture(texturePacman);
    spritePacman.setPosition(200, 200);

    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::EventType::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(spritePacman);
        window.display();
    }


    return 0;

}