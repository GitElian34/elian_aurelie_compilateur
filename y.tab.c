/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "compilateur.y"

#include <stdlib.h>
#include <stdio.h>
#include "tableau.h"
#include "asm_ins.h"


void yyerror(char *s);
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

#line 100 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    tID = 279,                     /* tID  */
    tIF = 280,                     /* tIF  */
    tWHILE = 281,                  /* tWHILE  */
    tNB = 282                      /* tNB  */
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
#define tID 279
#define tIF 280
#define tWHILE 281
#define tNB 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "compilateur.y"
 int nb; 
int ligne2;
 int ligne;
  char name[128];
   

#line 214 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tINT = 3,                       /* tINT  */
  YYSYMBOL_tOP = 4,                        /* tOP  */
  YYSYMBOL_tCP = 5,                        /* tCP  */
  YYSYMBOL_tOB = 6,                        /* tOB  */
  YYSYMBOL_tCB = 7,                        /* tCB  */
  YYSYMBOL_tAS = 8,                        /* tAS  */
  YYSYMBOL_tSEM = 9,                       /* tSEM  */
  YYSYMBOL_tCOMA = 10,                     /* tCOMA  */
  YYSYMBOL_tPLUS = 11,                     /* tPLUS  */
  YYSYMBOL_tMINUS = 12,                    /* tMINUS  */
  YYSYMBOL_tDIV = 13,                      /* tDIV  */
  YYSYMBOL_tMUL = 14,                      /* tMUL  */
  YYSYMBOL_tELSE = 15,                     /* tELSE  */
  YYSYMBOL_tOR = 16,                       /* tOR  */
  YYSYMBOL_tAND = 17,                      /* tAND  */
  YYSYMBOL_tVOID = 18,                     /* tVOID  */
  YYSYMBOL_tEQ = 19,                       /* tEQ  */
  YYSYMBOL_tINFOREQ = 20,                  /* tINFOREQ  */
  YYSYMBOL_tSUP = 21,                      /* tSUP  */
  YYSYMBOL_tSUPOREQ = 22,                  /* tSUPOREQ  */
  YYSYMBOL_tINF = 23,                      /* tINF  */
  YYSYMBOL_tID = 24,                       /* tID  */
  YYSYMBOL_tIF = 25,                       /* tIF  */
  YYSYMBOL_tWHILE = 26,                    /* tWHILE  */
  YYSYMBOL_tNB = 27,                       /* tNB  */
  YYSYMBOL_YYACCEPT = 28,                  /* $accept  */
  YYSYMBOL_Program = 29,                   /* Program  */
  YYSYMBOL_Funs = 30,                      /* Funs  */
  YYSYMBOL_Fun = 31,                       /* Fun  */
  YYSYMBOL_32_1 = 32,                      /* $@1  */
  YYSYMBOL_Args = 33,                      /* Args  */
  YYSYMBOL_ArgsM = 34,                     /* ArgsM  */
  YYSYMBOL_Body = 35,                      /* Body  */
  YYSYMBOL_36_2 = 36,                      /* $@2  */
  YYSYMBOL_37_3 = 37,                      /* $@3  */
  YYSYMBOL_Lins = 38,                      /* Lins  */
  YYSYMBOL_39_4 = 39,                      /* $@4  */
  YYSYMBOL_Ins = 40,                       /* Ins  */
  YYSYMBOL_Aff = 41,                       /* Aff  */
  YYSYMBOL_42_5 = 42,                      /* $@5  */
  YYSYMBOL_Decla = 43,                     /* Decla  */
  YYSYMBOL_44_6 = 44,                      /* $@6  */
  YYSYMBOL_Decla1 = 45,                    /* Decla1  */
  YYSYMBOL_DeclaS = 46,                    /* DeclaS  */
  YYSYMBOL_If = 47,                        /* If  */
  YYSYMBOL_48_7 = 48,                      /* $@7  */
  YYSYMBOL_49_8 = 49,                      /* $@8  */
  YYSYMBOL_50_9 = 50,                      /* $@9  */
  YYSYMBOL_Else = 51,                      /* Else  */
  YYSYMBOL_52_10 = 52,                     /* $@10  */
  YYSYMBOL_While = 53,                     /* While  */
  YYSYMBOL_54_11 = 54,                     /* $@11  */
  YYSYMBOL_55_12 = 55,                     /* $@12  */
  YYSYMBOL_E = 56                          /* E  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   104

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  87

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    54,    54,    56,    56,    58,    58,    60,
      60,    62,    62,    62,    64,    64,    64,    67,    70,    71,
      72,    74,    74,    82,    82,    85,    91,   103,   103,   106,
     106,   108,   106,   117,   117,   118,   120,   120,   120,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tINT", "tOP", "tCP",
  "tOB", "tCB", "tAS", "tSEM", "tCOMA", "tPLUS", "tMINUS", "tDIV", "tMUL",
  "tELSE", "tOR", "tAND", "tVOID", "tEQ", "tINFOREQ", "tSUP", "tSUPOREQ",
  "tINF", "tID", "tIF", "tWHILE", "tNB", "$accept", "Program", "Funs",
  "Fun", "$@1", "Args", "ArgsM", "Body", "$@2", "$@3", "Lins", "$@4",
  "Ins", "Aff", "$@5", "Decla", "$@6", "Decla1", "DeclaS", "If", "$@7",
  "$@8", "$@9", "Else", "$@10", "While", "$@11", "$@12", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-24)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       0,   -65,     6,   -65,     0,   -11,   -65,   -65,    34,    50,
      36,    79,    51,   -65,    82,   -65,   -65,    80,    63,   -65,
      51,    81,   -65,    83,    -3,   -65,   -65,   -65,    81,   -65,
      65,   -65,    88,   -65,   -65,    89,    90,   -65,    84,    71,
     -22,   -22,   -22,    91,    86,   -65,   -65,    -4,    28,    43,
     -22,    71,    92,   -65,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -65,   -65,    56,    86,   -65,   -65,    45,
      45,   -65,   -65,    23,    60,    60,    60,    60,   -65,   -65,
     -65,   -65,    85,   -65,   -65,   -65,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     0,     2,     4,     0,     1,     3,     0,     8,
       0,     0,    10,    11,     0,     7,     6,     0,     0,    12,
      10,    14,     9,     0,    21,    13,    29,    36,    14,    17,
       0,    20,     0,    18,    19,     0,     0,    15,     0,     0,
       0,     0,     0,    25,    27,    49,    48,     0,     0,     0,
       0,     0,     0,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,    22,    26,    27,    24,    11,    39,
      41,    42,    40,    43,    47,    44,    45,    46,    11,    28,
      31,    38,    35,    33,    32,    11,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,    93,   -65,   -65,   -65,    78,   -64,   -65,   -65,
      74,   -65,   -65,   -65,   -65,   -65,   -65,    52,    38,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,     5,    11,    15,    16,    17,    21,
      23,    24,    28,    29,    30,    31,    32,    44,    52,    33,
      35,    68,    82,    84,    85,    34,    36,    78,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
     -23,    53,    45,     1,    80,    46,     6,    54,    55,    56,
      57,    48,    49,     8,    81,    58,    59,    60,    61,    62,
      65,    86,    26,    27,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    54,    55,    56,    57,     9,    54,
      55,    56,    57,    59,    60,    61,    62,    58,    59,    60,
      61,    62,    64,    10,    54,    55,    56,    57,    56,    57,
      12,    14,    58,    59,    60,    61,    62,    54,    55,    56,
      57,    54,    55,    56,    57,    58,    59,    60,    61,    62,
     -24,   -24,   -24,   -24,    13,    18,    19,    20,   -16,    38,
      25,    39,    42,    40,    41,    43,    51,     7,    22,    50,
      83,    67,    37,    66,    79
};

static const yytype_int8 yycheck[] =
{
       3,     5,    24,     3,    68,    27,     0,    11,    12,    13,
      14,    41,    42,    24,    78,    19,    20,    21,    22,    23,
      50,    85,    25,    26,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     5,    11,    12,    13,    14,     4,    11,
      12,    13,    14,    20,    21,    22,    23,    19,    20,    21,
      22,    23,     9,     3,    11,    12,    13,    14,    13,    14,
      24,    10,    19,    20,    21,    22,    23,    11,    12,    13,
      14,    11,    12,    13,    14,    19,    20,    21,    22,    23,
      20,    21,    22,    23,     5,     3,     6,    24,     7,    24,
       7,     3,     8,     4,     4,    24,    10,     4,    20,     8,
      15,     9,    28,    51,    66
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    29,    30,    31,    32,     0,    30,    24,     4,
       3,    33,    24,     5,    10,    34,    35,    36,     3,     6,
      24,    37,    34,    38,    39,     7,    25,    26,    40,    41,
      42,    43,    44,    47,    53,    48,    54,    38,    24,     3,
       4,     4,     8,    24,    45,    24,    27,    56,    56,    56,
       8,    10,    46,     5,    11,    12,    13,    14,    19,    20,
      21,    22,    23,     5,     9,    56,    45,     9,    49,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    55,    46,
      35,    35,    50,    15,    51,    52,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    29,    30,    30,    32,    31,    33,    33,    34,
      34,    36,    37,    35,    39,    38,    38,    40,    40,    40,
      40,    42,    41,    44,    43,    45,    45,    46,    46,    48,
      49,    50,    47,    52,    51,    51,    54,    55,    53,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     7,     3,     0,     4,
       0,     0,     0,     5,     0,     3,     0,     1,     1,     1,
       1,     0,     5,     0,     5,     1,     3,     0,     3,     0,
       0,     0,     9,     0,     3,     0,     0,     0,     7,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* $@1: %empty  */
