#include "asm_ins.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct instruction instruction_table[TAILLE_TABLEAU]; // Tableau de 256 cases
int taille_actuelle_asm = 0;  

// Initialisation du tableau avec des valeurs de 0 à 255 (ou vide selon besoin)
void initialiser_instruction_table() {
    taille_actuelle_asm = 0; 
    // Vide au départ
}

// Affichage du tableau
void afficher_instruction_table() {
    printf("##############################Tableau d'instructions##########################################\n");
    printf("Tableau [%d elements]:\n", taille_actuelle_asm);
    for (int i = 0; i < taille_actuelle_asm; i++) {
        printf("%s (res: %d, nb1: %d, nb2: %d)\n", 
            instruction_table[i].name, instruction_table[i].res, instruction_table[i].nb1, instruction_table[i].nb2);
    }
    printf("\n");
}

void patch(int line_if, int new_line) {
    instruction_table[line_if].nb2 = new_line;
}

// Ajout d'un élément au tableau
void ajouter_instruction(char *val, int resultat, int nbre1, int nbre2) {
    if (taille_actuelle_asm >= TAILLE_TABLEAU) {
        printf("Erreur : le tableau est plein.\n");
        return;
    }
    instruction_table[taille_actuelle_asm].name = strdup(val);
    instruction_table[taille_actuelle_asm].res = resultat;
    instruction_table[taille_actuelle_asm].nb1 = nbre1;
    instruction_table[taille_actuelle_asm].nb2 = nbre2;
    taille_actuelle_asm += 1;
}

// Suppression d'un élément du tableau
void supprimer_instruction(char *val) {
    int index = -1;

    // Recherche de l'élément
    for (int i = 0; i < taille_actuelle_asm; i++) {
        if (strcmp(instruction_table[i].name, val) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Erreur : valeur non trouvée.\n");
         // Échec
    }

    // Libération de la mémoire allouée pour le nom
    free(instruction_table[index].name);

    // Décalage des éléments pour combler le trou
    for (int i = index; i < taille_actuelle_asm - 1; i++) {
        instruction_table[i] = instruction_table[i + 1];
    }

    taille_actuelle_asm--; // Réduction de la taille
     // Succès
}