#ifndef __ARBRE_BINAIRE_H__
#define __ARBRE_BINAIRE_H__

#include <iostream>
#include <cstdlib>

using namespace std;

struct noeud {
    int info;
    noeud * fg, * fd;
};

noeud * NN(int, noeud *, noeud *);
noeud * NN(int);

class arbre {
    noeud * racine;
  public:
    arbre();
    arbre(noeud *);
    ~arbre();
	void detruit(noeud * p);

	void profondeur();
	void profondeur(noeud *, int);
	
	int hauteur1();
	int hauteur1(noeud *);
	int hauteur2();
	int hauteur2(noeud *, int);

	int hauteurT();
	void hauteurT(noeud *, int, int &);
	
};

#endif