#line 56 "compilateur.y"
           {printf("function1!\n"); }
#line 1303 "y.tab.c"
    break;

  case 6: /* Fun: tINT $@1 tID tOP Args tCP Body  */
#line 56 "compilateur.y"
                                                            {printf("function!\n"); }
#line 1309 "y.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 62 "compilateur.y"
       {incr_depth();printf("body1!\n");}
#line 1315 "y.tab.c"
    break;

  case 12: /* $@3: %empty  */
#line 62 "compilateur.y"
                                            {incr_depth();}
#line 1321 "y.tab.c"
    break;

  case 13: /* Body: $@2 tOB $@3 Lins tCB  */
#line 62 "compilateur.y"
                                                                     {afficher_tableau();afficher_instruction_table();supprimer_par_profondeur(current_depth);decr_depth(); }
#line 1327 "y.tab.c"
    break;

  case 14: /* $@4: %empty  */
#line 64 "compilateur.y"
       {printf("instruc");}
#line 1333 "y.tab.c"
    break;

  case 16: /* Lins: %empty  */
#line 64 "compilateur.y"
                                     {printf("instruc");}
#line 1339 "y.tab.c"
    break;

  case 21: /* $@5: %empty  */
#line 74 "compilateur.y"
      {printf("instruc1");}
