    #include <iostream>
    #include <sstream>
    #include <string>
    #include <vector>

    #include <SFML/Graphics/Color.hpp>
    #include <SFML/Graphics/RenderWindow.hpp>
    #include <SFML/Graphics/VertexArray.hpp>
    #include <SFML/Window/Event.hpp>
    #include <SFML/Window/Mouse.hpp>
    #include <SFML/Graphics/Font.hpp>

    #include "Graphe.hpp"
    #include "FenetreGrapheSFML.hpp"
    #include "FaxeRepereMonde.hpp"
    #include "VSommet.hpp"
    #include "Peinture.hpp"
    #include "LevelGenerator.hpp"
    using namespace std;
    using namespace sf;
int main(){     

    Font font1, font2;
    string nomFichierFonte1 = "../mespolices/abaddon.ttf";
    string nomFichierFonte2 = "../mespolices/ActionManBoldItalic.ttf";
    bool ok = font1.loadFromFile(nomFichierFonte1);
    ok = font2.loadFromFile(nomFichierFonte2);

    char ch;
    unsigned int magenta = Color::Magenta.toInteger();		// récupère la couleur Magenta au format nombre entier non signé
    	// création à vide
    

    unsigned int jaune0 = 0xDFFF00FF;   // jaune opaque
    unsigned int jaune1 = 0xDFFF00C0;   // jaune presque opaque
    unsigned int jaune2 = 0xDFFF0064;   // jaune un peu transparent
    unsigned int jaune3 = 0xDFFF0020;	// jaune presque transparent

    unsigned int tangerine0 = 0xFF7F00FF; // tangerine opaque
    unsigned int tangerine1 = 0xFF7F00DF; // tangerine presque opaque
    unsigned int tangerine2 = 0xFF7F00BF; // tangerine un peu transparent
    unsigned int tangerine3 = 0xFF7F0060; // tangerine presque transparent
    unsigned int tangerine4 = 0xFF7F0000; // tangerine  transparent
    

    //unsigned int jauneOpaque

    unsigned int turquoise = 0x00CED1FF;	// couleur turquoise opaque. préfixe 0x pour héxadécimal. format RGBA
    unsigned int vertCitron = 0x00FF00FF;
    //creation de labyrinthe
    Graphe<Peinture,VSommet> *g1;
    LevelGenerator *lab  = new LevelGenerator(7,magenta, turquoise, vertCitron);
    //------------------ on dessine le graphe ----------------
    g1 = lab->getGraphe();
    cout <<"le graphe créé g1 est :" << endl << *g1 << endl;
    cout<<"**********************************************"<<endl;
    cout<<"tapez une touche + entrer"<<endl;
    cin>>ch;

    string titre("Labyrinthe");
    int largeur = 800, hauteur = 500;
    //Vecteur2D  coinBG(0,hauteur), coinHD(largeur,0);

    Vecteur2D  coinBG(-1, -1), coinHD(9,9);

    unsigned int fondCarte = 0xEFEFEFFF;	// sorte de gris clair ~= étain pur
    
    //FenetreGrapheSFML fenetreGraphe( titre, fondCarte, coinBG, coinHD, largeur, hauteur, font1);
    FaxeRepereMonde fenetreGraphe( titre, fondCarte, coinBG, coinHD, largeur, hauteur, font1, font2);
    ok = g1->dessine(fenetreGraphe);
    cout <<"graphe dessiné ? "  << (ok  ? "succès":"échec") << endl;
    fenetreGraphe.fenetre.display();

    //boucle infinie de contrôle des évènements de la fenêtre
    while( fenetreGraphe.fenetre.isOpen())
        {
        Event event;
        while(fenetreGraphe.fenetre.pollEvent(event))
            {

            if (event.type == Event::Closed) /*(event.type == Event::EventType::Closed)*/
                fenetreGraphe.fenetre.close();
            }

        }
            return 0;
        
}