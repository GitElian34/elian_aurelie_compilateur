#ifndef TABLEAU_H
#define TABLEAU_H

#include <stdio.h>

#define TAILLE_TABLEAU 256


// Déclaration du tableau et de la taille actuelle
extern struct instruction ; 
extern struct instruction tableau[TAILLE_TABLEAU];
extern int taille_actuelle_asm;

// Fonctions pour gérer le tableau
void initialiser_tableau();
void afficher_tableau();
int ajouter_instruction(char val[32], int resultat, int nbre1, int nbre2);
int supprimer_instruction ( char val[32]) ; 


#endif // TABLEAU_H
