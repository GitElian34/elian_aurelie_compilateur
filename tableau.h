#ifndef TABLEAU_H
#define TABLEAU_H
#define TAILLE_TABLEAU 256
#define INT_NULL  2222222
#include <stdio.h>


struct symbole {
    char *name;
    int adresse;
    int depth;
    int value;
};

// Déclarations externes (sans allocation mémoire)
extern struct symbole symbol_table[TAILLE_TABLEAU];
extern int taille_actuelle;
extern int taille_fin; 
extern int current_depth;
int get_value_by_name(const char *name);
int get_adresse_by_name(const char *name);
int get_value_by_adresse(int adresse);
void set_value_by_name(const char *name,int value );
void initialiser_symbol_table();
void afficher_symbol_table();
int getTailleDeb() ; 
int getTailleFin(); 
void ajouter_element_deb(char * val,int value);
void ajouter_element_fin(char * val,int value);
void supprimer_element_debut( char * val) ; 
void supprimer_element_fin( char * val) ; 
void supprimer_par_profondeur(int seuil_depth);
void supprimer_dernier_element();

#endif // TABLEAU_H
