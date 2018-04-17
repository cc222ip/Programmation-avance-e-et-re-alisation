#include "TD-Liste.h"
#include <iostream>


using namespace std;

int main( int argc, char **argv){
	
	Maillon* m = Liste::nouveau_maillon(10, NULL);
	Liste* l = new Liste(m);
	l->Insertion_tete(5);
	l->afficher();

	return 0;
}