#line 1345 "y.tab.c"
    break;

  case 22: /* Aff: $@5 tID tAS E tSEM  */
#line 74 "compilateur.y"
                                         {
                 
                printf("Ajout de la variable %s au tableau\n", (yyvsp[-3].name));
                ajouter_instruction("COP",-1, get_adresse_by_name((yyvsp[-3].name)), getTailleFin()); ;set_value_by_name((yyvsp[-3].name),get_value_by_adresse(getTailleFin()+1) );
                //assembleur different
            
            }
#line 1357 "y.tab.c"
    break;

  case 23: /* $@6: %empty  */
#line 82 "compilateur.y"
        {printf("instruc2");}
#line 1363 "y.tab.c"
    break;

  case 25: /* Decla1: tID  */
#line 85 "compilateur.y"
           { 
            ajouter_element_deb((yyvsp[0].name),-1) ; {
                printf("Ajout de la variable %s au tableau\n", (yyvsp[0].name));
                
            }
        }
#line 1374 "y.tab.c"
    break;

  case 26: /* Decla1: tID tAS E  */
#line 91 "compilateur.y"
                {
                
                ajouter_element_deb((yyvsp[-2].name),get_value_by_adresse(getTailleFin()+1)); {
                ajouter_instruction("COP",-1, getTailleDeb()-1, getTailleFin()); // -1 car on vient d'ajouter la variable
                printf("Ajout de la variable %s au tableau\n", (yyvsp[-2].name));
                supprimer_dernier_element() ;
                //printf("La taille du tableau est :  %d     \n", getTailleDeb());
                
                //assembleur different
            }
        }
#line 1390 "y.tab.c"
    break;

  case 29: /* $@7: %empty  */
#line 106 "compilateur.y"
        {;afficher_tableau();}
#line 1396 "y.tab.c"
    break;

  case 30: /* $@8: %empty  */
#line 106 "compilateur.y"
                                            {ajouter_instruction("JMF",-1,getTailleFin(),-1); (yyvsp[-4].ligne) = taille_actuelle_asm; }
#line 1402 "y.tab.c"
    break;

  case 31: /* $@9: %empty  */
#line 108 "compilateur.y"
         {patch((yyvsp[-6].ligne), taille_actuelle_asm+1); printf("Le If à été PATCH à %d\n\n\n\n\n\n", (taille_actuelle_asm+1));printf("Depuis %d\n", (yyvsp[-6].ligne));}
