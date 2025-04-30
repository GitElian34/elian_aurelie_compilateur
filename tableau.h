#ifndef TABLEAU_H
#define TABLEAU_H

#include <stdio.h>


// Fonctions pour gérer le tableau
int current_depth ;
void initialiser_tableau();
void afficher_tableau();
int getTailleDeb() ; 
int getTailleFin(); 
int ajouter_element_deb(char val[15]);
int ajouter_element_fin(char val[15]);
int supprimer_element_debut( char val[15]) ; 
int supprimer_element_fin( char val[15]) ; 
void supprimer_par_profondeur(int seuil_depth);


#endif // TABLEAU_H
