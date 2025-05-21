%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tableau.h"
#include "asm_ins.h"
#include "crosscompiler.h"

void print_instruction_binary(struct instruction * inst);
struct instruction * get_instruction_table();
void yyerror(char *s);
void generate_compact_binary(void) ;
void afficher_instruction_table_binary(void);
void afficher_tableau(void);
void incr_depth(void);
void decr_depth(void);
void supprimer_par_profondeur(int profondeur);
int getTailleDeb(void);
int getTailleFin(void);
int Get_whileStart(void);
void Set_whileStart(int);
void supprimer_dernier_element();
int get_adresse_by_name(const char *name);
int get_value_by_name(const char *name);
int get_value_by_adresse(int adresse);
void set_value_by_name(const char *name,int value );
void ajouter_element_deb(char *id,int value);
void ajouter_element_fin(char *id,int value);
void afficher_instruction_table(void);
//void supprimer_instruction ( char val[32]);
void ajouter_instruction(char * nom, int res, int op1, int op2);
void patch(int index, int valeur);
%}
%union { int nb; 
int ligne2;
 int ligne;
  char name[128];
   }

%token tINT tOP tCP tOB tCB tAS tSEM tCOMA tPLUS tMINUS tDIV tMUL tELSE tOR tAND tVOID tEQ tINFOREQ tSUP tSUPOREQ tINF tRETURN 

%token<name> tID
%token<ligne> tIF
%token<ligne2> tWHILE


%token<nb> tNB
%type <nb> Arg ArgList
%type <name> Fun FunName
%left tEQ
%nonassoc tSUP tINF tSUPOREQ tINFOREQ  /* Non-associatifs, priorité moyenne */
%left tPLUS tMINUS                      /* Priorité plus basse */
%left tMUL tDIV     /* Priorité plus élevée que + et - */

%start Program

%%

Program : Funs ;

Funs : Fun Funs | Fun;

Fun :  ReturnType FunName  tOP Args tCP Body {printf("function!\n"); } ;

FunName : tID { strcpy($$, $1); printf("Le nom de la fonction est %s\n", $1); };

ReturnType : tINT | tVOID ;

Args :  tINT tID{ 
            ajouter_element_deb($2,-1) ; {
                printf("Ajout de la variable %s au tableau\n", $2);
                
            }
        }      ArgsM | ;

ArgsM : tCOMA tINT tID{ 
            ajouter_element_deb($3,-1) ; {
                printf("Ajout de la variable %s au tableau\n", $3);
                
            }
        }
        ArgsM | ;

Arg :  tINT tID {$$ = 0;} ;

ArgList : Arg { $$ = 1; }
         | Arg tCOMA ArgList { $$ = $1 + $3; }
         | {$$ = 0;};

FuncCall : tID tOP ArgList tCP {
    // Empiler les arguments
    for(int i = 0; i < nb_args; i++) {
        ajouter_instruction("COP",  STACK_BASE + i, arg_adresses[i],-1);
    }
};

Body : {incr_depth();printf("body1!\n");}tOB{incr_depth();} Lins tCB {afficher_tableau();afficher_instruction_table();supprimer_par_profondeur(current_depth);decr_depth()
;generate_compact_binary();} ;

Lins : {printf("instruc");}Ins Lins |{printf("instruc");} ;

Return : tRETURN E tSEM

Ins :
      Aff
    //| tNB Op tSEM
    //| tID Op tSEM
    | If
    | While
    | Decla 
    |Return ;

Aff : {printf("instruc1");}tID tAS E tSEM{
                 
                printf("Ajout de la variable %s au tableau\n", $2);
                ajouter_instruction("COP", get_adresse_by_name($2), getTailleFin(),-1); ;set_value_by_name($2,get_value_by_adresse(getTailleFin()+1) );
                //assembleur different
            
            } ; //DES TRUCS A FAIRE ICI

Decla : {printf("instruc2");}tINT Decla1 DeclaS tSEM ;

Decla1 :
      tID  { 
            ajouter_element_deb($1,-1) ; {
                printf("Ajout de la variable %s au tableau\n", $1);
                
            }
        }
    | tID tAS E {
                
                ajouter_element_deb($1,get_value_by_adresse(getTailleFin()+1)); {
                ajouter_instruction("COP", getTailleDeb()-1, getTailleFin(),-1); // -1 car on vient d'ajouter la variable
                printf("Ajout de la variable %s au tableau\n", $1);
                supprimer_dernier_element() ;
                
                
                //assembleur different
            }
        };

