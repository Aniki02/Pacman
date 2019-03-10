#ifndef _CHOIXSOMMET_HPP
#define _CHOIXSOMMET_HPP

#include "Sommet.hpp"
#include "PElement.hpp"

template<class T>
class ChoixSommet{

public:

    static Sommet<T> * choixRandom(Graphe<Peinture,T> * graphe, Sommet<T> * sommetCourant){
        //srand(time(0));
        // On recherche les voisins
        PElement<Sommet<VSommet> > * voisins = graphe->voisins(sommetCourant);
        int numSommetAlea = rand() % (PElement<Sommet<VSommet>>::taille(voisins));
        while(numSommetAlea > 0 && voisins != nullptr){
            voisins = voisins->suivant;
            numSommetAlea--;
        }
        return voisins->valeur;
    }
    
    static Sommet<T> * choixSnake(Graphe<Peinture,T> * graphe, Sommet<T> * sommetCourant){
        // On choisit un sommet aléatoirement
        Sommet<VSommet> * sommetChoisi = ChoixSommet<VSommet>::choixRandom(graphe, sommetCourant);

        PElement<Sommet<VSommet> > * voisins = graphe->voisins(sommetCourant);
        Arete<Peinture, T> * arete = graphe->getAreteParSommets(sommetChoisi, sommetCourant);
        //pour chaque voisins on compare son arete avec la premiere arete choisis et on garde celle qui a la couleur la plus élevé
        while(voisins!= nullptr){
           
            Arete<Peinture, T> * areteVoisin = graphe->getAreteParSommets(voisins->valeur, sommetCourant);
            if(arete->v.devant < areteVoisin->v.devant){
                arete = areteVoisin;
                sommetChoisi = voisins->valeur;
            }
            voisins = voisins->suivant;
        }

        return sommetChoisi;
    }

    static Sommet<T> * choixAStar(Graphe<Peinture,T> graphe, Sommet<T> sommetCourant){}
};
#endif