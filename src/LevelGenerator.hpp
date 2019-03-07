#ifndef __LEVELGENERATOR__HPP
#define __LEVELGENERATOR__HPP
    #include    <vector>
    #include    <array>

    #include    "Graphe.hpp"
    #include    "Peinture.hpp"
    #include    "VSommet.hpp"
    #include    "Vecteur2D.hpp"
    #include    "PacGomme.hpp"
    class LevelGenerator
    {
        private:
            Graphe<Peinture,VSommet> labyrinthe;
            Graphe<Peinture, PacGomme> pacGomme;

            Vecteur2D centre;
            Sommet<VSommet> * sommetCourant;
            Sommet<VSommet> * sommetGhost;
            unsigned int complexite;
        public:
            LevelGenerator(const unsigned int color, const unsigned int color1, const unsigned int color2);
            LevelGenerator( unsigned int complexite, const unsigned int color, const unsigned int color1, const unsigned int color2);

            Graphe<Peinture,VSommet>  * getGraphe(){return &this->labyrinthe;}
            Graphe<Peinture,PacGomme>  * getPacGomme(){return &this->pacGomme;}

            ~LevelGenerator();

            const Sommet<VSommet> * getSommetCourant() const {return sommetCourant;}
            void setSommetCourant(Sommet<VSommet> * newSommetCourant){sommetCourant = newSommetCourant;}
            const Sommet<VSommet> * getSommetGhost() const {return sommetGhost;}
            void setSommetGhost(Sommet<VSommet> * newSommetGhost){sommetGhost = newSommetGhost;}

        private:

            void generatorArete1(const int ligne, const int colonne,
                                const unsigned int c1, const unsigned int c2,
                                vector< Arete<Peinture, VSommet> *> ensembleAretes,
                                vector<vector<Sommet<VSommet> *>> ensembleSommets);

            void generatorArete21(const int ligne, const int colonne,
                                const unsigned int c1, const unsigned int c2,
                                vector< Arete<Peinture, VSommet> *> ensembleAretes,
                                vector<vector<Sommet<VSommet> *>> ensembleSommets);
            void generatorPacGomme(vector<Sommet<PacGomme> *> &nCase, 
                                    vector<vector<Sommet<PacGomme> *>> &ensemblePacGomme);
            void generatorSommets(vector<Sommet<VSommet> *> &nCase, 
                                    vector<vector<Sommet<VSommet> *>> &ensembleSommets, const unsigned int c);
    };


#endif
