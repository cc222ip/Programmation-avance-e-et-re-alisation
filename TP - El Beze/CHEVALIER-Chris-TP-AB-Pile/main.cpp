#include "ABPile.h"

int main() {
    Arbre A1;
    Arbre A2;

    string s1 = "2 3 + 4 * 5 X * + ";
    string s2 = "3 X * 4 Y * + Z X 4 + * + ";

    Noeud *n1 = NULL;
    Noeud *n2 = NULL;

    Pile P1;
    Pile P2;

    int X, Y, Z;
    X = 8;
    Y = 11;
    Z = 22;
    int r = 0;

    P1.EmpileChaine(s1);
    P2.EmpileChaine(s2);

    A1.StockExpr(P1, n1);
    cout << "Arbre 1 stockant " << s1 << ":" << endl;
    A1.Afficher(n1);
    cout << endl;

    cout << "Arbre 2 stockant " << s2 << ":" << endl;
    A2.StockExpr(P2, n2);
    A2.Afficher(n2);
    cout << endl;

    cout << "Expression 1 : ";
    A1.AfficherExpr(n1);
    cout << endl;
    cout << "-> Résultat = ";
    cout << A1.Calculer(X, Y, Z, n1, r) << endl;
    cout << endl;

    cout << "Expression 2 : ";
    A2.AfficherExpr(n2);
    cout << endl;
    cout << "-> Résultat = ";
    cout << A2.Calculer(X, Y, Z, n2, r) << endl;
    cout << endl;
    
    A1.Simplifier(X, Y, Z, n1, r);
    A1.Simplifier(X, Y, Z, n1, r);
    cout << "Arbre 1 Simplifié :" << endl;
    A1.Afficher(n1);


    return 0;
}
