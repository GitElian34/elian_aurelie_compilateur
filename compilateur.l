%{
#include "y.tab.h"
%}

%option noyywrap
%option noinput
%option nounput

D   [0-9]
%%
	/*
	"=="              printf(" tEQ");
	"<="			  printf(" tINFOREQ");
	"<"				  printf(" tINF");
	"["               printf(" tOSQR");
	"]"               printf(" tCSQR");
	

	
	"&&"			  printf("tAND");
	"||"			  printf("tOR");
			
	while             printf(" tWHILE");
	if                printf(" tIF");
	else              printf(" tELSE");
	void              printf(" tVOID");
	*/

int               return tINT;
	/*
	
	*/
{D}+              {yylval.nb = atoi(yytext); return tNB; }

" "               { }
\t                { }
\n                { }
";"               return tSEM;
","               return tCOMA;
"="               return tAS;
"("               return tOP;
")"               return tCP;
"{"               return tOB;
"}"               return tCB;
"+"               return tPLUS;
"-"               return tMINUS;
"*"               return tMUL;
"/"               return tDIV;
"&&"			  return tAND;
"||"			  return tOR;
"=="              return tEQ;
"<="			  return  tINFOREQ;
"<"				  return  tINF ;
">="			  return  tSUPOREQ;
">"				  return  tSUP;
			
while             return tWHILE ;
if                {yylval.ligne = atoi(yytext); return tIF; }
else              {yylval.ligne2 = atoi(yytext); return tELSE; }
void              return tVOID ;

[a-z]+            { strcpy(yylval.name, yytext); return tID; }
	
.                 { printf(" ERROR[%s]\n", yytext); exit(2); }

%%

/*
int main(void) {
	yylex();
	printf("\n");
	return 0;
}
*/

