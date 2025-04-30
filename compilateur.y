%{
#include <stdlib.h>
#include <stdio.h>
#include "tableau.h"
#include "asm_ins.h"
void yyerror(char *s);
%}


%union { int nb; int ligne2; int ligne; char name[128]; }

%token tINT tOP tCP tOB tCB tAS tSEM tCOMA tPLUS tMINUS tDIV tMUL tELSE tOR tAND tVOID tEQ tINFOREQ tSUP tSUPOREQ tINF

%token<name> tID
%token<ligne> tIF
%token<ligne2> tWHILE


%token<nb> tNB
%left tEQ
%left tPLUS tMINUS  /* Plus faible priorité */
%left tMUL tDIV     /* Priorité plus élevée que + et - */

%start Program

%%

Program : Funs ;

Funs : Fun Funs | Fun;

Fun : tINT tID tOP Args tCP Body {printf("function %s!\n", $2); } ;

Args :  tINT tID  ArgsM | ;

ArgsM : tCOMA tINT tID ArgsM | ;

Body : tOB{incr_depth();} Lins tCB {supprimer_par_profondeur(current_depth);decr_depth(); } ;

Lins : Ins Lins | ;

Ins :
      Aff
    //| tNB Op tSEM
    //| tID Op tSEM
    | If
    | While
    | Decla ;

Aff : tID tAS E tSEM ;

Decla : tINT Decla1 DeclaS tSEM ;

Decla1 :
      tID  { 
            if (ajouter_element_deb($1)) {
                printf("Ajout de la variable %s au tableau\n", $1);
                
            }
        }
    | tID tAS E {
             if (ajouter_element_deb($1)) {
                printf("Ajout de la variable %s au tableau\n", $1);
                ajouter_instruction("COP",-1, getTailleDeb(), getTailleFin());
                //assembleur different
            }
        };

DeclaS : | tCOMA Decla1 DeclaS ;


If : tIF  tOP E  tCP  {ajouter_instruction("JMF",-1,getTailleFin(),-1); $1 = taille_actuelle_asm; }  

    Body {patch($1, taille_actuelle_asm+1); }
    Else {if( $<nb>8!= -1 ){
        patch( $1, $<nb>8+1);
    }};

Else : tELSE {ajouter_instruction("JMP",-1,-1,-1);  $<nb>1 = taille_actuelle_asm;}    
      Body{patch($<nb>1, taille_actuelle_asm + 1);} |{$<nb>$ = -1;}  // est ce que $1 est reconnu ??????

While : tWHILE tOP E  tCP  {{ajouter_instruction("JMF",-1,getTailleFin(),-1); $1 = taille_actuelle_asm; } }  
        Body {ajouter_instruction("JMP",-1,$1,-1);
        patch($1, taille_actuelle_asm+1); } ;







E :   tNB {ajouter_element_fin("temp");}
    | tID  {ajouter_element_debut($1);ajouter_element_fin("temp"); ajouter_instruction("COP",-1, getTailleDeb(), getTailleFin()); 
    }
    | E tPLUS E {ajouter_instruction("ADD",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element() ;}
    | E tMUL E {ajouter_instruction("MUL",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element();}
    | E tMINUS E {ajouter_instruction("SOU",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element();}
    | E tDIV E {ajouter_instruction("DIV",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element();}
    | E tEQ E {ajouter_instruction("EQU",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element() ;}
    | E tSUP E{ajouter_instruction("SUP",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element() ;}
    | E tSUPOREQ E
    | E tINF E {ajouter_instruction("INF",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element() ;}
    | E tINFOREQ E
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