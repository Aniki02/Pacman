#ifndef __LEVELGENERATOR__HPP
#define __LEVELGENERATOR__HPP

/**
 * \file LevelGenerator.hpp
 * \brief représente le generateur de niveau 
 * \author zitoun-diallo-sid
 */

    #include    <vector>
    #include    <array>

    #include    "Graphe.hpp"
    #include    "Peinture.hpp"
    #include    "InfoSommet.hpp"
    #include    "Vecteur2D.hpp"
    class LevelGenerator
    {
        private:
            Vecteur2D _centre;
            Sommet<InfoSommet> * _sommetCourant;
            Sommet<InfoSommet> * _sommetGhost;
            unsigned int _complexite;
            Graphe<Peinture,InfoSommet> _labyrinthe;
        public:
            LevelGenerator(const unsigned int color, const unsigned int color1, const unsigned int color2):_complexite(7){
                this->generate(color, color1, color2);
            }
            LevelGenerator( unsigned int complexite, const unsigned int color, const unsigned int color1, const unsigned int color2):_complexite(complexite){
                this->generate(color, color1, color2);
            }

            void generate(const unsigned int color, const unsigned int color1, const unsigned int color2);

            Graphe<Peinture,InfoSommet> & getGraphe(){return this->_labyrinthe;}

            ~LevelGenerator();

            Sommet<InfoSommet> * getSommetCourant()const{return _sommetCourant;}
            void setSommetCourant(Sommet<InfoSommet> * newSommetCourant){_sommetCourant = newSommetCourant;}
            Sommet<InfoSommet> * getSommetGhost() const {return _sommetGhost;}
            void setSommetGhost(Sommet<InfoSommet> * newSommetGhost){_sommetGhost = newSommetGhost;}
            void initSommet();

        private:

            void generatorArete1(const int ligne, const int colonne,
                                const unsigned int c1, const unsigned int c2,
                                vector< Arete<Peinture, InfoSommet> *> ensembleAretes,
                                vector<vector<Sommet<InfoSommet> *>> ensembleSommets);

            void generatorArete21(const int ligne, const int colonne,
                                const unsigned int c1, const unsigned int c2,
                                vector< Arete<Peinture, InfoSommet> *> ensembleAretes,
                                vector<vector<Sommet<InfoSommet> *>> ensembleSommets);
            void generatorSommets(vector<Sommet<InfoSommet> *> &nCase, 
                                    vector<vector<Sommet<InfoSommet> *>> &ensembleSommets, const unsigned int c);
    };


#endif
