#include "arbre_binaire.h"
//---------------------------------------------------- 	Constructeurs 	Q1
arbre::arbre() {  racine = NULL; }
arbre::arbre(noeud * N) {  racine = N; }
noeud * NN(int i) { 			// Creation d'un noeud feuille et remplissage
	noeud *  N = new noeud;
	N -> info = i;	N -> fg = N -> fd = NULL;
	return N;
}
//--------------------------------------------------------- Destructeur	Q2
void arbre::detruit(noeud * p) {
  if (p == NULL)   return;
    detruit(p -> fg);    detruit(p -> fd);    delete(p);
}
arbre::~arbre() {  detruit(racine); }
//------------------------------------- Creation d'un noeud et remplissage	Q3 
noeud * NN(int i, noeud * g, noeud * d) { 
	noeud * N = new noeud;
	N -> info = i;	N -> fg = g;	N -> fd = d;
	return N;
}
//--------------------------------------------- Prodondeur de chaque noeud 	Q4 
void arbre::profondeur() {		profondeur(racine, 1); }
void arbre::profondeur(noeud * p, int prof) {
  if (p == NULL)    { cout << '#'; return ; }
    cout << '(';
    profondeur(p -> fg, prof + 1);
    cout << ",<" << p -> info << ',' << prof << ">,";
    profondeur(p -> fd, prof + 1);
    cout << ')';
}
//----------------------------------------------------- Hauteur d un arbre	Q5 
// 1 argument avec calcul de la hauteur en remontant ; recursivite non Terminale
//------------------------------------------------------------ 
int arbre::hauteur1() {	return hauteur1(racine); }
int arbre::hauteur1(noeud * p) {
	int h1, h2;
	if (p == NULL)		return 0;
	h1 = hauteur1(p -> fg) + 1; 	h2 = hauteur1(p -> fd) + 1;
	if (h1 > h2)		return h1;
					return h2;
}
//----------------------------------------------------- Hauteur d un arbre	Q5 
// 2 arguments et calcul de la hauteur en descendant ; recursivite non Terminale
//------------------------------------------------------------- 
int arbre::hauteur2() {	return hauteur2(racine,0);  }
int arbre::hauteur2(noeud * p, int h) {
	int h1, h2;
	if (p == NULL)		return h;
	h1 = hauteur2(p -> fg, h);		h2 = hauteur2(p -> fd, h);
	if (h1 > h2)		return h1 + 1;
					return h2 + 1;
}
//----------Variante recursive Terminale -------------- Hauteur d un arbre	Q5 
int arbre::hauteurT() { int mx =-1; hauteurT(racine,0,mx); return mx; }
void arbre::hauteurT(noeud * p, int h, int & mx) {
	if (h > mx)		mx = h ; 
	if (p == NULL)		return ;
	hauteurT (p->fg, 1+h, mx); 		hauteurT (p->fd, 1+h, mx);
}
