#include "LevelGenerator.hpp"
 

 /////////////////////////////// GENERATE ///////////////////////////////////
void LevelGenerator::generate(const unsigned int color, const unsigned int color1, const unsigned int color2){

    /** Tableau des sommets */
    vector<Sommet<VSommet> *> nbCase(_complexite);
    vector<vector<Sommet<VSommet> *>> ensembleSommets(_complexite, nbCase);
    
    this->generatorSommets(nbCase, ensembleSommets, color);

    PElement<Sommet<VSommet> > * temp = _labyrinthe.lSommets;
    //choisis la dernier element de la liste comme sommet courant car c'est le premier sommet en bas a gauche
    while (temp->suivant != nullptr)
        temp = temp->suivant;

    _sommetCourant = temp->valeur;
    _sommetGhost = _labyrinthe.lSommets->valeur;

    vector< Arete<Peinture, VSommet> *> ensembleAretes;
    this->generatorArete1(ensembleSommets.size(), nbCase.size(), color1, color2, ensembleAretes, ensembleSommets);
    this->generatorArete21(ensembleSommets.size(), nbCase.size(), color1, color2, ensembleAretes, ensembleSommets);
}


//////////////////////////////////////////////// GENERATOR ARETE 1 ////////////////////////////////////////////////////////////
void LevelGenerator::generatorArete1(const int ligne, const int colonne,
                                        const unsigned int c1, const unsigned int c2,
                                        vector< Arete<Peinture, VSommet> *> ensembleAretes,
                                        vector<vector<Sommet<VSommet> *>> ensembleSommets)
{
    for(int i(0); i<ligne-1; i++){
        ensembleAretes.push_back(this->_labyrinthe.creeArete(Peinture(c1, c2),
                                    ensembleSommets[ligne-1][i], ensembleSommets[ligne-1][i+1]));
        ensembleAretes.push_back(this->_labyrinthe.creeArete(Peinture(c1, c2),
                                ensembleSommets[i][colonne-1], ensembleSommets[i+1][colonne-1]));
        for(int c(0); c<colonne-1; c++ ){
            ensembleAretes.push_back(this->_labyrinthe.creeArete(Peinture(c1, c2),
                                    ensembleSommets[i][c], ensembleSommets[i][c+1]));
            ensembleAretes.push_back(this->_labyrinthe.creeArete(Peinture(c1, c2),
                                ensembleSommets[i][c], ensembleSommets[i+1][c]));
        }
    }
}

///////////////////////////////////////////////// GENERATOR ARETE 2 /////////////////////////////////////////////////////////

void LevelGenerator::generatorArete21(const int ligne, const int colonne, 
                            const unsigned int c1, const unsigned int c2,
                            vector< Arete<Peinture, VSommet> *> ensembleAretes,
                            vector<vector<Sommet<VSommet> *>> ensembleSommets)
{
    int milieu = ligne/2;
    int mCase = colonne/2;

    for(int l(0); l<milieu; l++){
        for(int c(mCase); c<colonne-1; c++ ){
            ensembleAretes.push_back(this->_labyrinthe.creeArete(Peinture(c1, c2),
                                    ensembleSommets[l+1][c], ensembleSommets[l][c+1]));
        }
    }
    for(int l(0); l<milieu; l++){
        for(int c(0); c<mCase; c++ ){
            ensembleAretes.push_back(this->_labyrinthe.creeArete(Peinture(c1, c2),
                                    ensembleSommets[l][c], ensembleSommets[l+1][c+1]));
        }
    }

    for(int l(milieu); l<ligne-1; l++){
        for(int c(0); c<mCase; c++ ){
            ensembleAretes.push_back(this->_labyrinthe.creeArete(Peinture(c1, c2),
                                    ensembleSommets[l+1][c], ensembleSommets[l][c+1]));
        }
    }

    for(int l(milieu); l<ligne-1; l++){
        for(int c(mCase); c<colonne-1; c++ ){
            ensembleAretes.push_back(this->_labyrinthe.creeArete(Peinture(c1, c2),
                                    ensembleSommets[l][c], ensembleSommets[l+1][c+1]));
        }
    }

}


///////////////////////////////////////////////////////GENERATOR SOMMET /////////////////////////////////////////////////////
void LevelGenerator::generatorSommets(vector<Sommet<VSommet> *> &nCase, 
                                    vector<vector<Sommet<VSommet> *>> &ensembleSommets, const unsigned int c)
{
    for(int i(0); i<ensembleSommets.size(); i++){
        for(int j(0); j<nCase.size(); j++){
            int p = j;
            Sommet<VSommet> *s;
            s = this->_labyrinthe.creeSommet(VSommet("s"+to_string(i), Vecteur2D(i+1,p+2), c));
            ensembleSommets[i][j] = s;
        } 
    }
}