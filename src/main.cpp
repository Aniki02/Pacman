
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
#include "FaxeRepereMonde.hpp"
#include "RandomMove.hpp"

using namespace sf;
int main(){
    WorldRenderer * wr = new WorldRenderer();


    string titre("Labyrinthe");
    int largeur = 800, hauteur = 500;
    Vecteur2D  coinBG(-1, -1), coinHD(9,9);
    unsigned int fondCarte = 0xEFEFEFFF;	// sorte de gris clair ~= étain pur
    PElement< Sommet<VSommet> > * voisins = wr->labyrinthe->getGraphe()->voisins(wr->labyrinthe->getSommetCourant());
    FaxeRepereMonde fenetreGraphe( titre, fondCarte, coinBG, coinHD, largeur, hauteur);
     VisitorGhostMove * visiteur = new RandomMove();

    while (fenetreGraphe.fenetre.isOpen()){
        sf::Event event;

        while(fenetreGraphe.fenetre.pollEvent(event)){
            wr->update(event);
            wr->accepteMove(visiteur);
            if(event.type == sf::Event::EventType::Closed)
                fenetreGraphe.fenetre.close();
        }

        fenetreGraphe.fenetre.clear(sf::Color::Black);
        wr->render(fenetreGraphe);
        fenetreGraphe.fenetre.display();
    }
    return 0;
}
