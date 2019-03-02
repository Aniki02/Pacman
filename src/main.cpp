
#include <stdio.h>
#include <string>
#include "SFML/Graphics.hpp"
#include "GameElement.hpp"
#include "GameElementMove.hpp"
#include "Pacman.hpp"
#include "Ghost.hpp"
#include "TextureFactory.hpp"
#include "WorldRenderer.hpp"

int main(){
    sf::RenderWindow window(sf::VideoMode(600, 800), "TestWorldRenderer");
    WorldRenderer * wr = new WorldRenderer();
    


    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            wr->update(event);
            if(event.type == sf::Event::EventType::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        wr->render(&window);
        window.display();
    }
    return 0;
}