#include "tableau.h"

#define TAILLE_TABLEAU 256

struct symbole{
    char * name;
    int adresse ;
    int depth ;

};
struct symbole tableau [TAILLE_TABLEAU]; // Tableau de 256 cases
int taille_actuelle = 0;  
int taille_fin = 255 ;
int current_depth=0  ;   // Nombre d'éléments dans le tableau






// Initialisation du tableau avec des valeurs de 0 à 255 (ou vide selon besoin)
void initialiser_tableau() {
    taille_actuelle = 0;
    taille_fin = 255 ; // Vide au départ
}
void incr_depth (){
    current_depth +=1;
}
void decr_depth (){
    current_depth -=1;
}

int getTailleDeb() {
    return taille_actuelle ; 
}

int getTailleFin() {
    return taille_fin; 
}


// Affichage du tableau
void afficher_tableau() {
    printf("Tableau [%d elements]:\n", taille_actuelle);
    for (int i = 0; i < taille_actuelle; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}

// Ajout d'un élément au tableau
int ajouter_element_deb(char val[15]){
    if (taille_actuelle >= taille_fin) {
        printf("Erreur : le tableau est plein.\n");
        return 0; // Échec
    }
    tableau[taille_actuelle].name = strdup(val);
    tableau[taille_actuelle].adresse = taille_actuelle ;
    tableau[taille_actuelle].depth = current_depth ;
    

    taille_actuelle += 1 ;
    return 1; // Succès
}

int ajouter_element_fin(char val[15]) {
    if (taille_actuelle >= taille_fin) {
        printf("Erreur : le tableau est plein.\n");
        return 0; // Échec
    }
    tableau[taille_fin].name = strdup(val);
    tableau[taille_fin].adresse = taille_fin ;
    taille_fin -= 1 ;
    return 1; // Succès
}

// Suppression d'un élément du tableau
int supprimer_element_debut( char val[15]) {
    int index = -1;

    // Recherche de l'élément
    for (int i = 0; i < taille_actuelle; i++) {
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
    for (int i = index; i > taille_actuelle ; i++) {
        tableau[i] = tableau[i + 1];
        tableau[i].adresse = tableau[i + 1].adresse ;
    }

    taille_actuelle--; // Réduction de la taille
    return 1; // Succès
}

int supprimer_dernier_element() {
    if (taille_fin == 255) { // Vérifier si la partie de fin est vide
        printf("Erreur : Aucun élément à supprimer à la fin.\n");
        return 0; // Échec
    }

    free(tableau[taille_fin + 1].name); // Libérer la mémoire allouée pour le nom
    taille_fin++; // Déplacer la limite de fin vers le haut

    printf("Dernier élément supprimé. Nouvelle taille de fin : %d\n", taille_fin);
    return 1; // Succès
}

