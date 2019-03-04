    #include    <SFML/Graphics/RenderWindow.hpp>
    #include    <SFML/Graphics/Font.hpp>
    #include    <SFML/Graphics/Text.hpp>
    #include    <SFML/Graphics/VertexArray.hpp>
    #include    <SFML/Graphics/CircleShape.hpp>
    #include    <SFML/Graphics/ConvexShape.hpp>

    #include    "TransfoAffine2D.hpp"

    #include    "Sommet.hpp"
    #include    "Arete.hpp"
    #include    "VSommet.hpp"
    #include    "Peinture.hpp"
    using namespace sf;

inline const Vector2f vecteur2DToVector2f( const Vecteur2D & v) { float x,y; v.arrondit(x,y); return Vector2f(x,y);}

inline bool dessinePetitRond(RenderWindow & fenetre, const TransfoAffine2D & t, const VSommet & vSommet,
							const Vecteur2D & deltaTextePixels = Vecteur2D(VSommet::rayonDisquePixel, VSommet::rayonDisquePixel))
{
    Vecteur2D position = t.applique(vSommet.pos);
    Vecteur2D position1 = position -VSommet::rayonDisquePixel*Vecteur2D(1,1);

    // si on appliquait la transfo t globalement à tout le graphe avant de commencer à dessiner, on optimiserait
    // bcp de calculs !!!!

    CircleShape disque((float)VSommet::rayonDisquePixel);
    disque.setFillColor(Color(vSommet.couleur));
    float epaisseurBord = (float)(0.15*VSommet::rayonDisquePixel);
    disque.setOutlineThickness(epaisseurBord);
    disque.setOutlineColor(Color(VSommet::couleurBord));

    Vector2f p1 = vecteur2DToVector2f(position1);

    disque.setPosition(p1);

    fenetre.draw(disque);
    return true;
}

/**
début et fin sont en coordonnées monde
*/
inline bool dessineSegment( RenderWindow & fenetre, const TransfoAffine2D & t, const unsigned int couleur,
						const Vecteur2D & debut, const Vecteur2D & fin, const unsigned int epaisseurTraitPixels = 2)
{
    // on va dessiner un rectangle très fin pour représenter l'arête

    Vecteur2D A, B;	// {AB} est l'arête à représenter

    A = t.applique(debut); B = t.applique(fin);		// on passe des coordonnées monde aux coordonnées écran

    Vecteur2D u = B-A;

    double nU = norme(u);
    u /=nU;
    Vecteur2D  n = u.rotationDirecteQuartDeTour();

    //double e = 1;	// épaisseur du rectangle = 2*e. longueur du rectangle == AB
    double e = 0.5*epaisseurTraitPixels;	// épaisseur du rectangle = 2*e. longueur du rectangle == AB


    Vecteur2D v = e*n;

    Vecteur2D A0= A-v,A1 = B-v, A2 = B+v,A3 = A+v; // on calcule les 4 sommets du rectangle dont l'arête [AB] est un axe de symétrie

    Vector2f F0 = vecteur2DToVector2f(A0);
    Vector2f F1 = vecteur2DToVector2f(A1);
    Vector2f F2 = vecteur2DToVector2f(A2);
    Vector2f F3 = vecteur2DToVector2f(A3);

    ConvexShape rectangle(4);
    rectangle.setPoint(0,F0);
    rectangle.setPoint(1,F1);
    rectangle.setPoint(2,F2);
    rectangle.setPoint(3,F3);

    rectangle.setFillColor(Color(couleur));
    fenetre.draw(rectangle);

    return true;
}
