#ifndef __ASTAR__
#define __ASTAR__
    #include <utility>
    #include "PElement.hpp"

    template<class Graphe, class Sommet>
    class AStar
    {
        
        public:
            static Sommet *aStar(Graphe & graphe, Sommet *depart, double(*hh)(const Sommet * s));
            static void miseAJourVoisin(Sommet * v, Sommet * s, const double & nouveauCout, PElement<Sommet> * & Ouverts);
            static bool aStar1Cible(Graphe & graphe, Sommet * depart, Sommet * cible, double (*hh)(const Sommet * s1, const Sommet * s2));

            static bool estPlusPetitOuEgal(const Sommet * sommet1, const Sommet * sommet2)
            {
                return g(sommet1) <= g(sommet2);
            }
            ~AStar();
    };
    template<class Graphe, class Sommet>
    Sommet * AStar<Graphe, Sommet>::aStar(Graphe & graphe, Sommet *depart, double(*hh)(const Sommet * s))
    {
        libereToutSommet(graphe);
        PElement<Sommet> * Ouverts;

        pere(depart) = nullptr; c(depart) = 0;

        Ouverts = new PElement<Sommet>(nullptr, depart); etat(depart) = OUVERT;
        while(Ouverts)
        {
            Sommet  * s =PElement<Sommet>::depiler(Ouverts); etat(s) = FERME;
            if (estFinal(s)) { PElement<Sommet>::efface1(Ouverts); return s;}

            PElement< pair<Sommet*,double> > * listeDesVoisins = listeVoisins(s, graphe);
	        PElement< pair<Sommet*,double> > * l;

            for( l = listeDesVoisins; l; l = l->suivant)
            {
                Sommet * v = l->valeur->first;
                double nouveauCout = c(s) + l->valeur->second;
            
                if (etat(v) == LIBRE)
                {
                    h(v) = hh(v);
                    miseAJourVoisin( v, s, nouveauCout, Ouverts);
                }
                else
                {
                    if ( nouveauCout < c(v))
                    {
                        if (etat(v) == OUVERT)
                        PElement< Sommet>::retire(v,Ouverts);

                        miseAJourVoisin( v, s, nouveauCout, Ouverts);
                    }	
                }
            }
            PElement< pair<Sommet*,double> >::efface2(listeDesVoisins);
        }
        return nullptr;
    }
    template<class Graphe, class Sommet>
    bool AStar<Graphe, Sommet>::aStar1Cible(Graphe & graphe, Sommet * depart, Sommet * cible,
			                                double (*hh)(const Sommet * s1, const Sommet * s2))
    {
        libereToutSommet(graphe);
        PElement<Sommet> * Ouverts;

        pere(depart) = nullptr; c(depart) = 0;
        Ouverts = new PElement<Sommet>(depart,nullptr); etat(depart) = OUVERT;
        while(Ouverts)
        {
            Sommet  * s =PElement<Sommet>::depiler(Ouverts); etat(s) = FERME;
            if (s == cible) { PElement<Sommet>::efface1(Ouverts); return true;}

            PElement< pair<Sommet*,double> > * listeDesVoisins = listeVoisins(s, graphe);
            PElement< pair<Sommet*,double> > * l;

            for( l = listeDesVoisins; l; l = l->suivant)
            {
                Sommet * v = l->valeur->first;
                double nouveauCout = c(s) + l->valeur->second;

                if (etat(v) == LIBRE)
                {
                    h(v) = hh(v,cible);
			        miseAJourVoisin( v, s, nouveauCout, Ouverts);
                }
                else
                {
                    if ( nouveauCout < c(v))
                    {
                        if (etat(v) == OUVERT)
                            PElement< Sommet>::retire(v,Ouverts);

                        miseAJourVoisin( v, s, nouveauCout, Ouverts);
                    }
                }
            }
            PElement< pair<Sommet*,double> >::efface2(listeDesVoisins);
        }
        return false;
    }

    template<class Graphe, class Sommet>
    void AStar<Graphe, Sommet>::miseAJourVoisin(Sommet * v, Sommet * s, const double & nouveauCout, PElement<Sommet> * & Ouverts)
    {
        pere(v) = s;
        c(v) = nouveauCout;
        g(v) = c(v) + h(v);
        PElement<Sommet>::insertionOrdonnee( v, Ouverts, estPlusPetitOuEgal); etat(v) = OUVERT;
    }

    /***/
    template <class Sommet>
    PElement<Sommet> * chemin( Sommet * cible, PElement<Sommet> * & debut)
    {
        if (!cible)
        {
            debut = nullptr; return nullptr;
        }
        else
        {
            if(!pere(cible))	
            {
                debut = new PElement<Sommet>(nullptr, cible);
	            return debut;
            }
            else
            {
                PElement<Sommet> * d = chemin(pere(cible), debut);
                d->suivant = new PElement<Sommet>(nullptr, cible);
                return d->suivant;
            }
            
        }
    }
#endif