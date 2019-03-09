#ifndef _GAMESCREEN_HPP
#define _GAMESCREEN_HPP


#include "WorldRenderer.hpp"
#include "Game.hpp"

class Screen;
class GameScreen : public Screen{
public:
    WorldRenderer * wr;

    GameScreen(FaxeRepereMonde * window):Screen(window){
        wr = new WorldRenderer();
    }

    void update(sf::Event event){wr->update(event);}
    void render(sf::Time elapsedTime){
        if(this->winGame()){
            sf::Sprite spriteWinner;
            spriteWinner.setTexture(TextureFactory::getInstance()->getTexture("winner"));
            this->_window->fenetre.draw(spriteWinner);
        }else{
            wr->render(*_window, elapsedTime);}
        } 
    bool winGame(){return wr->score >= 49;}
};
#endif