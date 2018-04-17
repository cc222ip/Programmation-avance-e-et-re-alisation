#include <iostream>
#include "arbre_binaire.h"

using namespace std;

int main() {
	
	cout << endl;
	cout << endl << "============== B ==================== " << endl;
	arbre B(NN(7,
				NN(3,
					NN(4),
					NN(9,NN(12),NULL)
					),
				NN(5,
					NN(23,NULL,NN(17)),
					NULL)
				)
			);	
	cout << endl << ">>>>>>>>>>>>>>>>> Profondeur B : " << endl;
	B.profondeur();
	cout << endl;
	cout << endl << ">>>>>>>>>>>>>>>>> Hauteur B : " << endl;
	cout << endl << "Hauteur1 B : " << endl;
	cout << B.hauteur1();
	cout << endl;
	cout << endl << "Hauteur2 B : " << endl;
	cout << B.hauteur2();
	cout << endl;

	cout << endl << ">>>>>>>>>>>>>>>>> Hauteur Terminale : " << endl;
	cout << B.hauteurT();
	cout << endl;
	cout << "------> FIN DES FINS " << endl;

}

