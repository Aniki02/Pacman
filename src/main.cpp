
#include <stdio.h>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Color.hpp"
#include "GameElement.hpp"
#include "GameElementMove.hpp"
#include "Pacman.hpp"
#include "Ghost.hpp"
#include "TextureFactory.hpp"
#include "WorldRenderer.hpp"
#include "LevelGenerator.hpp"
#include "FaxeRepereMonde.hpp"

using namespace sf;
int main(){
    WorldRenderer * wr = new WorldRenderer();
    

    unsigned int magenta = Color::Magenta.toInteger();		// récupère la couleur Magenta au format nombre entier non signé
    unsigned int turquoise = 0x00CED1FF;	// couleur turquoise opaque. préfixe 0x pour héxadécimal. format RGBA
    unsigned int vertCitron = 0x00FF00FF;
   
    //creation de labyrinthe
    LevelGenerator *lab  = new LevelGenerator(7,magenta, turquoise, vertCitron);

    string titre("Labyrinthe");
    int largeur = 800, hauteur = 500;
    //Vecteur2D  coinBG(0,hauteur), coinHD(largeur,0);

    Vecteur2D  coinBG(-1, -1), coinHD(9,9);

    unsigned int fondCarte = 0xEFEFEFFF;	// sorte de gris clair ~= étain pur
    
    FaxeRepereMonde fenetreGraphe( titre, fondCarte, coinBG, coinHD, largeur, hauteur);


    while (fenetreGraphe.fenetre.isOpen()){
        sf::Event event;
        while(fenetreGraphe.fenetre.pollEvent(event)){
            wr->update(event);
            if(event.type == sf::Event::EventType::Closed)
                fenetreGraphe.fenetre.close();
        }

        fenetreGraphe.fenetre.clear(sf::Color::Black);
        bool ok = lab->getGraphe()->dessine(fenetreGraphe);
        wr->render(&fenetreGraphe.fenetre);
        fenetreGraphe.fenetre.display();
    }
    return 0;
}