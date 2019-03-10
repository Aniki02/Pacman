#ifndef __LEVELGENERATOR__HPP
#define __LEVELGENERATOR__HPP
    #include    <vector>
    #include    <array>

    #include    "Graphe.hpp"
    #include    "Peinture.hpp"
    #include    "VSommet.hpp"
    #include    "Vecteur2D.hpp"
    class LevelGenerator
    {
        private:
            Graphe<Peinture,VSommet> _labyrinthe;
            Vecteur2D _centre;
            Sommet<VSommet> * _sommetCourant;
            Sommet<VSommet> * _sommetGhost;
            unsigned int _complexite;
        public:
            LevelGenerator(const unsigned int color, const unsigned int color1, const unsigned int color2):_complexite(7){
                this->generate(color, color1, color2);
            }
            LevelGenerator( unsigned int complexite, const unsigned int color, const unsigned int color1, const unsigned int color2):_complexite(complexite){
                this->generate(color, color1, color2);
            }

            void generate(const unsigned int color, const unsigned int color1, const unsigned int color2);

            Graphe<Peinture,VSommet>  * getGraphe(){return &this->_labyrinthe;}

            ~LevelGenerator();

            Sommet<VSommet> * getSommetCourant()const{return _sommetCourant;}
            void setSommetCourant(Sommet<VSommet> * newSommetCourant){_sommetCourant = newSommetCourant;}
            Sommet<VSommet> * getSommetGhost() const {return _sommetGhost;}
            void setSommetGhost(Sommet<VSommet> * newSommetGhost){_sommetGhost = newSommetGhost;}
            void initSommet();

        private:

            void generatorArete1(const int ligne, const int colonne,
                                const unsigned int c1, const unsigned int c2,
                                vector< Arete<Peinture, VSommet> *> ensembleAretes,
                                vector<vector<Sommet<VSommet> *>> ensembleSommets);

            void generatorArete21(const int ligne, const int colonne,
                                const unsigned int c1, const unsigned int c2,
                                vector< Arete<Peinture, VSommet> *> ensembleAretes,
                                vector<vector<Sommet<VSommet> *>> ensembleSommets);
            void generatorSommets(vector<Sommet<VSommet> *> &nCase, 
                                    vector<vector<Sommet<VSommet> *>> &ensembleSommets, const unsigned int c);
    };


#endif
