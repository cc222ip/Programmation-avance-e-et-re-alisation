#include "TD-Liste.h"

// ---------------------------------
// -- Construct List from Table   --
// ---------------------------------
Liste::Liste(int *T, int N) {
	int i;
	Maillon * tmp;	
	debut = NULL;
	for (i = N - 1;i >= 0; i--)	{
		tmp = new Maillon   ;
		tmp -> info = T[i]  ;
		tmp -> suiv = debut ;
		debut = tmp ;
	}
}

