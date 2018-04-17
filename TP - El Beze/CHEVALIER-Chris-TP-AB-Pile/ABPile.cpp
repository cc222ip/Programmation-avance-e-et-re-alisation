#include "ABPile.h"

/*############################
###### - PILE CHAINÉE - ######
##############################*/

Pile::Pile() {
    tete = NULL;
}

Pile::~Pile() {
    if(tete) delete(tete);
}

bool Pile::Vide() {
    if(tete == NULL) return true;
    return false;
}

void Pile::afficher() {
    if(Vide()) {
        cerr << "La pile est vide." << endl;
    }
    else {
        while(!Vide()) {
            cout << this->Depiler() << endl;
        }
    }
}

Maillon *NM(string s, Maillon *p = NULL) { //Nouveau Maillon
    Maillon *P = new Maillon;
    P->info = s;
    P->suiv = p;
    return P;
}

void Pile::Empiler(string x) {
    tete = NM(x, tete);
}



string Pile::Depiler() {
    string s = tete->info;
    Maillon *tmp = tete;
    if(Vide()) {
        cerr << "La pile est vide" << endl;
    }
    else {
        tete = tete->suiv;
        delete(tmp);
        return s;
    }
    return 0;
}

/*################################
###### - FIN PILE CHAINÉE - ######
##################################

____________________________________________

#######################
###### - ARBRE - ######
#######################*/


Arbre::Arbre() {
    racine = NULL;
}

Arbre::~Arbre() {
    if(racine) delete racine;
}

void Arbre::afficheInverse(string s) {
    Pile P;
    int esp;
    string tmp;
    while(s != "") { //Parcours la chaîne de caractères
        esp = s.find(' ');
        tmp = s.substr(0, esp);
        P.Empiler(tmp); //Affichage de la sous-chaîne
        s = s.substr(esp + 1);
    }
    while(!P.Vide()) {
        cout << P.Depiler() << " ";
    }
    cout << endl;
}

void Pile::EmpileChaine(string s) {
    int esp;
    string tmp;
    while(s != "") {
        esp = s.find(' ');
        tmp = s.substr(0, esp);
        Empiler(tmp);
        s = s.substr(esp + 1);
    }
}

void Arbre::StockExpr(Pile &P, Noeud *&n) {
    if(!P.Vide()) {
        n = new Noeud;
        n->fg = NULL;
        n->fd = NULL;
        n->info = P.Depiler();
        if(racine == NULL) {
            racine = n;
        }
        if(n->info == "+" || n->info == "-" || n->info == "*" || n->info == "/") {
            StockExpr(P, n->fd);
            StockExpr(P, n->fg);
        }
    }
}

void Arbre::Afficher(Noeud *n) {
    cout << n->info << endl;
    if(n->fg) {
        Afficher(n->fg);
    }
    if(n->fd) {
        Afficher(n->fd);
    }
}

void Arbre::AfficherExpr(Noeud *n) {
    if(n) {
        if((n != racine) && (n->info == "+" || n->info == "-" || n->info == "*" || n->info == "/")) {
            cout << "(";
        }
        AfficherExpr(n->fg);
        cout << n->info << "";
        AfficherExpr(n->fd);
        if(n->fd) {
            if(n->fd->fd == NULL) {
                cout << ")";
            }
        }
    }
}

int Arbre::Conversion(int X, int Y, int Z, Noeud *n) {
    int v = 0;
    if(n) {
        if(n->info != "+" && n->info != "-" && n->info != "*" && n->info != "/" && n->info != "X" && n->info != "Y" && n->info != "Z") {
            v = atoi(n->info.c_str());
        }
        else if(n->info == "X") {
            v = X;
        }
        else if(n->info == "Y") {
            v = Y;
        }
        else if(n->info == "Z") {
            v = Z;
        }
    }
    return v;
}

int Arbre::Calculer(int X, int Y, int Z, Noeud *n, int &res) {
    if(n)  {
        res = Conversion(X, Y, Z, n);
        if(n->info == "+") {
            return Calculer(X, Y, Z, n->fg, res) + Calculer(X, Y, Z, n->fd, res);
        }
        if(n->info == "-") {
            return Calculer(X, Y, Z, n->fg, res) + Calculer(X, Y, Z, n->fd, res);
        }
        if(n->info == "*") {
            return Calculer(X, Y, Z, n->fg, res) * Calculer(X, Y, Z, n->fd, res);
        }
        if(n->info == "/") {
            return Calculer(X, Y, Z, n->fg, res) / Calculer(X, Y, Z, n->fd, res);
        }
    }
    return res;
}

void Arbre::Simplifier(int X, int Y, int Z, Noeud *n, int res) {
    if(n) {
        if(n->info == "+" || n->info == "-" || n->info == "*" || n->info == "/") {
            if(n->fg->info != "+" && n->fg->info != "-" && n->fg->info != "*" && n->fg->info != "/" && n->fg->info != "X" && n->fg->info != "Y" && n->fg->info != "Z") {
                if(n->fd->info != "+" && n->fd->info != "-" && n->fd->info != "*" && n->fd->info != "/" && n->fd->info != "X" && n->fd->info != "Y" && n->fd->info != "Z") {
                    n->info = to_string(Calculer(X, Y, Z, n, res));
                    n->fg = NULL;
                    n->fd = NULL;
                }
            }
        }
        Simplifier(X, Y, Z, n->fg, res);
        Simplifier(X, Y, Z, n->fd, res);
    }
}
