/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tINT = 258,                    /* tINT  */
    tOP = 259,                     /* tOP  */
    tCP = 260,                     /* tCP  */
    tOB = 261,                     /* tOB  */
    tCB = 262,                     /* tCB  */
    tAS = 263,                     /* tAS  */
    tSEM = 264,                    /* tSEM  */
    tCOMA = 265,                   /* tCOMA  */
    tPLUS = 266,                   /* tPLUS  */
    tMINUS = 267,                  /* tMINUS  */
    tDIV = 268,                    /* tDIV  */
    tMUL = 269,                    /* tMUL  */
    tELSE = 270,                   /* tELSE  */
    tOR = 271,                     /* tOR  */
    tAND = 272,                    /* tAND  */
    tVOID = 273,                   /* tVOID  */
    tEQ = 274,                     /* tEQ  */
    tINFOREQ = 275,                /* tINFOREQ  */
    tSUP = 276,                    /* tSUP  */
    tSUPOREQ = 277,                /* tSUPOREQ  */
    tINF = 278,                    /* tINF  */
    tRETURN = 279,                 /* tRETURN  */
    tID = 280,                     /* tID  */
    tIF = 281,                     /* tIF  */
    tWHILE = 282,                  /* tWHILE  */
    tNB = 283                      /* tNB  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define tINT 258
#define tOP 259
#define tCP 260
#define tOB 261
#define tCB 262
#define tAS 263
#define tSEM 264
#define tCOMA 265
#define tPLUS 266
#define tMINUS 267
#define tDIV 268
#define tMUL 269
#define tELSE 270
#define tOR 271
#define tAND 272
#define tVOID 273
#define tEQ 274
#define tINFOREQ 275
#define tSUP 276
#define tSUPOREQ 277
#define tINF 278
#define tRETURN 279
#define tID 280
#define tIF 281
#define tWHILE 282
#define tNB 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "compilateur.y"
 int nb; 
int ligne2;
 int ligne;
  char name[128];
   

#line 130 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
