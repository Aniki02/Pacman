#include "WorldRenderer.hpp"

void WorldRenderer::handleInput(sf::Event event){
    this->movePacman(event);
}
void WorldRenderer::update(sf::Event event){
    this->handleInput(event);
}



void WorldRenderer::movePacman(sf::Event event){
        if(event.type == sf::Event::EventType::KeyPressed){
        if(event.key.code == sf::Keyboard::A)
            _world->getPacman()->moveNorthWest();
        if(event.key.code == sf::Keyboard::Z)
            _world->getPacman()->moveNorth();
        if(event.key.code == sf::Keyboard::E)
            _world->getPacman()->moveNorthEast();
        if(event.key.code == sf::Keyboard::D)
            _world->getPacman()->moveEast();
        if(event.key.code == sf::Keyboard::C)
            _world->getPacman()->moveSouthEast();
        if(event.key.code == sf::Keyboard::X)
            _world->getPacman()->moveSouth();
        if(event.key.code == sf::Keyboard::W)
            _world->getPacman()->moveSouthWest();
        if(event.key.code == sf::Keyboard::Q)
            _world->getPacman()->moveWest();

        this->spritePacman.setPosition(_world->getPacman()->getPosition().x, _world->getPacman()->getPosition().y);
    }
}
void WorldRenderer::moveGhost(sf::Event event){

}