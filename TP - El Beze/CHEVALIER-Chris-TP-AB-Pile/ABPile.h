#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct Maillon {
    string info;
    Maillon *suiv;
};

Maillon *NM(string, Maillon *);

class Pile {
    Maillon *tete;

    public:
        Pile();
        Pile(int);
        ~Pile();
        void afficher();
        bool Vide();
        bool Pleine();
        void Empiler(string);
        string Depiler();
        void EmpileChaine(string s);
};

struct Noeud {
    Noeud* fg;
    Noeud* fd;
    string info;
};

class Arbre {
    Noeud *racine;

    public:
        Arbre();
        ~Arbre();
        void afficheInverse(string);
        void StockExpr(Pile &, Noeud *&);
        void Afficher(Noeud *);
        void AfficherExpr(Noeud *);
        int Conversion(int, int, int, Noeud *);
        int Calculer(int, int, int, Noeud *, int &);
        void Simplifier(int, int, int, Noeud *, int);
};
