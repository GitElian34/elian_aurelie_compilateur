#ifndef ASM_H
#define ASM_H

#include <stdio.h>

#define TAILLE_TABLEAU 256

// Déclaration du tableau et de la taille actuelle
struct instruction {
    char *name;
    int res;
    int nb1;
    int nb2;
};

// 2. Ensuite déclarer le tableau

extern int while_start;
extern struct instruction instruction_table[TAILLE_TABLEAU];
extern int taille_actuelle_asm;

// Fonctions pour gérer le tableau
void initialiser_instruction_table();
int Get_whileStart(void);
void Set_whileStart(int);
void afficher_instruction_table();
void ajouter_instruction(char * val, int resultat, int nbre1, int nbre2);
void supprimer_instruction ( char * val) ; 
void patch(int index, int valeur);

#endif // TABLEAU_H
