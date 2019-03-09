#include 	"OutilsCarte.hpp"


/*static*/ double OutilsCarte::distance( const Sommet<InfoSommet> * s1, const Sommet<InfoSommet> * s2)
{
	return norme(s1->v.vSommet.pos - s2->v.vSommet.pos);
//return 0;
}

/*static*/ Arete<InfoArete, InfoSommet> *  OutilsCarte::creeArete(Sommet<InfoSommet> * sA, Sommet<InfoSommet> * sB, Graphe<InfoArete, InfoSommet> & graphe)
{
	return graphe.creeArete( InfoArete( OutilsCarte::distance(sA,sB) ), sA, sB);
}

/*static*/ void OutilsCarte::libereToutSommet(Graphe<InfoArete, InfoSommet> & graphe)
{
	PElement < Sommet<InfoSommet> > * l;


	for (  l = graphe.lSommets; l ; l = l->suivant)
		{
		etat(l->valeur) = LIBRE;
		pere(l->valeur) = NULL;
	}
}


/*static*/ double OutilsCarte::hh(const Sommet<InfoSommet> * s)
{
	return OutilsCarte::distance(s,OutilsCarte::cible);
}

/*static*/ PElement< pair<Sommet<InfoSommet>*,double> > * OutilsCarte::listeVoisins(const Sommet<InfoSommet> * s, const Graphe<InfoArete, InfoSommet> & graphe)
{
	PElement< pair < Sommet<InfoSommet> *, Arete<InfoArete,InfoSommet> * > > * ladj, *lA;						// pair < Sommet<InfoSommet> *, Arete<InfoArete,InfoSommet> * >

	ladj = graphe.adjacences(s);

	PElement< pair<Sommet<InfoSommet>*,double> > * lVC;

	for ( lA = ladj, lVC = NULL; lA; lA = lA->suivant)
		lVC = new PElement< pair<Sommet<InfoSommet>*,double> >(lVC,
																new pair<Sommet<InfoSommet>*,double>(lA->valeur->first,lA->valeur->second->v.cout1));


	PElement< pair< Sommet<InfoSommet> *, Arete<InfoArete,InfoSommet> * > >::efface2(ladj);
	return lVC;

}

/*static*/ Sommet<InfoSommet> *  OutilsCarte::pere( const Sommet<InfoSommet> * sommet)
{
	return (Sommet<InfoSommet>*)sommet->v.infoAStar.pere;
}


/*static*/ Sommet<InfoSommet> * & OutilsCarte::pere( Sommet<InfoSommet> * sommet)
{
	return (Sommet<InfoSommet> *&)(sommet->v.infoAStar.pere);
}

/*static*/ int & OutilsCarte::etat( Sommet<InfoSommet> * sommet)
{
	return sommet->v.infoAStar.etat;
}

/*static*/ double & OutilsCarte::c( Sommet<InfoSommet> * sommet)
{
	return sommet->v.infoAStar.c;
}

/*static*/ double & OutilsCarte::h( Sommet<InfoSommet> * sommet)
{
	return sommet->v.infoAStar.h;
}

/*static*/ double OutilsCarte::g( const Sommet<InfoSommet> * sommet)
{
	return sommet->v.infoAStar.g;
}


/*static*/ double & OutilsCarte::g( Sommet<InfoSommet> * sommet)
{
	return sommet->v.infoAStar.g;
}

/*static*/ bool OutilsCarte::estFinal(const Sommet<InfoSommet> * sommet)
{
	return sommet == cible;
}

/*static*/ Sommet<InfoSommet> * OutilsCarte::cible = NULL;


//--------------------- et maintenant les méthodes ordinaires appelées par A* -------------------------------------



void libereToutSommet(Graphe<InfoArete, InfoSommet> & graphe)
{
	return OutilsCarte::libereToutSommet(graphe);
}

PElement< pair<Sommet<InfoSommet>*,double> > * listeVoisins(const Sommet<InfoSommet> * s, const Graphe<InfoArete, InfoSommet> & graphe)
{
	return OutilsCarte::listeVoisins(s,graphe);
}

Sommet<InfoSommet> *  pere( const Sommet<InfoSommet> * sommet)
{
	return OutilsCarte::pere(sommet);
}

Sommet<InfoSommet> * & pere( Sommet<InfoSommet> * sommet)
{
	return OutilsCarte::pere(sommet);
}

int & etat( Sommet<InfoSommet> * sommet)
{
	return OutilsCarte::etat(sommet);
}

double & c( Sommet<InfoSommet> * sommet)
{
	return OutilsCarte::c(sommet);
}

double & h( Sommet<InfoSommet> * sommet)
{
	return OutilsCarte::h(sommet);
}

double g( const Sommet<InfoSommet> * sommet)
{
	return OutilsCarte::g(sommet);
}

double & g( Sommet<InfoSommet> * sommet)
{
	return OutilsCarte::g(sommet);
}


/**
compte le nombre de maillons de la liste chaînée "pere" dont le maillon de tête est "tête".
*/
int longueurChemin(const Sommet<InfoSommet>* tete)
{
	if (!tete)
		return 0;
	else
		return 1 + longueurChemin(pere(tete));
}


const Sommet<InfoSommet> * dernierMaillon(const Sommet<InfoSommet>* tete)
{
	if (!tete) return NULL;
	else
		if (pere(tete) == NULL)
			return tete;
		else
			return dernierMaillon(pere(tete));

}


bool estFinal(const Sommet<InfoSommet> * sommet)
{
	return OutilsCarte::estFinal(sommet);
}
