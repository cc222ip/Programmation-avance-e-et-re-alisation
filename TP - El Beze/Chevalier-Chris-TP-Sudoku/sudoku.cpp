#include "sudoku.h"

Grid::Grid() { // Construit la grille de Sudoku en se basant sur le fichier 'grille'
    size = 9;
    G = new char *[size];
    for(int i = 0; i < size; i++) {
        G[i] = new char[size];
    }
    int x = 0;
    int y = 0;

    ifstream fichier("grille", ios::in);
    if(fichier) {
        char caractere;
        fichier.get(caractere);
        while(caractere != ';') {
            if(caractere == ',') {
                fichier.get(caractere);
            }
            else if(caractere == '\n') {
                fichier.get(caractere);
                y++;
                x = 0;
            }
            else {
                G[x][y] = caractere;
                fichier.get(caractere);
                x++;
            }
        }
        fichier.close();
    }
    else {
        cerr << "La grille sudoku ne peut être lue." << endl;
    }
}

Grid::~Grid() {
    for (int i = 0; i < size; i++) {
        delete[] G[i];
    }
    delete[] G;
}

void Grid::Afficher() {
    cout << "____________" << endl;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if((j + 1) % 3) {
                cout << G[j][i];
            }
            else {
                cout << G[j][i] << "|";
            }
        }
        cout << endl;
        if(!((i + 1) % 3)) {
            cout << "------------" << endl;
        }
    }

}

bool Grid::SurLigne(char v, int i) { // Teste si le nombre choisi apparaît dans la ligne i
    for (int j = 0; j < size; j++) {
        if(G[i][j] == v) {
            return true;
        }
    }
    return false;
}

bool Grid::SurColonne(char v, int j) { // Teste si le nombre choisi apparaît dans la colonne j
    for (int i = 0; i < size; i++) {
        if(G[i][j] == v) {
            return true;
        }
    }
    return false;
}

bool Grid::SurBloc(char v, int i, int j) { // Teste si le nombre choisi est déjà dans le bloc courant
    int I = i - (i % 3), J = j - (j % 3);
    for (i = I; i < I + 3; i++) {
        for (j = J; j < J + 3; j++) {
            if (G[i][j] == v) {
                return true;
            }
        }
    }
    return false;
}

bool Grid::Valide(char c, int i, int j) { // Teste si le nombre choisi peut être placé dans la case[i, j].
    if(SurLigne(c, i) == false && SurColonne(c, j) == false && SurBloc(c, i, j) == false) {
        return true;
    }
    return false;
}

// Version 1 (On pose puis on teste la valeur) :
void Grid::Resolution1(int position, bool &b) {
    if(position == size * size) { // Si la grille a été entierement parcourue, fin de la fonction
        b = true;
        return;
    }
    if(b) {
        return;
    }

    int i = position / size; // Axe des ordonnés.
    int j = position % size; // Axe des abscisses.
    char T[] = "123456789ABCDEF"; // Stocke toutes les valeurs possibles pour une grille de 9x9 OU 16x16.

    if(G[i][j] != '0') { // Si la case est déjà remplie,
        Resolution2(position + 1, b); // On passe à la case suivante.
        return;
    }

    // Si la case n'est pas remplie,
    for(int k = 0; k < size; k++) { // On parcourt des nombres entre 1 et la taille de la grille.
        char c = T[k]; // On stocke la valeur à placer dans 'c'.
        G[i][j] = c; // On place la valeur dans la grille.
        if(Valide(c, i, j)) { // Si la valeur entre dans les normes,
            Resolution1(position + 1, b); // on passe à la case suivante.
            return;
        }

        if(!b) { // Si on n'a pas entièrement parcouru la grille,
            Resolution1(position + 1, b); // on passe à la case suivante.
        }
    }
    if(!b) { // Si aucune valeur proposée ne correspond,
        G[i][j] = '0'; // on remet la case à 0.
    }
}

// Version 2 (on teste la valeur avant de la poser):
void Grid::Resolution2(int position, bool &b) {
    if(position == size * size) { // Si la grille a été entierement parcourue, fin de la fonction
        b = true;
        return;
    }
    if(b) { // Si on a parcouru l'intégralité de la grille,
        return; // on quitte la fonction.
    }

    int i = position / size; // Axe des ordonnés.
    int j = position % size; // Axe des abscisses.
    string T = "123456789ABCDEF"; // Stocke toutes les valeurs possibles pour une grille de 9x9 OU 16x16.

    if(G[i][j] != '0') { // Si la case est déjà remplie,
        Resolution2(position + 1, b); // on passe à la case suivante.
        return;
    }

    // Si la case n'est pas remplie,
    for(int k = 0; k < size; k++) { // on parcourt des nombres entre 1 et la taille de la grille.
        char c = T[k]; // Stocke la valeur testée dans 'c'.
        if(Valide(c, i, j)) { // Si la valeur proposée respecte les conditions,
            G[i][j] = c; // on rempli la case avec cette valeur.
            if(!b) { // Si on n'a pas parcouru l'intégralité de la grille,
                Resolution2(position + 1, b); // on passe à la case suivante.
            }
        }
    }
    if(!b) { // Si aucune valeur proposée ne correspond,
        G[i][j] = '0'; // on remet la case à 0.
    }
}
