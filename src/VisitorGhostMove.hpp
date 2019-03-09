#ifndef _VISITORGHOSTMOVE_HPP
#define _VISITORGHOSTMOVE_HPP

class WorldRenderer;


class VisitorGhostMove{
public :
    virtual void visite(WorldRenderer * world) = 0;
    Vecteur2D direction(Vecteur2D sommetDepart, Vecteur2D sommetArrive) {
        int x(0), y(0);
        if(sommetArrive.x > sommetDepart.x)
            x = 1;
        else{
            if(sommetArrive.x < sommetDepart.x)
                x = -1;
        }

        if(sommetArrive.y > sommetDepart.y)
            y = 1;
        else{
            if(sommetArrive.y < sommetDepart.y)
                y = -1;
        }
        return Vecteur2D(x,y);
    }
};
#endif
