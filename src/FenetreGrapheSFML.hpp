#ifndef __FENETREGRAPHESFML__
#define __FENETREGRAPHESFML__
    
    #include "MdessinUtil.inc.hpp"
    #include "VSommet.hpp"
    
    class FenetreGrapheSFML
    {
        public:
            RenderWindow fenetre;

            TransfoAffine2D t; //realise le passage fenêtre-cloture (ou encore monde vers écran)
        public:
            FenetreGrapheSFML(const std::string & titre, const unsigned int fondCarte,
                                const Vecteur2D & coinBG, const Vecteur2D & coinHD,
                                const int largeur, const int hauteur):

                                fenetre(sf::VideoMode(largeur, hauteur), titre){
                                    fenetre.clear(Color(fondCarte));

                                    Vecteur2D coinEcranBG(0, hauteur), coinEcranHD(largeur, 0);

                                    t = TransfoAffine2D::passageMondeEcran(coinBG, coinHD, coinEcranBG,
                                                                            coinEcranHD);
                                }

            template<class T>
            bool dessine(const Sommet<T> * sommet);
            
            template<class T>
            bool dessine(const Sommet<T> *debut, const Sommet<T> *fin, unsigned int couleur);

            template<class S, class T>
            bool dessine(const Arete<S,T> *arete);
            ~FenetreGrapheSFML(){}
    };
    
    template<class T>
    bool FenetreGrapheSFML::dessine(const Sommet<T> *sommet){
        return dessinePetitRond(this->fenetre,this->t, sommet->v);
    }

    template <>
    bool FenetreGrapheSFML::dessine<Peinture,VSommet>(const Arete<Peinture,VSommet> * arete)
    {
        dessineSegment( this->fenetre, this->t,   arete->v.fond, arete->_debut->v.pos, arete->_fin->v.pos);
        return dessineSegment( this->fenetre, this->t, arete->v.devant, arete->_debut->v.pos, arete->_fin->v.pos);
    }
#endif