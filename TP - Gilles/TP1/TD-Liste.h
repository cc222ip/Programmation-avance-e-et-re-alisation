#ifndef __TD_LISTE_H__
#define __TD_LISTE_H__

#include <iostream>

using namespace std;

struct Maillon
{
	int info;
	Maillon *suiv;
};



class Liste {
		Maillon *debut;

	public :
		Liste(int *, int);
};

#endif
