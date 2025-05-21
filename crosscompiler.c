#include <stdio.h>
#include <string.h>
#include "asm_ins.h"
#include "crosscompiler.h"

const char* opcodes[9] = {
    NULL,  // Index 0 inutilisé
    "ADD", "MUL", "SOU", "DIV",
    "COP", "AFC", "LOAD", "STORE"  // Index 1-8
};

int get_opcode(const char* name) {
    for (int i = 1; i <= 8; i++) {
        if (strcmp(name, opcodes[i]) == 0) {
            return i;
        }
    }
    return 0; // NOP si non trouvé
}

void print_instruction_binary(struct instruction* inst) {
    int opcode = get_opcode(inst->name);
    
    switch(opcode) {
        case 1: case 2: case 3: case 4:  // ADD, MUL, SOU, DIV
            printf("%02X %02X %02X %02X\n", 
                   opcode, inst->res, inst->nb1, inst->nb2);
            break;
            
        case 5: case 6: case 7: case 8:  // COP, AFC, LOAD, STORE
            printf("%02X %02X %02X\n", 
                   opcode, inst->res, inst->nb1);
            break;
            
        default:
            printf("00\n");  // NOP pour les opérations inconnues
    }
}

void afficher_instruction_table_binary() {
    //printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
    printf("Format: OP A B C\n");
    
    for (int i = 0; i < taille_actuelle_asm; i++) {
        printf("%2d: ", i);
        print_instruction_binary(&instruction_table[i]);
    }
}

void generate_compact_binary() {
    FILE* output = fopen("output.bin", "w");
    if (!output) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    for (int i = 0; i < taille_actuelle_asm; i++) {
        struct instruction inst = instruction_table[i];
        char binary_str[12] = {0}; // x" + 8 chiffres + " + \0 = 11 caractères + marge
        int opcode = get_opcode(inst.name);
        
        switch(opcode) {
            case 1: case 2: case 3: case 4:  // ADD, MUL, SOU, DIV (4 opérandes)
                snprintf(binary_str, sizeof(binary_str), 
                    "x\"%02x%02x%02x%02x\"",  // Notez le \" à la fin
                    opcode, inst.res, inst.nb1, inst.nb2);
                break;
                
            case 5: case 6: case 7: case 8:  // COP, AFC, LOAD, STORE
                snprintf(binary_str, sizeof(binary_str),
                    "x\"%02x%02x%02x00\"",  // Notez le \" à la fin
                    opcode, inst.res, inst.nb1);
                break;
                
            default:  // NOP
                strcpy(binary_str, "x\"00000000\"");
        }
        
        fprintf(output, "%s%s", binary_str, (i < taille_actuelle_asm - 1) ? ",\n" : "\n");
    }
    
    fclose(output);
}