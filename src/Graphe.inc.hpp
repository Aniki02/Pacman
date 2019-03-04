    #include "Graphe.hpp"

    template <class S, class T>
    Graphe<S,T>::operator std::string()const{
        std::ostringstream os;
        os << "Le Graphe : \n"
            <<"La prochaine clef (nombre d'éléments sommets et arête): "<<this->prochaineClef
            <<"Son nombre de sommets : "<<this->nombreSommets()
            <<"Le nombre d'arrête : "<<this->nombreAretes()
            <<"*********** Les sommets *********"
            <<PElement<Sommet<T>>::toString(lSommets, "{"," : ", "}")
            <<"*********** Les arêtes **********"
            <<PElement<Arete<S,T>>::toString(lAretes, "{", " : ", "}");
        return os.str();
    }

    template<class S, class T> 
    std::ostream & operator <<(std::ostream &o, const Graphe<T,S> &graphe)
    {
        return o << (std::string)graphe;
    }

    template<class S, class T>
    Graphe<S,T>::Graphe():prochaineClef(0),lSommets(nullptr),lAretes(nullptr){}
    
    template <class S, class T>
    void Graphe<S,T>::copie(const Graphe<S, T> &graphe){

        //std::cout<<"**************************************************************"<<std::endl;
        this->prochaineClef = graphe.prochaineClef;
       // std::cout<<"le nombre d'elements :"<<std::endl<<this->prochaineClef<<std::endl;
        this->lSommets = nullptr;
        this->lAretes = nullptr;

        this->lSommets = PElement<Sommet<T>>::copie2(graphe.lSommets);
        //std::cout<<*this->lSommets->valeur<<std::endl;
        
        PElement<Arete<S,T>> *lstAretes = graphe.lAretes;
        while(lstAretes!=nullptr){
            
            ExisteParClef<T> condition(lstAretes->valeur->_debut);
            PElement<Sommet<T>> *adresseMaillonDebut = PElement<Sommet<T>>::appartient(this->lSommets, condition);
            //std::cout<<"le sommet debut :"<<std::endl<<*adresseMaillonDebut->valeur<<std::endl;

            ExisteParClef<T> condition2(lstAretes->valeur->_fin);
            PElement<Sommet<T>> *adresseMaillonFin = PElement<Sommet<T>>::appartient(this->lSommets, condition2);
           // std::cout<<"le sommet fin :"<<std::endl<<*adresseMaillonFin->valeur<<std::endl;

            this->lAretes = new PElement<Arete<S,T>>(this->lAretes,
                                                    new Arete<S,T>(lstAretes->valeur->clef,
                                                            lstAretes->valeur->v,
                                                            adresseMaillonDebut->valeur, adresseMaillonFin->valeur)
                                                    );
           // std::cout<<"l'arete construite :"<<std::endl<<*this->lAretes->valeur<<std::endl;
            //std::cout<<"**************************************************************"<<std::endl;
            lstAretes = lstAretes->suivant;
        }
        
    }

    template<class S, class T>
    Graphe<S,T>::Graphe(const Graphe<S,T> &graphe){
        this->copie(graphe);
    }

    template<class S,class T>
    const Graphe<S,T> & Graphe<S,T>::operator = (const Graphe<S,T>& graphe){
        PElement<Arete<S,T>>::efface2(this->lAretes);
        PElement<Sommet<T>>::efface1(this->lSommets);
        this->prochaineClef = 0;

        this->copie(graphe);
        return *this; 
    }
    
    template<class S, class T>
    Graphe<S,T>::~Graphe(){
        PElement<Arete<S,T>>::efface2(this->lAretes);
        PElement<Sommet<T>>::efface1(this->lSommets);
        this->prochaineClef = 0;
    }

    template <class S, class T>
    Sommet<T> * Graphe<S,T>::creeSommet(const T &info){
        /**
         * Crée un sommet isolé
         * met à jour prochaineClef
        */
       this->prochaineClef += 1 ;
       this->lSommets = new PElement<Sommet<T>>(this->lSommets, new Sommet<T>(prochaineClef, info));
       return this->lSommets->valeur;
    }

    template <class S, class T>
    Arete<S,T> * Graphe<S,T>::creeArete(const S & info, Sommet<T> * debut, Sommet<T> * fin){
        /**
         * Crée une arêt joignant les 2 sommets debut et fin 
         * _met à jour les champs degre de debut et de fin
         * _met à jour prochaineClef
        */
       this->prochaineClef +=1;
       this->lAretes = new PElement<Arete<S,T>>(this->lAretes,new Arete<S,T>(prochaineClef, info, debut, fin));
       return this->lAretes->valeur;
    }

    template <class S, class T>
    int Graphe<S,T>::nombreSommets()const {
        return PElement<Sommet<T>>::taille(lSommets);
    }

    template <class S, class T>
    int Graphe<S, T>::nombreAretes()const {
        return PElement<Arete<S,T>>::taille(lAretes);
    }

    template<class S, class T>
    PElement< std::pair< Sommet<T> *, Arete<S,T> * > > * Graphe<S,T>:: adjacences(const Sommet<T> * sommet) const{
        PElement< std::pair< Sommet<T> *, Arete<S,T> * > >*lAdjacences = nullptr;
        
        PElement< Arete<S,T> > * newPtrlAretes = this->lAretes; //nouvelle poiteur local sur la liste des arêtes

        if(newPtrlAretes!=nullptr){
            while(newPtrlAretes!=nullptr){
                if(newPtrlAretes->valeur->_debut == sommet){
                    lAdjacences = new PElement< std::pair< Sommet<T> *, Arete<S,T> * > >(lAdjacences,
                                new std::pair<Sommet<T> *, Arete<S,T> *>(newPtrlAretes->valeur->_fin, newPtrlAretes->valeur));
                }else if(newPtrlAretes->valeur->_fin == sommet){
                    lAdjacences = new PElement<std::pair< Sommet<T> *, Arete<S,T> * >>(lAdjacences,
                                new std::pair<Sommet<T> *, Arete<S,T> *>(newPtrlAretes->valeur->_debut, newPtrlAretes->valeur));
                }
                newPtrlAretes = newPtrlAretes->suivant;
            }
        }
        return lAdjacences;
    }

    template<class S, class T>
    PElement< Arete<S,T> > * Graphe<S,T>::aretesAdjacentes(const Sommet<T> * sommet)const{
        PElement< Arete<S,T> >* lAretesIncidentes = nullptr;

       PElement< std::pair< Sommet<T> *, Arete<S,T> * > > *lAdjacentes = this->adjacences(sommet);

       if(lAdjacentes!=nullptr){
           while(lAdjacentes!=nullptr){
               lAretesIncidentes = new PElement<Arete<S,T> >(lAretesIncidentes, lAdjacentes->valeur->second);
               lAdjacentes = lAdjacentes->suivant;
           }
           PElement< std::pair< Sommet<T> *, Arete<S,T> * > >::efface2(lAdjacentes);//on efface les maillons et donnée de lAdjacentes
       }
       return lAretesIncidentes;
    }

    template<class S, class T>
    PElement<Sommet<T>>* Graphe<S,T>::voisins(const Sommet<T> *sommet)const{
        PElement< Sommet<T> > *lSommetAdjacents = nullptr;

        PElement < std::pair< Sommet<T> *, Arete<S,T> * >> *lAdjacentes = this->adjacences(sommet);

        if(lAdjacentes != nullptr){
            while(lAdjacentes != nullptr){
                lSommetAdjacents = new PElement<Sommet<T> >(lSommetAdjacents, lAdjacentes->valeur->first);
                lAdjacentes = lAdjacentes->suivant;
            }
            PElement< std::pair< Sommet<T> *, Arete<S,T> * >>::efface2(lAdjacentes);
        }
        return lSommetAdjacents;
    }

    template<class S, class T>
    Arete<S,T> * Graphe<S,T>::getAreteParSommets(const Sommet<T> * s1, const Sommet<T> *s2)const{
        PElement <Arete<S,T>> * nvPtrlAretes = this->lAretes;

        while(nvPtrlAretes != nullptr && !nvPtrlAretes->valeur->estEgal(s1, s2)){
            nvPtrlAretes = nvPtrlAretes->suivant;
        }
        if(nvPtrlAretes !=nullptr)
            return nvPtrlAretes->valeur;
        else
            return nullptr;
    }
    /**********************************************************************
     * 
     * Implementation des methoses de dessin
     * 
     * 
    */
    template<class S, class T>
    template<class FENETRE>
    bool Graphe<S,T>::dessineToutesAretes(FENETRE & fenetre)const{
        PElement<Arete<S,T>> *newptrlAretes = this->lAretes;

        while(newptrlAretes != nullptr){
            if(!fenetre.dessine(newptrlAretes->valeur))
                return false;
            newptrlAretes = newptrlAretes->suivant;
        }
        return true;
    }

    template<class S, class T>
    template<class FENETRE>
    bool Graphe<S,T>::dessineToutSommets(FENETRE & fenetre)const{
        PElement<Sommet<T>> * newptrlSommets = this->lSommets;

        while(newptrlSommets != nullptr){
            if(!fenetre.dessine(newptrlSommets->valeur))
                return false;
            newptrlSommets = newptrlSommets->suivant;
        }
        return true;
    }

    template<class S, class T>
    template<class FENETRE>
    bool Graphe<S,T>::dessine(FENETRE & fenetre)const{
        if(!this->dessineToutesAretes(fenetre)) return false;
        return this->dessineToutSommets(fenetre);
    }