#line 1408 "y.tab.c"
    break;

  case 32: /* If: tIF $@7 tOP E tCP $@8 Body $@9 Else  */
#line 109 "compilateur.y"
         {if( (yyvsp[0].nb)!= -1 ){
        
        patch( (yyvsp[-8].ligne), (yyvsp[0].nb) + 1);

        printf("Le If à été PATCH à BLOUBLI%d\n\n\n\n\n\n", ((yyvsp[0].nb)));
       
    }}
#line 1420 "y.tab.c"
    break;

  case 33: /* $@10: %empty  */
#line 117 "compilateur.y"
             {ajouter_instruction("JMP",-1,-1,-1);printf("111111111111111111111\n\n\n\n\n");  (yyvsp[0].nb) = taille_actuelle_asm ;}
#line 1426 "y.tab.c"
    break;

  case 34: /* Else: tELSE $@10 Body  */
#line 118 "compilateur.y"
          {patch((yyvsp[-2].nb), taille_actuelle_asm + 1);}
#line 1432 "y.tab.c"
    break;

  case 35: /* Else: %empty  */
#line 118 "compilateur.y"
                                                     {(yyval.nb) = -1;}
#line 1438 "y.tab.c"
    break;

  case 36: /* $@11: %empty  */
#line 120 "compilateur.y"
              { Set_whileStart(taille_actuelle_asm+1);}
#line 1444 "y.tab.c"
    break;

  case 37: /* $@12: %empty  */
#line 120 "compilateur.y"
                                                                    {{(yyvsp[-4].ligne2) = taille_actuelle_asm ;ajouter_instruction("JMF",-1, (yyvsp[-4].ligne2) ,-1);  } }
#line 1450 "y.tab.c"
    break;

  case 38: /* While: tWHILE $@11 tOP E tCP $@12 Body  */
#line 121 "compilateur.y"
             {ajouter_instruction("JMP",-1,Get_whileStart(),-1);
        patch((yyvsp[-6].ligne2), taille_actuelle_asm+1); }
#line 1457 "y.tab.c"
    break;

  case 39: /* E: E tPLUS E  */
#line 131 "compilateur.y"
               {ajouter_instruction("ADD",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element() ;}
#line 1463 "y.tab.c"
    break;

  case 40: /* E: E tMUL E  */
#line 132 "compilateur.y"
               {ajouter_instruction("MUL",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element();}
#line 1469 "y.tab.c"
    break;

  case 41: /* E: E tMINUS E  */
#line 133 "compilateur.y"
                 {ajouter_instruction("SOU",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element();}
#line 1475 "y.tab.c"
    break;

  case 42: /* E: E tDIV E  */
#line 134 "compilateur.y"
               {ajouter_instruction("DIV",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element();}
#line 1481 "y.tab.c"
    break;

  case 43: /* E: E tEQ E  */
#line 135 "compilateur.y"
              {ajouter_instruction("EQU",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element() ;}
#line 1487 "y.tab.c"
    break;

  case 44: /* E: E tSUP E  */
#line 136 "compilateur.y"
              {ajouter_instruction("SUP",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element() ;}
#line 1493 "y.tab.c"
    break;

  case 46: /* E: E tINF E  */
#line 138 "compilateur.y"
               {ajouter_instruction("INF",getTailleFin()+1,getTailleFin()+1,getTailleFin());supprimer_dernier_element() ;}
#line 1499 "y.tab.c"
    break;

  case 48: /* E: tNB  */
#line 140 "compilateur.y"
          {ajouter_element_fin("temp",(yyvsp[0].nb));ajouter_instruction("AFC",-1,getTailleFin(), (yyvsp[0].nb));}
#line 1505 "y.tab.c"
    break;

  case 49: /* E: tID  */
#line 141 "compilateur.y"
           {ajouter_element_fin("temp",get_value_by_name((yyvsp[0].name))); ajouter_instruction("COP",-1,getTailleFin(), get_adresse_by_name((yyvsp[0].name)));set_value_by_name((yyvsp[0].name),get_value_by_adresse(getTailleFin()+1) );
    //| tID  {ajouter_element_deb($1);ajouter_element_fin("temp"); ajouter_instruction("COP",-1, getTailleDeb(), getTailleFin());  
    }
#line 1513 "y.tab.c"
    break;


#line 1517 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 156 "compilateur.y"


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
