#ifndef _GAMESCREEN_HPP
#define _GAMESCREEN_HPP
/**
 * \file GameScreen.hpp
 * \brief représente lecran lorsque le jeux est lancer
 * \author zitoun-diallo-sid
 */


#include "WorldRenderer.hpp"
#include "Game.hpp"

class Screen;
class GameScreen : public Screen{
public:
    WorldRenderer * wr;

    /**
     *  \brief Constructeur
     *
     *  Constructeur de la classe GameScreen
     *
     *  \param window : la fenetre de l'ecran
     */
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
                if(wr->loseGame()){
                    sf::Sprite spriteLoser;
                    spriteLoser.setTexture(TextureFactory::getInstance()->getTexture("loser"));
                    this->_window->fenetre.draw(spriteLoser);
                    
                }else {
                    wr->render(*_window, elapsedTime);
                }
        }

    } 
    
    bool winGame(){return wr->_score >= 49;}
};
#endif