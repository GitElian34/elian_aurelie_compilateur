%{
#include "y.tab.h"
%}

%option noyywrap
%option noinput
%option nounput

D   [0-9]
%%
	

int               return tINT;
	/*
	
	*/
{D}+              {yylval.nb = atoi(yytext); return tNB; }
\r?\n    { }  /* Gère à la fois Unix et Windows */
" "               { }
\t                { }

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
return			  return tRETURN ;
[a-z]+            { strcpy(yylval.name, yytext); return tID; }
	
.                 { printf(" ERROR[%s]\n", yytext); exit(2); }

%%



