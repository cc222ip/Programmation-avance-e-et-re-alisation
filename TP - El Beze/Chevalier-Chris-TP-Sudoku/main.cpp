#include "sudoku.h"

int main() {
    float temps;
    clock_t t1, t2;

    Grid G1;
    cout << "Grille avant remplissage :" << endl;
    G1.Afficher();
    bool b1 = false;

    t1 = clock();
    G1.Resolution1(0, b1);
    t2 = clock();
    
    temps = (float)(t2 - t1)/CLOCKS_PER_SEC;
    cout << "Grille après remplissage (version 1) :" << endl;
    G1.Afficher();
    cout << "Temps d'exécution de la version 1 : " << temps << endl << endl;

    Grid G2;
    bool b2 = false;

    t1 = clock();
    G2.Resolution2(0, b2);
    t2 = clock();

    temps = (float)(t2 - t1)/CLOCKS_PER_SEC;
    cout << "Grille après remplissage (version 2) :" << endl;
    G2.Afficher();
    cout << "Temps d'exécution de la version 2 : " << temps << endl;

    return 0;
}
