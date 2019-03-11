#ifndef __GRAPHE__
#define __GRAPHE__
/**
 * \file Graphe.hpp
 * \brief représente un graphe
 * \author zitoun-diallo-sid
 */

    #include "ExisteParClef.hpp"

    #include <utility>

    #include "PElement.hpp"
    #include "Sommet.hpp"
    #include "Arete.hpp"

    template <class S, class T>
    class Graphe
    {
        public:
            int prochaineClef;
            PElement<Sommet<T>> * lSommets;
            PElement<Arete<S,T>> * lAretes;
        public:
            /**
             *  \brief Constructeur
             *
             *  Constructeur de la classe Graphe
             */
            Graphe();
            /**
             *  \brief Constructeur par recopie
             *
             *  Constructeur de la classe Graphe
             *
             *  \param graphe : le graphe a recopier
             */
            Graphe(const Graphe<S,T> &graphe);
            const Graphe<S,T> & operator = (const Graphe<S,T>& graphe);
            void copie(const Graphe<S,T>& graphe);

            Sommet<T> * creeSommet(const T &info);
            Arete<S,T> * creeArete(const S & info, Sommet<T> * debut, Sommet<T> * fin);
            int nombreSommets() const;
            int nombreAretes() const;
            operator std::string()const;

            PElement< std::pair< Sommet<T> *, Arete<S,T> * > > * adjacences(const Sommet<T> * sommet) const;
            PElement< Arete<S,T> > * aretesAdjacentes(const Sommet<T> * sommet)const;
            PElement< Sommet<T> > * voisins(const Sommet<T> *sommet)const;
            
            Arete<S,T> * getAreteParSommets(const Sommet<T> * s1, const Sommet<T> *s2)const;

            /**
             * Les methodes pour le dessin d'un graphe
            */
           template<class FENETRE>
           bool dessineToutesAretes(FENETRE & fenetre)const;

           template<class FENETRE>
           bool dessineToutSommets(FENETRE & fenetre)const;

           template<class FENETRE>
           bool dessine(FENETRE & fenetre)const;
            ~Graphe();
    }; 
    #include "Graphe.inc.hpp"


#endif