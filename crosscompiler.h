#ifndef CROSSCOMPILER_H
#define CROSSCOMPILER_H

#include "asm_ins.h"  // Pour la définition de struct instruction

// Déclaration du tableau des opcodes
extern const char* opcodes[9]; 

// Déclaration des fonctions
void print_instruction_binary(struct instruction* inst);
void afficher_instruction_table_binary(void);

#endif