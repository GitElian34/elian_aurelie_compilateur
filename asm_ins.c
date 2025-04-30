#include "asm_ins.h"
struct instruction{
    char * name;
    int res ;
    int nb1;
    int nb2;

   

};

struct instruction tableau [TAILLE_TABLEAU]; // Tableau de 256 cases
int taille_actuelle_asm= 0;  
  // Nombre d'éléments dans le tableau

// Initialisation du tableau avec des valeurs de 0 à 255 (ou vide selon besoin)
void initialiser_tableau() {
    taille_actuelle_asm = 0;
     // Vide au départsq
}

// Affichage du tableau
void afficher_tableau() {
    printf("Tableau [%d elements]:\n", taille_actuelle_asm);
    for (int i = 0; i < taille_actuelle_asm; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}
void patch(int line_if, int new_line){
    tableau[line_if].nb2 =new_line;

}

// Ajout d'un élément au tableau
int ajouter_instruction(char val[32],int resultat, int nbre1, int nbre2){
    if (taille_actuelle_asm_asm >= TAILLE_TABLEAU) {
        printf("Erreur : le tableau est plein.\n");
        return 0; // Échec
    }
    tableau[taille_actuelle_asm].name = strdup(val);
    tableau[taille_actuelle_asm].res = resultat;
    tableau[taille_actuelle_asm].nb1 =nbre1;
    tableau[taille_actuelle_asm].nb2 = nbre2;
    taille_actuelle_asm += 1 ;
    return 1; // Succès
}


// Suppression d'un élément du tableau
int supprimer_instruction( char val[32]) {
    int index = -1;

    // Recherche de l'élément
    for (int i = 0; i < taille_actuelle_asm; i++) {
        if (tableau[i].name == val) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Erreur : valeur non trouvée.\n");
        return 0; // Échec
    }

    // Décalage des éléments pour combler le trou
    for (int i = index; i > taille_actuelle_asm ; i++) {
        tableau[i] = tableau[i + 1];

    }

    taille_actuelle_asm--; // Réduction de la taille
    return 1; // Succès
}

