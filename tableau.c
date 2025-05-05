#include "tableau.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TAILLE_TABLEAU 256


struct symbole symbol_table[TAILLE_TABLEAU]; // Tableau de 256 cases
int taille_actuelle = 0;  
int taille_fin = 255;
int current_depth = 0;   // Nombre d'éléments dans le tableau

// Initialisation du tableau avec des valeurs de 0 à 255 (ou vide selon besoin)
void initialiser_tableau() {
    taille_actuelle = 0;
    taille_fin = 255; // Vide au départ
}

void incr_depth() {
    current_depth += 1;
}

void decr_depth() {
    current_depth -= 1;
}

int getTailleDeb() {
    return taille_actuelle; 
}

int getTailleFin() {
    return taille_fin; 
}

// Affichage du tableau
void afficher_tableau() {
    printf("Tableau [%d elements]:\n", taille_actuelle);
    for (int i = 0; i < taille_actuelle; i++) {
        printf("Nom: %s, Adresse: %d, Profondeur: %d\n", 
            symbol_table[i].name, symbol_table[i].adresse, symbol_table[i].depth);
    }
    printf("\n");
}

// Ajout d'un élément au début du tableau
void ajouter_element_deb(char *val) {
    if (taille_actuelle >= taille_fin) {
        printf("Erreur : le tableau est plein.\n");
         // Échec
    }
    symbol_table[taille_actuelle].name = strdup(val);
    symbol_table[taille_actuelle].adresse = taille_actuelle;
    symbol_table[taille_actuelle].depth = current_depth;
    
    taille_actuelle += 1;
     // Succès
}

// Ajout d'un élément à la fin du tableau
void ajouter_element_fin(char *val) {
    if (taille_actuelle >= taille_fin) {
        printf("Erreur : le tableau est plein.\n");
         // Échec
    }
    symbol_table[taille_fin].name = strdup(val);
    symbol_table[taille_fin].adresse = taille_fin;
    symbol_table[taille_fin].depth = current_depth;
    taille_fin -= 1;
     // Succès
}

void supprimer_par_profondeur(int seuil_depth) {
    // Suppression dans la partie début (variables locales)
    int i = 0;
    while (i < taille_actuelle) {
        if (symbol_table[i].depth >= seuil_depth) {
            // Libération de la mémoire allouée pour le nom
            free(symbol_table[i].name);
            
            // Décalage des éléments vers la gauche
            for (int j = i; j < taille_actuelle - 1; j++) {
                symbol_table[j] = symbol_table[j + 1];
                symbol_table[j].adresse = j;
            }
            taille_actuelle--;
        } else {
            i++;
        }
    }

    // Suppression dans la partie fin (arguments)
    int elements_supprimes = 0;
    for (int pos = taille_fin + 1; pos < TAILLE_TABLEAU; pos++) {
        if (symbol_table[pos].depth == seuil_depth) {
            // Libération de la mémoire allouée pour le nom
            free(symbol_table[pos].name);
            elements_supprimes++;
        } else if (elements_supprimes > 0) {
            // Décalage vers le haut des éléments restants
            symbol_table[pos - elements_supprimes] = symbol_table[pos];
            symbol_table[pos - elements_supprimes].adresse = pos - elements_supprimes;
        }
    }

    // Réajustement de taille_fin
    if (elements_supprimes > 0) {
        taille_fin += elements_supprimes;
    }

    printf("Suppression profondeur %d: %d locaux + %d arguments\n", 
           seuil_depth, i, elements_supprimes);
}
// Suppression d'un élément au début du tableau
void supprimer_element_debut(char *val) {
    int index = -1;

    // Recherche de l'élément
    for (int i = 0; i < taille_actuelle; i++) {
        if (strcmp(symbol_table[i].name, val) == 0) {  // Modification: utilisation de strcmp
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Erreur : valeur non trouvée.\n");
         // Échec
    }

    free(symbol_table[index].name); // Libération de la mémoire

    // Décalage des éléments pour combler le trou
    for (int i = index; i < taille_actuelle - 1; i++) {
        symbol_table[i] = symbol_table[i + 1];
        symbol_table[i].adresse = i; // Mise à jour de l'adresse
    }

    taille_actuelle--; // Réduction de la taille
   // Succès
}

// Suppression du  dernier élément
void supprimer_dernier_element(){
    if (taille_fin == 255) { // Vérifier si la partie de fin est vide
        printf("Erreur : Aucun élément à supprimer à la fin.\n");
         // Échec
    }

    free(symbol_table[taille_fin + 1].name); // Libérer la mémoire allouée pour le nom
    taille_fin++; // Déplacer la limite de fin vers le haut

    printf("Dernier élément supprimé. Nouvelle taille de fin : %d\n", taille_fin);
     // Succès
}