#include "TD-Liste.h"
// ------------------------------
// - Q1 : Construct empty List -- 
// ------------------------------
Liste::Liste() { 	debut = NULL;   }

// ---------------------------------
// Q2 : Construct List from Table --
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

// ---------------------------------
// Q2-bis : Create a new Maillon  --
// ---------------------------------
Maillon* Liste::nouveau_maillon(int val, Maillon* suivant){
	
	Maillon* nouveau = new Maillon; 
	nouveau->info = val;
	nouveau->suiv = suivant;
	return nouveau;
}

// --------------------------------------
// Q3 : Construct List with  Maillon * --
// --------------------------------------
Liste::Liste(Maillon * p) { 	debut = p; }

// ------------------ --
// Q4 : Destruct List --
// ------------------ --
Liste::~Liste(){
	Maillon * tmp;
	while (debut != NULL)	{
		tmp = debut;
		debut = debut -> suiv;
		delete tmp;
	}
}

// -------------------- --
// Q5 Insertion en tete --
// -------------------- --
void Liste::Insertion_tete(int v){
	Maillon * tmp = new Maillon;
	tmp -> info = v;
	tmp -> suiv = debut;
	debut = tmp;
}

// --------------------------- --
// Q6 affichage iteratif Liste --
// --------------------------- --
void Liste::afficher() {
	Maillon * tmp = debut;
	while (tmp != NULL) {
		cout << tmp -> info << "  ";
		tmp = tmp -> suiv;
	}
}

// ------------------------------- --
// Q6-bis affichage recursif Liste --
// ------------------------------- --
void Liste::afficher_rec() {
	afficher_rec(debut);
}
void Liste::afficher_rec(Maillon * m) {
	if (m == NULL)	return;
	cout << m -> info << "  ";
	afficher_rec(m -> suiv);
}

// --------------------------------------- --
// Q7 affichage inverse recursif Liste --
// --------------------------------------- --
void Liste::afficher_inverse() {
	Liste B ;
	Maillon * p, * tmp = debut;
	cout <<"___> Affichage Inverse Iter "<< endl << flush;
	while (tmp != NULL) {
			p = new Maillon   ;
			p -> info = tmp -> info  ;
			p-> suiv = B.debut ;
			B.debut = p ;
		tmp = tmp -> suiv;
	}
	B.afficher();
	cout << endl << flush;
}

// --------------------------------------- --
// Q7-bis affichage inverse recursif Liste --
// --------------------------------------- --
void Liste::afficher_inverse_rec() {
	cout <<"___> Affichage Inverse Rec "<< endl << flush;
	afficher_inverse_rec(debut);
	cout << endl << flush;
}
void Liste::afficher_inverse_rec(Maillon * m) {
	if (m == NULL) return;
	afficher_inverse_rec(m -> suiv);
	cout << m -> info << "  ";
}


// --------------------------------- --
// Q8 renvoi iteratif cardinal Liste --
// --------------------------------- --
int Liste::cardinal() {
	Maillon * tmp= debut;
	int cpt (0);
	while (tmp != NULL)	{
		cpt ++; tmp = tmp -> suiv;
	}
	return cpt;
}

// ------------------------------------- --
// Q8 bis renvoi recursif cardinal Liste --
// ------------------------------------- --
int Liste::cardinal_rec() {
	return cardinal_rec(debut);
}
int Liste::cardinal_rec(Maillon * m) {
	if (m == NULL) return 0;
	return 1 +  cardinal_rec(m-> suiv);
}

// ---------------------------------------------------------------------
// Q9 : Cherche v renvoie true si v appartient a la liste false sinon --
// ---------------------------------------------------------------------
bool Liste::chercher(int v) {
	Maillon * tmp = debut;
	while (tmp != NULL) {
		if (tmp -> info == v) return true;
		tmp = tmp -> suiv;
	}
	return false;
}
// ----------------------------------------------------------------
// Q9-bis : Cherche v et renvoie pointeur vers premier maillon 	--
// qui contient v si v appartient a la liste NULL sinon 		--
// -----------------------------------------------------------------
Maillon * Liste::chercher_bis(int v) {
	Maillon * tmp = debut;
	while (tmp != NULL && tmp -> info != v)	tmp = tmp -> suiv;
	return tmp;
}
// -----------------------------------------------
// Q10 : Compte Nb apparitions v  dans la liste --
// -----------------------------------------------
int Liste::Nb_Occurence (int v) {
	int NbOccur = 0;
	Maillon * tmp = debut;
	while (tmp != NULL) {
		if (tmp -> info == v) NbOccur++;
		tmp = tmp -> suiv;
	}
	return NbOccur;
}

// -----------------------------------------------
// Q 11 Supprimer le premier maillon qui porte la valeur v
// -----------------------------------------------
void Liste::supprimer(int v) {
	Maillon * pcur, * preced;
	
	pcur = debut;	preced = NULL;
	while (pcur != NULL && pcur -> info != v)	{
		preced = pcur;
		pcur = pcur -> suiv;
	}
	if (pcur == NULL)	return;		 		// v absent
	if (preced == NULL) debut = pcur -> suiv; 	// v en tete 
	else			preced -> suiv = pcur -> suiv;
	delete pcur;
}
// -----------------------------------------------
// Q 12 Supprimer tous les maillons qui portent la valeur v
// -----------------------------------------------
void Liste::supprimer_tout(int v) {
	Maillon * pcur= debut; Maillon * preced= NULL;

	while (pcur != NULL )	{
		if (pcur -> info == v){
			if (preced == NULL) 	debut = pcur -> suiv; // v tete Liste
			else				preced -> suiv = pcur -> suiv;
			delete pcur;
			if (preced == NULL) 	pcur = debut; 
			else				pcur = preced -> suiv;

		}
		else{
			preced = pcur;
			pcur = pcur -> suiv;
		}
	}
}

// --------------------------------
// Q 13
// --------------------------------
void Liste::operator+= (int v) {
	Maillon * tmp = new Maillon;
	tmp -> info = v;
	tmp -> suiv = debut;
	debut = tmp;
}

// --------------------------------
// Q 14 Constructeur par recopie --
// --------------------------------
Liste::Liste(Liste & L) {
	if (L.debut == NULL) {  		// Liste vide
		debut = NULL;		return;
	}
	debut = new Maillon;
	debut -> info = L.debut -> info;
	
	Maillon * tmp1, *tmp2 = debut;
	tmp1 = L.debut -> suiv;
	while (tmp1 != NULL) {
		tmp2 -> suiv = new Maillon;
		tmp2 = tmp2 -> suiv;
		tmp2 -> info = tmp1 -> info;
		tmp1 = tmp1 -> suiv;
	}
	tmp2 -> suiv = NULL;
}



/************
//15
//int & Liste::operator[] (const int i) {
int Liste::operator[] (int i) {
	Maillon * tmp;
	tmp = debut;
	if (tmp == NULL) cout <<"NUL de NUL"<<endl;
	cout <<"============i="<<i<<endl;
	for (int j=0; j<i; j++){
		if (tmp == NULL) break;
		tmp = tmp -> suiv;
		cout << j <<" "<< tmp-> info <<" "<<endl;
	}
	if (tmp == NULL) {
		cout << "erreur"<<endl;
//		return 0;
		return NULL;
	}
	return  tmp -> info;
}
**/