DeclaS : | tCOMA Decla1 DeclaS ;


If : tIF{;afficher_tableau();}  tOP E  tCP  {ajouter_instruction("JMF",getTailleFin(),-1,-1); $1 = taille_actuelle_asm; }  

    Body {patch($1 - 1, taille_actuelle_asm+1); printf("Le If à été PATCH à %d\n\n\n\n\n\n", (taille_actuelle_asm+1));printf("Depuis %d\n", $1);}
    Else {if( $<nb>9!= -1 ){
        
        patch( $1 - 1 , $<nb>9 + 1);

        printf("Le If à été PATCH à %d\n\n\n\n\n\n", ($<nb>9));
       
    }};

Else : tELSE {ajouter_instruction("JMP",-1,-1,-1);printf("111111111111111111111\n\n\n\n\n");  $<nb>1 = taille_actuelle_asm ;}    
      Body{patch($<nb>1 -1, taille_actuelle_asm + 1);} |{$<nb>$ = -1;}  // est ce que $1 est reconnu ??????

While : tWHILE{ Set_whileStart(taille_actuelle_asm+1);} tOP E  tCP  {{$1 = taille_actuelle_asm ;ajouter_instruction("JMF", $1, -1,-1);  } }  
        Body {ajouter_instruction("JMP",Get_whileStart(),-1,-1);
        patch($1, taille_actuelle_asm+1); } ;







E : 
     E tPLUS E {ajouter_instruction("ADD",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element() ;}
    | E tMUL E {ajouter_instruction("MUL",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element();}
    | E tMINUS E {ajouter_instruction("SOU",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element();}
    | E tDIV E {ajouter_instruction("DIV",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element();}
    | E tEQ E {ajouter_instruction("EQU",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element() ;}
    | E tSUP E{ajouter_instruction("SUP",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element() ;}
    | E tSUPOREQ E
    | E tINF E {ajouter_instruction("INF",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element() ;}
    | E tINFOREQ E
    | tNB {ajouter_element_fin("temp",$1);ajouter_instruction("AFC",getTailleFin(), $1,-1);}
    | tID  {ajouter_element_fin("temp",get_value_by_name($1)); ajouter_instruction("COP",getTailleFin(), get_adresse_by_name($1),-1);set_value_by_name($1,get_value_by_adresse(getTailleFin()+1) );
    //| tID  {ajouter_element_deb($1);ajouter_element_fin("temp"); ajouter_instruction("COP",-1, getTailleDeb(), getTailleFin());  
    }
    ;











%%

/*
%union { int nb; char var; }
%token <nb> tNB
%token <var> tID
%type <nb> Expr DivMul Terme
*/

void yyerror(char *s) { fprintf(stderr, "%s\n", s); }

int main(void) {
  yydebug=1;
  yyparse();
  return 0;
}








/* VOTRE CODE


Op : Add Op2 | Minus Op2 | Div Op2 | Mul Op2  ;

Op2 : Add Op2 {ajouter_instruction("ADD "+  )  }| Minus Op2 | Div Op2 | Mul Op2 | ;

Add : tPLUS tNB {if (ajouter_element_fin("temp")) {
        
        printf("Ajout de la variable %s a la fin du tableau\n", $2);
    }}| tPLUS tID {}   ;

Minus : tMINUS tNB {if (ajouter_element_fin("temp")) {
        printf("Ajout de la variable %s a la fin du tableau\n", $2);
    }} | tMINUS tID;

Mul: tMUL tNB {if (ajouter_element_fin("temp")) {
        printf("Ajout de la variable %s a la fin du tableau\n", $2);
    }} | tMUL tID;

Div : tDIV tNB {if (ajouter_element_fin("temp")) {
        printf("Ajout de la variable %s a la fin du tableau\n", $2);
    }} | tDIV tID;

Cond : tID MathOP | tNB MathOP | tID LogOP | tNB LogOP | ;

LogOP :  Or LogOP | And LogOP | ;

MathOP : Sup | Inf |SupEq | InfEq | Eq ;

Sup : tSUP tID | tSUP tNB ;

Inf : tINF tID | tINF tNB ;

SupEq : tSUPOREQ tID | tSUPOREQ tNB ;

InfEq : tINFOREQ tID | tINFOREQ tNB ;

Eq : tEQ tID | tEQ tNB ;

Or : tOR tID | tOR tNB ;

And : tAND tID | tAND tNB ;

E : tNB {printf("neb: %d\n", $1);} | tNB Op | tID Op | tID ;
*/