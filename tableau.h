#ifndef TABLEAU_H
#define TABLEAU_H
#define TAILLE_TABLEAU 256
#include <stdio.h>


struct symbole {
    char *name;
    int adresse;
    int depth;
};

// Déclarations externes (sans allocation mémoire)
extern struct symbole symbol_table[TAILLE_TABLEAU];
extern int taille_actuelle;
extern int taille_fin; 
extern int current_depth;


void initialiser_tableau();
void afficher_tableau();
int getTailleDeb() ; 
int getTailleFin(); 
void ajouter_element_deb(char * val);
void ajouter_element_fin(char * val);
void supprimer_element_debut( char * val) ; 
void supprimer_element_fin( char * val) ; 
void supprimer_par_profondeur(int seuil_depth);
void supprimer_dernier_element();

#endif // TABLEAU_H
