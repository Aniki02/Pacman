#ifndef _CHOIXSOMMET_HPP
#define _CHOIXSOMMET_HPP

#include "Sommet.hpp"
#include "PElement.hpp"
#include "AStarT.hpp"
#include "OutilsCarte.hpp"

template<class T>
class ChoixSommet{

public:

    static Sommet<T> * choixRandom(Graphe<Peinture,T> & graphe, Sommet<T> * sommetCourant){
        //srand(time(0));
        // On recherche les voisins
        PElement<Sommet<InfoSommet> > * voisins = graphe.voisins(sommetCourant);
        int numSommetAlea = rand() % (PElement<Sommet<InfoSommet>>::taille(voisins));
        while(numSommetAlea > 0 && voisins != nullptr){
            voisins = voisins->suivant;
            numSommetAlea--;
        }
        return voisins->valeur;
    }
    
    static Sommet<T> * choixSnake(Graphe<Peinture,T> & graphe, Sommet<T> * sommetCourant){
        // On choisit un sommet aléatoirement
        Sommet<InfoSommet> * sommetChoisi = ChoixSommet<InfoSommet>::choixRandom(graphe, sommetCourant);

        PElement<Sommet<InfoSommet> > * voisins = graphe.voisins(sommetCourant);
        Arete<Peinture, T> * arete = graphe.getAreteParSommets(sommetChoisi, sommetCourant);
        //pour chaque voisins on compare son arete avec la premiere arete choisis et on garde celle qui a la couleur la plus élevé
        while(voisins!= nullptr){
           
            Arete<Peinture, T> * areteVoisin = graphe.getAreteParSommets(voisins->valeur, sommetCourant);
            if(arete->v.devant < areteVoisin->v.devant){
                arete = areteVoisin;
                sommetChoisi = voisins->valeur;
            }
            voisins = voisins->suivant;
        }

        return sommetChoisi;
    }

    static Sommet<T> * choixAStar(Graphe<Peinture,T> & graphe, Sommet<T> * sommetCourant, Sommet<T> * cible){
        Sommet<InfoSommet> * depart = sommetCourant;
        OutilsCarte::cible = cible;

        AStarT< Graphe<Peinture,InfoSommet>,Sommet<InfoSommet> >::aStar1Cible(graphe, depart, cible, OutilsCarte::distance);
        PElement<Sommet<InfoSommet>> * c = chemin(cible, c);
        std::cout << "---------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        

        while(c->suivant != nullptr)
            c = c->suivant;
        std::cout << "---------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << c << std::endl;
        return c->valeur;
    }
};
#endif