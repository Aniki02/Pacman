#ifndef __LEVELGENERATOR__
#define __LEVELGENERATOR__
    #include    <vector>

    #include    "Graphe.hpp"
    #include    "Peinture.hpp"
    #include    "VSommet.hpp"
    #include    "Vecteur2D.hpp"
    class LevelGenerator
    {
        private:
            Graphe<Peinture,VSommet> labyrinthe;
            Vecteur2D centre;
        public:
            LevelGenerator(const unsigned int color, const unsigned int color1, const unsigned int color2);
            LevelGenerator( int complexite, const unsigned int color, const unsigned int color1, const unsigned int color2);

            Graphe<Peinture,VSommet>  * getGraphe(){
                return &this->labyrinthe;
            }
            ~LevelGenerator();
        private:
            
            void generatorArete1(const int ligne, const int colonne, 
                                const unsigned int c1, const unsigned int c2,
                                vector< Arete<Peinture, VSommet> *> ensembleAretes,
                                vector<vector<Sommet<VSommet> *>> ensembleSommets);

            void generatorArete21(const int ligne, const int colonne,
                                const unsigned int c1, const unsigned int c2,
                                vector< Arete<Peinture, VSommet> *> ensembleAretes,
                                vector<vector<Sommet<VSommet> *>> ensembleSommets);
    };
    LevelGenerator::LevelGenerator( int complexite, const unsigned int color, const unsigned int color1, const unsigned int color2)
    {
        vector<Sommet<VSommet> *> nbCase(complexite);
        vector<vector<Sommet<VSommet> *>> ensembleSommets(complexite, nbCase);

        for(int i(0); i<ensembleSommets.size(); i++){
            for(int j(0); j<nbCase.size(); j++){
                int p = j;
                Sommet<VSommet> *s;
                s = this->labyrinthe.creeSommet(VSommet("s"+to_string(i), Vecteur2D(i+1,p+2), color));
                ensembleSommets[i][j] = s;
            } 
        }
        vector< Arete<Peinture, VSommet> *> ensembleAretes;
        this->generatorArete1(ensembleSommets.size(), nbCase.size(), color1, color2, ensembleAretes, ensembleSommets);
        this->generatorArete21(ensembleSommets.size(), nbCase.size(), color1, color2, ensembleAretes, ensembleSommets);
    }
    LevelGenerator::LevelGenerator(const unsigned int color, const unsigned int color1, const unsigned int color2)
    {
        vector<Sommet<VSommet> *> nbCase(5);
        vector<vector<Sommet<VSommet> *>> ensembleSommets(5, nbCase);

       for(int i(0); i<ensembleSommets.size(); i++){
            for(int j(0); j<nbCase.size(); j++){
                int p = j;
                Sommet<VSommet> *s;
                s = this->labyrinthe.creeSommet(VSommet("s"+to_string(i), Vecteur2D(i+1,p+2), color));
                ensembleSommets[i][j] = s;
            } 
        }
        vector< Arete<Peinture, VSommet> *> ensembleAretes;
        this->generatorArete1(ensembleSommets.size(), nbCase.size(), color1, color2, ensembleAretes, ensembleSommets);
        this->generatorArete21(ensembleSommets.size(), nbCase.size(), color1, color2, ensembleAretes, ensembleSommets);
    }

    void LevelGenerator::generatorArete1(const int ligne, const int colonne,
                                            const unsigned int c1, const unsigned int c2,
                                            vector< Arete<Peinture, VSommet> *> ensembleAretes,
                                            vector<vector<Sommet<VSommet> *>> ensembleSommets)
    {
        for(int i(0); i<ligne-1; i++){
            ensembleAretes.push_back(this->labyrinthe.creeArete(Peinture(c1, c2),
                                        ensembleSommets[ligne-1][i], ensembleSommets[ligne-1][i+1]));
            ensembleAretes.push_back(this->labyrinthe.creeArete(Peinture(c1, c2),
                                    ensembleSommets[i][colonne-1], ensembleSommets[i+1][colonne-1]));
            for(int c(0); c<colonne-1; c++ ){
                ensembleAretes.push_back(this->labyrinthe.creeArete(Peinture(c1, c2),
                                        ensembleSommets[i][c], ensembleSommets[i][c+1]));
                ensembleAretes.push_back(this->labyrinthe.creeArete(Peinture(c1, c2),
                                    ensembleSommets[i][c], ensembleSommets[i+1][c]));
            }
        }
    }
    
    void LevelGenerator::generatorArete21(const int ligne, const int colonne, 
                                const unsigned int c1, const unsigned int c2,
                                vector< Arete<Peinture, VSommet> *> ensembleAretes,
                                vector<vector<Sommet<VSommet> *>> ensembleSommets)
    {
        int milieu = ligne/2;
        int mCase = colonne/2;

        for(int l(0); l<milieu; l++){
            for(int c(mCase); c<colonne-1; c++ ){
                ensembleAretes.push_back(this->labyrinthe.creeArete(Peinture(c1, c2),
                                        ensembleSommets[l+1][c], ensembleSommets[l][c+1]));
            }
        }
        for(int l(0); l<milieu; l++){
            for(int c(0); c<mCase; c++ ){
                ensembleAretes.push_back(this->labyrinthe.creeArete(Peinture(c1, c2),
                                        ensembleSommets[l][c], ensembleSommets[l+1][c+1]));
            }
        }

        for(int l(milieu); l<ligne-1; l++){
            for(int c(0); c<mCase; c++ ){
                ensembleAretes.push_back(this->labyrinthe.creeArete(Peinture(c1, c2),
                                        ensembleSommets[l+1][c], ensembleSommets[l][c+1]));
            }
        }

        for(int l(milieu); l<ligne-1; l++){
            for(int c(mCase); c<colonne-1; c++ ){
                ensembleAretes.push_back(this->labyrinthe.creeArete(Peinture(c1, c2),
                                        ensembleSommets[l][c], ensembleSommets[l+1][c+1]));
            }
        }

    }
#endif