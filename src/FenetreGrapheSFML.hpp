#ifndef _FENETREGRAPHESFML_HPP
#define _FENETREGRAPHESFML_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "TransfoAffine2D.h"
#include "VSommet.hpp"
#include "Sommet.hpp"
#include "Arete.hpp"
#include "Peinture.hpp"

class FenetreGrapheSFML{
public:
    sf::RenderWindow fenetre;
    const sf::Font & font;

    TransfoAffine2D t;  //réalise le passage fenetre-cloture
                        // ( ou encore monde vers écran)
    /**
    Crée la fenêtre qui va contenir le dessin du graphe.

    DONNEES : titre : titre de la fenêtre
            fondCarte : couleur du fond de la scène au format RGBA
            coinBG : coin Bas Gauche de la scène en coordonnées monde
            coinHD : coin Haut Droit de la scène en coordonnées monde
            largeur : largeur de la fenêtre écran (en pixels)
            hauteur : hauteur de la fenêtre écran (en pixels)
            font : police à utiliser pour les annotations sur les sommets

    */
    FenetreGrapheSFML( const string & titre, 
                const unsigned int fondCarte,
                const Vecteur2D & coinBG, 
                const Vecteur2D & coinHD,
                const int largeur, 
                const int hauteur, 
                const sf::Font & font): fenetre(sf::VideoMode(largeur,hauteur), titre), font(font)
    {
        fenetre.clear(sf::Color(fondCarte));
        // calcul de la transformation affine - changement de repère : monde ---> écran
        Vecteur2D coinEcranBG(0,hauteur), coinEcranHD(largeur,0);

        t = TransfoAffine2D::passageMondeEcran(coinBG,coinHD,
                                    coinEcranBG,coinEcranHD);
    }

    /**
    Dessine un sommet du graphe. Exemples :  nom, couleur, informations associées, etc.
    renvoie true en cas de succès, false en cas d'échec
    On suppose que les coordonnées du sommet sont définies par rapport au repère du monde
    */
    template <class T>
    bool dessine(const Sommet<T> * sommet);

    /**
    Dessine l'arête (début->fin) en utilisant la couleur "couleur"
    renvoie true en cas de succès, false en cas d'échec
    On suppose que les coordonnées des sommets sont définies par rapport au repère du monde
    */
    template <class T>
    bool dessine(const Sommet<T> * debut, const Sommet<T> * fin, unsigned int couleur);

    /**
    Dessine un arête du graphe. Exemples :  nom, couleur, informations associées, etc.
    renvoie true en cas de succès, false en cas d'échec
    On suppose que les coordonnées des sommets sont définies par rapport au repère du monde
    */
    template <class S, class T>
    bool dessine(const Arete<S,T> * arete) ;

};

template<>
bool FenetreGrapheSFML::dessine<VSommet>(const Sommet<VSommet> * sommet){
    return false;
}

template <>
bool FenetreGrapheSFML::dessine<Peinture, VSommet>(const Arete<Peinture, VSommet> * arete){
    return false;
}


#endif