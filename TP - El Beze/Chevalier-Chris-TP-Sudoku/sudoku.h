#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

class Grid {
    int size;
    char **G;

    public:
        Grid();
        ~Grid();
        void Afficher();
        bool SurLigne(char, int);
        bool SurColonne(char, int);
        bool SurBloc(char, int, int);
        bool Valide(char, int, int);
        void Resolution1(int, bool &);
        void Resolution2(int, bool &);
};
