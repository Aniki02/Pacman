
#include <stdio.h>
#include <string>
#include "SFML/Graphics.hpp"
#include "GameElement.hpp"
#include "GameElementMove.hpp"
#include "Pacman.hpp"
#include "Ghost.hpp"
#include "TextureFactory.hpp"

int main(){
    sf::RenderWindow window(sf::VideoMode(600, 800), "TestWorld");
    Pacman * pacman = new Pacman();
    Ghost * ghost = new Ghost();
    
    sf::Sprite spritePacman, spriteGhost;
    spritePacman.setTexture(TextureFactory::getInstance()->getTexture(pacman->getName()));
    spritePacman.setPosition(100, 100);
    spriteGhost.setTexture(TextureFactory::getInstance()->getTexture(ghost->getName()));
    spriteGhost.setPosition(200, 200);


    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){

            if(event.type == sf::Event::EventType::KeyPressed){
                if(event.key.code == sf::Keyboard::A)
                    pacman->moveNorthWest();
                if(event.key.code == sf::Keyboard::Z)
                    pacman->moveNorth();
                if(event.key.code == sf::Keyboard::E)
                    pacman->moveNorthEast();
                if(event.key.code == sf::Keyboard::D)
                    pacman->moveEast();
                if(event.key.code == sf::Keyboard::C)
                    pacman->moveSouthEast();
                if(event.key.code == sf::Keyboard::X)
                    pacman->moveSouth();
                if(event.key.code == sf::Keyboard::W)
                    pacman->moveSouthWest();
                if(event.key.code == sf::Keyboard::Q)
                    pacman->moveWest();

            }
            if(event.type == sf::Event::EventType::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        spritePacman.setPosition(pacman->getPosition().x, pacman->getPosition().y);
        window.draw(spritePacman);
        window.draw(spriteGhost);
        window.display();
    }
    return 0;
}