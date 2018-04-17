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
		Liste();
		Liste(Maillon *);
		Liste(int *, int);
		~Liste();
		static Maillon* nouveau_maillon(int, Maillon*);
		void afficher();
		void afficher_rec();
		void afficher_rec(Maillon *);
		void afficher_inverse();
		void afficher_inverse_rec();
		void afficher_inverse_rec(Maillon *);
		int cardinal();
		int cardinal_rec();
		int cardinal_rec(Maillon *);
		int Nb_Occurence (int) ;
		bool chercher(int);
		Maillon * chercher_bis(int);
		void Insertion_tete(int);
		void supprimer(int);
		void supprimer_tout(int);
		Liste(Liste &);
		void  operator+= (int);
};
/*
//		int &operator[] (const int);
		int  operator[] (int);
**/

#endif

