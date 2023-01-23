/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDE = 258,
     NUM = 259,
     NAT_NUM = 260,
     INFTY = 261,
     SELECT = 262,
     FROM = 263,
     WHERE = 264,
     PACKAGE = 265,
     REPEAT = 266,
     SUCH = 267,
     THAT = 268,
     AS = 269,
     ALL = 270,
     DEF = 271,
     LIMIT = 272,
     ORDER = 273,
     GROUP = 274,
     BY = 275,
     MAXIMIZE = 276,
     MINIMIZE = 277,
     INPUT = 278,
     OUTPUT = 279,
     DISTINCT = 280,
     OR = 281,
     AND = 282,
     NOT = 283,
     Op = 284,
     BETWEEN = 285,
     IN_P = 286,
     AT = 287,
     COLLATE = 288,
     UMINUS = 289,
     TYPECAST = 290
   };
#endif
/* Tokens.  */
#define IDE 258
#define NUM 259
#define NAT_NUM 260
#define INFTY 261
#define SELECT 262
#define FROM 263
#define WHERE 264
#define PACKAGE 265
#define REPEAT 266
#define SUCH 267
#define THAT 268
#define AS 269
#define ALL 270
#define DEF 271
#define LIMIT 272
#define ORDER 273
#define GROUP 274
#define BY 275
#define MAXIMIZE 276
#define MINIMIZE 277
#define INPUT 278
#define OUTPUT 279
#define DISTINCT 280
#define OR 281
#define AND 282
#define NOT 283
#define Op 284
#define BETWEEN 285
#define IN_P 286
#define AT 287
#define COLLATE 288
#define UMINUS 289
#define TYPECAST 290




/* Copy the first part of user declarations.  */
#line 1 "PaQL_Grammar.y"

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <stdio.h>
#include <cmath>
#include "sql_query.hpp"
#include "sql_command.hpp"

#include "scanner.hpp"

#define YYSTYPE string

//~ #include "parser.hpp"


//#define DEBUG_ON
#ifdef DEBUG_ON
	#define debug(msg)			cerr << msg << endl;
#else
	#define debug(...)
#endif

using namespace std;

// Prototypes to keep the compiler happy
//void yyerror (const char *error);
int yylex();
void yyerror(const char *error) {
  cerr << error << endl;
} /* error handler */
//~ extern "C" {
    //~ extern int yylex();
//~ }

extern SQL_query q;
extern SQL_command c;
extern string ide;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 217 "parser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   741

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNRULES -- Number of states.  */
#define YYNSTATES  278

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    51,     2,    39,     2,     2,
      46,    47,    37,    35,    52,    36,    49,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
      30,    29,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,    40,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    32,    33,    34,    41,    42,    43,
      48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    12,    17,    20,    23,    25,
      28,    35,    42,    53,    55,    57,    60,    62,    65,    69,
      72,    74,    78,    81,    86,    91,    95,    96,    98,   101,
     103,   107,   109,   113,   115,   121,   123,   125,   127,   129,
     133,   137,   140,   141,   145,   146,   153,   155,   159,   162,
     165,   168,   172,   176,   180,   184,   188,   192,   196,   200,
     204,   209,   214,   219,   224,   228,   232,   235,   241,   248,
     250,   253,   256,   260,   264,   268,   273,   278,   283,   288,
     290,   292,   296,   300,   301,   305,   306,   309,   312,   313,
     317,   321,   322,   327,   333,   335,   337,   341,   343,   345,
     348,   351,   355,   359,   363,   367,   371,   375,   379,   383,
     387,   392,   397,   402,   407,   411,   415,   418,   424,   431,
     433,   436,   439,   443,   447,   451,   455,   459,   463,   467,
     471,   475,   480,   485,   490,   495,   497,   499,   501
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,     3,    -1,    58,    50,    -1,    51,    56,
      51,    -1,    51,    58,    50,    51,    -1,    57,    50,    -1,
       1,    50,    -1,     3,    -1,     3,    56,    -1,    16,     3,
      14,     3,     8,     3,    -1,    16,     3,    14,     4,     8,
       3,    -1,     7,    65,     8,    69,    71,    72,    77,    78,
      79,    80,    -1,     3,    -1,    37,    -1,     3,    60,    -1,
      61,    -1,    60,    61,    -1,    60,    49,    37,    -1,    49,
       3,    -1,     3,    -1,     3,    49,     3,    -1,     3,     3,
      -1,     3,    49,     3,     3,    -1,    46,    58,    47,    64,
      -1,    62,    11,     5,    -1,    -1,     3,    -1,    14,     3,
      -1,    67,    -1,    67,    52,    65,    -1,    68,    -1,    68,
      52,    66,    -1,    68,    -1,    10,    46,    70,    47,    64,
      -1,    59,    -1,    70,    -1,    62,    -1,    63,    -1,    62,
      52,    70,    -1,    63,    52,    70,    -1,     9,    85,    -1,
      -1,    12,    13,    74,    -1,    -1,     7,    74,     8,    62,
      71,    77,    -1,    76,    -1,    46,    74,    47,    -1,    15,
      74,    -1,    35,    74,    -1,    36,    74,    -1,    74,    35,
      74,    -1,    74,    36,    74,    -1,    74,    37,    74,    -1,
      74,    38,    74,    -1,    74,    39,    74,    -1,    74,    40,
      74,    -1,    74,    30,    74,    -1,    74,    31,    74,    -1,
      74,    29,    74,    -1,    74,    30,    31,    74,    -1,    74,
      53,    29,    74,    -1,    74,    30,    29,    74,    -1,    74,
      31,    29,    74,    -1,    74,    27,    74,    -1,    74,    26,
      74,    -1,    28,    74,    -1,    74,    33,    75,    27,    75,
      -1,    74,    28,    33,    75,    27,    75,    -1,    76,    -1,
      35,    75,    -1,    36,    75,    -1,    75,    30,    75,    -1,
      75,    31,    75,    -1,    75,    29,    75,    -1,    75,    53,
      29,    75,    -1,    75,    30,    31,    75,    -1,    75,    30,
      29,    75,    -1,    75,    31,    29,    75,    -1,    87,    -1,
      81,    -1,    46,    73,    47,    -1,    19,    20,    66,    -1,
      -1,    18,    20,    66,    -1,    -1,    21,    76,    -1,    22,
      76,    -1,    -1,    17,    23,     5,    -1,    17,    24,     5,
      -1,    -1,    82,    46,    83,    47,    -1,    82,    46,    25,
      83,    47,    -1,     3,    -1,    84,    -1,    83,    52,    84,
      -1,    87,    -1,    87,    -1,    35,    85,    -1,    36,    85,
      -1,    85,    35,    85,    -1,    85,    36,    85,    -1,    85,
      37,    85,    -1,    85,    38,    85,    -1,    85,    39,    85,
      -1,    85,    40,    85,    -1,    85,    30,    85,    -1,    85,
      31,    85,    -1,    85,    29,    85,    -1,    85,    53,    29,
      85,    -1,    85,    30,    31,    85,    -1,    85,    30,    29,
      85,    -1,    85,    31,    29,    85,    -1,    85,    27,    85,
      -1,    85,    26,    85,    -1,    28,    85,    -1,    85,    33,
      86,    27,    86,    -1,    85,    28,    33,    86,    27,    86,
      -1,    87,    -1,    35,    86,    -1,    36,    86,    -1,    86,
      35,    86,    -1,    86,    36,    86,    -1,    86,    37,    86,
      -1,    86,    38,    86,    -1,    86,    39,    86,    -1,    86,
      40,    86,    -1,    86,    30,    86,    -1,    86,    31,    86,
      -1,    86,    29,    86,    -1,    86,    53,    29,    86,    -1,
      86,    30,    31,    86,    -1,    86,    30,    29,    86,    -1,
      86,    31,    29,    86,    -1,    59,    -1,     4,    -1,     5,
      -1,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   131,   135,   139,   143,   146,   150,   150,
     152,   153,   157,   185,   191,   195,   203,   204,   205,   207,
     222,   223,   224,   225,   226,   234,   236,   237,   238,   245,
     246,   249,   250,   254,   255,   260,   266,   268,   269,   270,
     271,   277,   281,   286,   290,   295,   312,   315,   318,   321,
     323,   326,   328,   330,   332,   334,   336,   339,   341,   343,
     345,   347,   349,   351,   353,   355,   357,   359,   364,   370,
     372,   374,   376,   378,   380,   382,   384,   386,   388,   392,
     393,   394,   400,   401,   404,   405,   408,   409,   410,   413,
     414,   415,   426,   429,   437,   440,   444,   450,   471,   482,
     484,   486,   488,   490,   492,   494,   496,   498,   500,   502,
     504,   506,   508,   510,   512,   514,   516,   524,   533,   551,
     555,   557,   559,   561,   563,   565,   567,   569,   571,   573,
     575,   576,   577,   578,   580,   584,   585,   586,   587
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDE", "NUM", "NAT_NUM", "INFTY",
  "SELECT", "FROM", "WHERE", "PACKAGE", "REPEAT", "SUCH", "THAT", "AS",
  "ALL", "DEF", "LIMIT", "ORDER", "GROUP", "BY", "MAXIMIZE", "MINIMIZE",
  "INPUT", "OUTPUT", "DISTINCT", "OR", "AND", "NOT", "'='", "'<'", "'>'",
  "Op", "BETWEEN", "IN_P", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "AT",
  "COLLATE", "UMINUS", "'['", "']'", "'('", "')'", "TYPECAST", "'.'",
  "';'", "'#'", "','", "'!'", "$accept", "start", "garbage", "command",
  "query", "columnref", "indirection", "indirection_el", "relation",
  "relation_repeat", "named", "select_list", "attr_list", "select_item",
  "attr_item", "from_list", "relation_list", "where_clause",
  "such_that_clause", "st_subquery", "a_st_expr", "b_st_expr", "c_st_expr",
  "group_by_clause", "order_by_clause", "objective_clause", "limit_clause",
  "func", "func_name", "func_arg_list", "func_arg_expr", "a_expr",
  "b_expr", "c_expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    61,
      60,    62,   284,   285,   286,    43,    45,    42,    47,    37,
      94,   287,   288,   289,    91,    93,    40,    41,   290,    46,
      59,    35,    44,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    55,    55,    56,    56,
      57,    57,    58,    59,    59,    59,    60,    60,    60,    61,
      62,    62,    62,    62,    62,    63,    64,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    69,    70,    70,    70,
      70,    71,    71,    72,    72,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    76,    77,    77,    78,    78,    79,    79,    79,    80,
      80,    80,    81,    81,    82,    83,    83,    84,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    87,    87,    87,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     4,     2,     2,     1,     2,
       6,     6,    10,     1,     1,     2,     1,     2,     3,     2,
       1,     3,     2,     4,     4,     3,     0,     1,     2,     1,
       3,     1,     3,     1,     5,     1,     1,     1,     1,     3,
       3,     2,     0,     3,     0,     6,     1,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     4,     4,     3,     3,     2,     5,     6,     1,
       2,     2,     3,     3,     3,     4,     4,     4,     4,     1,
       1,     3,     3,     0,     3,     0,     2,     2,     0,     3,
       3,     0,     4,     5,     1,     1,     3,     1,     1,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     4,     4,     3,     3,     2,     5,     6,     1,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     4,     4,     4,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     2,     0,     0,     0,     0,     0,     0,     7,
      13,     0,    14,    35,     0,    29,    33,     0,     8,     0,
       0,     1,     6,     3,     0,    15,    16,     0,     0,     0,
       0,     9,     4,     0,    19,     0,    17,    20,     0,    37,
      38,     0,    42,    36,    30,     0,     0,     5,    18,    22,
       0,     0,     0,     0,     0,    26,     0,    44,     0,     0,
      21,    26,    25,    39,    40,    27,     0,    34,   136,   137,
     138,     0,     0,     0,   135,    41,    98,     0,    83,    10,
      11,    23,    24,    28,   116,    99,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,   115,   114,     0,   109,     0,     0,
     107,     0,   108,     0,     0,     0,   119,   101,   102,   103,
     104,   105,   106,     0,    13,     0,     0,     0,     0,     0,
      43,    46,    80,     0,    79,     0,     0,    88,     0,   112,
     111,   113,   120,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,    48,    66,    49,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,    31,
       0,     0,     0,    91,     0,   117,   130,     0,     0,   128,
       0,   129,   122,   123,   124,   125,   126,   127,     0,     0,
      81,    47,    65,    64,     0,    59,     0,     0,    57,     0,
      58,     0,     0,     0,     0,    69,    51,    52,    53,    54,
      55,    56,     0,     0,     0,    95,    97,     0,    84,    86,
      87,     0,    12,   118,   133,   132,   134,   131,     0,     0,
      62,    60,    63,    70,    71,     0,     0,     0,     0,     0,
      61,     0,    92,     0,    32,     0,     0,    42,     0,    67,
      74,     0,     0,    72,     0,    73,     0,    93,    96,    89,
      90,    83,    68,    77,    76,    78,    75,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    19,     7,     8,    74,    25,    26,    39,    40,
      67,    14,   178,    15,   179,    42,    41,    57,    78,   161,
     130,   214,   131,   103,   137,   183,   232,   132,   133,   224,
     225,    75,   115,   134
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -184
static const yytype_int16 yypact[] =
{
       0,   -45,  -184,    21,     5,    79,    15,   -20,    17,  -184,
      28,    60,  -184,  -184,   123,    91,  -184,   131,   134,   102,
     118,  -184,  -184,  -184,   176,   147,  -184,    10,    10,    21,
      19,  -184,  -184,   146,  -184,    29,  -184,     1,   201,     9,
     157,   164,   210,  -184,  -184,   202,   214,  -184,  -184,  -184,
     215,   180,   223,    10,    10,   135,   412,   219,   233,   234,
     244,   135,  -184,  -184,  -184,  -184,   245,  -184,  -184,  -184,
    -184,   412,   412,   412,  -184,   467,  -184,   238,   243,  -184,
    -184,  -184,  -184,  -184,   562,   211,   211,   412,   412,   230,
     412,   373,   392,   447,   412,   412,   412,   412,   412,   412,
     237,   353,   247,   251,   145,   562,   447,   593,   412,   412,
     636,   412,   636,   447,   447,   524,  -184,   -28,   -28,   -26,
     -26,   -26,   211,   412,   101,   353,   353,   353,   353,   303,
     486,  -184,  -184,   226,  -184,    73,   254,   100,   543,   669,
     669,   669,   227,   227,   447,   447,   408,   427,   447,   447,
     447,   447,   447,   447,   252,   669,   229,   581,   229,   229,
     353,   236,   439,   353,   353,   259,   353,   299,   318,   357,
     353,   353,   353,   353,   353,   353,   255,   121,  -184,   224,
      73,    43,    43,   277,   447,   688,   624,   447,   447,   660,
     447,   660,   163,   163,    47,    47,    47,   227,   447,   260,
    -184,  -184,   505,   581,   357,   612,   353,   353,   648,   353,
     648,   357,   357,   304,   212,  -184,   420,   420,    89,    89,
      89,   229,   353,    98,   110,  -184,  -184,    73,  -184,  -184,
    -184,   136,  -184,   688,   688,   688,   688,   688,    10,   248,
     679,   679,   679,   262,   262,   357,   357,   338,   209,   283,
     679,   114,  -184,    98,  -184,   311,   312,   210,   357,   262,
     393,   357,   357,    54,   357,    54,   357,  -184,  -184,  -184,
    -184,   243,   262,   262,   262,   262,   262,  -184
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -184,  -184,   301,  -184,    30,    -3,  -184,   295,    87,  -184,
     265,   300,  -174,  -184,    85,  -184,   111,    75,  -184,  -184,
     -55,  -183,   -41,    66,  -184,  -184,  -184,  -184,  -184,   125,
      97,   162,    42,   -54
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -95
static const yytype_int16 yytable[] =
{
      13,     1,    76,     2,    49,     9,   228,     3,    17,    96,
      97,    98,    99,    37,    99,    21,     4,    76,    76,    76,
      52,   239,    45,    46,    10,   100,    13,   100,   243,   244,
      22,    11,    34,    76,    76,    20,    76,    76,    76,   116,
      76,    76,    76,    76,    76,    76,   124,    68,    69,    70,
      50,     5,   116,   254,    76,    76,    38,    76,    12,   116,
     116,    53,   259,   260,   263,   265,    48,    23,    51,    76,
     156,   157,   158,   159,   162,   272,    10,    24,   273,   274,
      12,   275,    18,   276,   -95,   -95,     3,   153,    16,   213,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     154,    10,    68,    69,    70,   199,    27,   249,   202,   203,
      12,   205,   208,   210,    16,   216,   217,   218,   219,   220,
     221,   181,   182,   226,    10,    68,    69,    70,   215,   175,
     116,    28,    13,   116,   116,    12,   116,    18,    65,    43,
     229,   230,   176,    29,   116,    30,   223,   -94,   138,    66,
      24,   240,   241,    32,   242,   142,   143,   252,    12,   255,
     256,   267,   253,   215,    63,    64,   253,   250,    33,   226,
     215,   215,    88,    89,    90,    91,    92,    13,    93,    34,
      94,    95,    96,    97,    98,    99,   185,   186,   189,   191,
     192,   193,   194,   195,   196,   197,    35,    47,   100,   226,
     150,   151,   152,   153,   215,   215,   215,   215,     3,    54,
      58,    55,   124,    68,    69,    70,   154,   215,    60,    56,
     215,   215,    59,   215,    13,   215,   233,    61,    62,   234,
     235,    77,   236,    84,    85,    86,    79,    80,   264,   245,
     237,   246,   247,   248,   211,   212,    12,    81,    83,   104,
     105,   101,   107,   110,   112,   213,   117,   118,   119,   120,
     121,   122,   102,   106,   100,   249,   123,   135,   238,   136,
     139,   140,   177,   141,   180,   258,   227,   246,   247,   248,
     154,   198,   176,   200,   222,   155,   163,   164,   165,   166,
     167,   168,   204,   169,   231,   170,   171,   172,   173,   174,
     175,   249,   124,    68,    69,    70,   124,    68,    69,    70,
     160,   160,   266,   176,   125,   249,   269,   270,   125,    31,
      36,   124,    68,    69,    70,   257,    82,   126,   206,    44,
     207,   126,   271,   125,   127,   128,    12,   277,   127,   128,
      12,   124,    68,    69,    70,   129,   126,   209,   251,   129,
     268,     0,     0,   127,   128,    12,   124,    68,    69,    70,
     124,    68,    69,    70,   129,     0,     0,   261,   125,   262,
       0,     0,     0,   211,   212,    12,    10,    68,    69,    70,
       0,   126,     0,     0,   213,     0,     0,     0,   127,   128,
      12,     0,   211,   212,    12,    10,    68,    69,    70,   129,
       0,    71,   108,   213,   109,     0,     0,     0,    72,    73,
      12,    10,    68,    69,    70,    10,    68,    69,    70,     0,
      71,   111,   246,   247,   248,     0,     0,    72,    73,    12,
      10,    68,    69,    70,     0,     0,     0,   187,     0,   188,
      71,     0,     0,   113,   114,    12,   249,    72,    73,    12,
      10,    68,    69,    70,     0,     0,   190,   172,   173,   174,
     175,     0,   113,   114,    12,   163,   164,   165,   166,   167,
     168,     0,   169,   176,   170,   171,   172,   173,   174,   175,
       0,     0,   113,   114,    12,     0,   201,     0,     0,     0,
       0,     0,   176,    87,    88,    89,    90,    91,    92,     0,
      93,     0,    94,    95,    96,    97,    98,    99,     0,     0,
       0,     0,   163,   164,   165,   166,   167,   168,     0,   169,
     100,   170,   171,   172,   173,   174,   175,     0,     0,     0,
       0,     0,   164,   165,   166,   167,   168,     0,   169,   176,
     170,   171,   172,   173,   174,   175,     0,     0,     0,     0,
       0,   144,     0,   145,   146,   147,     0,     0,   176,   148,
     149,   150,   151,   152,   153,     0,     0,     0,     0,     0,
     184,     0,   145,   146,   147,     0,     0,   154,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,     0,    93,   154,    94,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,     0,   169,   100,   170,   171,   172,   173,
     174,   175,    90,    91,    92,     0,    93,     0,    94,    95,
      96,    97,    98,    99,   176,     0,     0,     0,     0,     0,
       0,   166,   167,   168,     0,   169,   100,   170,   171,   172,
     173,   174,   175,   145,   146,   147,     0,     0,     0,   148,
     149,   150,   151,   152,   153,   176,   -95,   -95,     0,    93,
       0,    94,    95,    96,    97,    98,    99,   154,   -95,   -95,
       0,   169,     0,   170,   171,   172,   173,   174,   175,   100,
     -95,   -95,     0,     0,     0,   148,   149,   150,   151,   152,
     153,   176,    93,     0,    94,    95,    96,    97,    98,    99,
       0,     0,   169,   154,   170,   171,   172,   173,   174,   175,
       0,     0,   100,   148,   149,   150,   151,   152,   153,     0,
       0,     0,   176,     0,     0,     0,     0,     0,     0,     0,
       0,   154
};

static const yytype_int16 yycheck[] =
{
       3,     1,    56,     3,     3,    50,   180,     7,     3,    37,
      38,    39,    40,     3,    40,     0,    16,    71,    72,    73,
      11,   204,     3,     4,     3,    53,    29,    53,   211,   212,
      50,    10,     3,    87,    88,     5,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,     3,     4,     5,     6,
      49,    51,   106,   227,   108,   109,    46,   111,    37,   113,
     114,    52,   245,   246,   247,   248,    37,    50,    38,   123,
     125,   126,   127,   128,   129,   258,     3,    49,   261,   262,
      37,   264,     3,   266,    30,    31,     7,    40,     3,    46,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      53,     3,     4,     5,     6,   160,    46,    53,   163,   164,
      37,   166,   167,   168,    29,   170,   171,   172,   173,   174,
     175,    21,    22,   177,     3,     4,     5,     6,   169,    40,
     184,     8,   135,   187,   188,    37,   190,     3,     3,    28,
     181,   182,    53,    52,   198,    14,    25,    46,   106,    14,
      49,   206,   207,    51,   209,   113,   114,    47,    37,    23,
      24,    47,    52,   204,    53,    54,    52,   222,    50,   223,
     211,   212,    27,    28,    29,    30,    31,   180,    33,     3,
      35,    36,    37,    38,    39,    40,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    49,    51,    53,   253,
      37,    38,    39,    40,   245,   246,   247,   248,     7,    52,
       8,    47,     3,     4,     5,     6,    53,   258,     3,     9,
     261,   262,     8,   264,   227,   266,   184,    47,     5,   187,
     188,    12,   190,    71,    72,    73,     3,     3,    29,    27,
     198,    29,    30,    31,    35,    36,    37,     3,     3,    87,
      88,    13,    90,    91,    92,    46,    94,    95,    96,    97,
      98,    99,    19,    33,    53,    53,    29,    20,     8,    18,
     108,   109,    46,   111,    20,    27,    52,    29,    30,    31,
      53,    29,    53,    47,    29,   123,    26,    27,    28,    29,
      30,    31,    33,    33,    17,    35,    36,    37,    38,    39,
      40,    53,     3,     4,     5,     6,     3,     4,     5,     6,
       7,     7,    29,    53,    15,    53,     5,     5,    15,    18,
      25,     3,     4,     5,     6,   238,    61,    28,    29,    29,
      31,    28,   257,    15,    35,    36,    37,   271,    35,    36,
      37,     3,     4,     5,     6,    46,    28,    29,   223,    46,
     253,    -1,    -1,    35,    36,    37,     3,     4,     5,     6,
       3,     4,     5,     6,    46,    -1,    -1,    29,    15,    31,
      -1,    -1,    -1,    35,    36,    37,     3,     4,     5,     6,
      -1,    28,    -1,    -1,    46,    -1,    -1,    -1,    35,    36,
      37,    -1,    35,    36,    37,     3,     4,     5,     6,    46,
      -1,    28,    29,    46,    31,    -1,    -1,    -1,    35,    36,
      37,     3,     4,     5,     6,     3,     4,     5,     6,    -1,
      28,    29,    29,    30,    31,    -1,    -1,    35,    36,    37,
       3,     4,     5,     6,    -1,    -1,    -1,    29,    -1,    31,
      28,    -1,    -1,    35,    36,    37,    53,    35,    36,    37,
       3,     4,     5,     6,    -1,    -1,    29,    37,    38,    39,
      40,    -1,    35,    36,    37,    26,    27,    28,    29,    30,
      31,    -1,    33,    53,    35,    36,    37,    38,    39,    40,
      -1,    -1,    35,    36,    37,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    53,    26,    27,    28,    29,    30,    31,    -1,
      33,    -1,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    -1,    33,
      53,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    33,    53,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    29,    30,    31,    -1,    -1,    53,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    29,    30,    31,    -1,    -1,    53,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    -1,    33,    53,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    -1,    33,    53,    35,    36,    37,    38,
      39,    40,    29,    30,    31,    -1,    33,    -1,    35,    36,
      37,    38,    39,    40,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    -1,    33,    53,    35,    36,    37,
      38,    39,    40,    29,    30,    31,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    53,    30,    31,    -1,    33,
      -1,    35,    36,    37,    38,    39,    40,    53,    30,    31,
      -1,    33,    -1,    35,    36,    37,    38,    39,    40,    53,
      30,    31,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    53,    33,    -1,    35,    36,    37,    38,    39,    40,
      -1,    -1,    33,    53,    35,    36,    37,    38,    39,    40,
      -1,    -1,    53,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     7,    16,    51,    55,    57,    58,    50,
       3,    10,    37,    59,    65,    67,    68,     3,     3,    56,
      58,     0,    50,    50,    49,    60,    61,    46,     8,    52,
      14,    56,    51,    50,     3,    49,    61,     3,    46,    62,
      63,    70,    69,    70,    65,     3,     4,    51,    37,     3,
      49,    58,    11,    52,    52,    47,     9,    71,     8,     8,
       3,    47,     5,    70,    70,     3,    14,    64,     4,     5,
       6,    28,    35,    36,    59,    85,    87,    12,    72,     3,
       3,     3,    64,     3,    85,    85,    85,    26,    27,    28,
      29,    30,    31,    33,    35,    36,    37,    38,    39,    40,
      53,    13,    19,    77,    85,    85,    33,    85,    29,    31,
      85,    29,    85,    35,    36,    86,    87,    85,    85,    85,
      85,    85,    85,    29,     3,    15,    28,    35,    36,    46,
      74,    76,    81,    82,    87,    20,    18,    78,    86,    85,
      85,    85,    86,    86,    27,    29,    30,    31,    35,    36,
      37,    38,    39,    40,    53,    85,    74,    74,    74,    74,
       7,    73,    74,    26,    27,    28,    29,    30,    31,    33,
      35,    36,    37,    38,    39,    40,    53,    46,    66,    68,
      20,    21,    22,    79,    27,    86,    86,    29,    31,    86,
      29,    86,    86,    86,    86,    86,    86,    86,    29,    74,
      47,    47,    74,    74,    33,    74,    29,    31,    74,    29,
      74,    35,    36,    46,    75,    76,    74,    74,    74,    74,
      74,    74,    29,    25,    83,    84,    87,    52,    66,    76,
      76,    17,    80,    86,    86,    86,    86,    86,     8,    75,
      74,    74,    74,    75,    75,    27,    29,    30,    31,    53,
      74,    83,    47,    52,    66,    23,    24,    62,    27,    75,
      75,    29,    31,    75,    29,    75,    29,    47,    84,     5,
       5,    71,    75,    75,    75,    75,    75,    77
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 128 "PaQL_Grammar.y"
    { ide = (yyvsp[(1) - (1)]);
						  return 1; ;}
    break;

  case 3:
#line 131 "PaQL_Grammar.y"
    { debug("Recognized Query..." << endl);
						  //q.print();
						  return 0; ;}
    break;

  case 4:
#line 136 "PaQL_Grammar.y"
    { debug("Recognized Comment..." << endl);
						  return 5; ;}
    break;

  case 5:
#line 140 "PaQL_Grammar.y"
    { debug("Recognized Query Commented Out..." << endl);
						  return 5; ;}
    break;

  case 6:
#line 143 "PaQL_Grammar.y"
    { debug("Recognized Command..." << endl);
						  return 4; ;}
    break;

  case 7:
#line 146 "PaQL_Grammar.y"
    { yyerrok;
						  return -1; ;}
    break;

  case 10:
#line 152 "PaQL_Grammar.y"
    { /*c = *new SQL_DEF_command($2, $4, $6);*/ ;}
    break;

  case 11:
#line 153 "PaQL_Grammar.y"
    { /*c = *new SQL_DEF_command($2, $4, $6);*/ ;}
    break;

  case 12:
#line 165 "PaQL_Grammar.y"
    {
			debug("{ PROJ: " << (yyvsp[(2) - (10)]) << " }" << endl
				<< "{ RELS: " << (yyvsp[(4) - (10)]) << " }" << endl
				<< "A query has been successfully parsed..." << endl << endl);
			//~ q.select.push_back($2);
			//~ q.from.push_back($4);

			q.json = "{\"SELECT\":[" + (yyvsp[(2) - (10)]) + "]" + \
			         ",\"FROM\":[" + (yyvsp[(4) - (10)]) + "]" + \
			         ",\"WHERE\":" + (yyvsp[(5) - (10)]) + \
			         ",\"SUCH-THAT\":" + (yyvsp[(6) - (10)]) + \
			         ",\"OBJECTIVE\":" + (yyvsp[(9) - (10)]) + \
			         ",\"LIMIT\":" + (yyvsp[(10) - (10)]) + \
			         "}";
			//cout << q.json << endl;
		;}
    break;

  case 13:
#line 186 "PaQL_Grammar.y"
    {
					(yyval) = "\"NODE_TYPE\":\"COL_REF\",\"attr_name\":\"" + (yyvsp[(1) - (1)]) + "\"";
					//cout << "IDE" << endl;
					//~ $$ = makeColumnRef($1, NIL, @1, yyscanner);
				;}
    break;

  case 14:
#line 192 "PaQL_Grammar.y"
    {
					(yyval) = "\"NODE_TYPE\":\"COL_REF\",\"attr_name\":\"" + (yyvsp[(1) - (1)]) + "\"";
				;}
    break;

  case 15:
#line 196 "PaQL_Grammar.y"
    {
					(yyval) = "\"NODE_TYPE\":\"COL_REF\",\"table_name\":\"" + (yyvsp[(1) - (2)]) + "\",\"attr_name\":\"" + (yyvsp[(2) - (2)]) + "\"";
					//$$ = $1 + $2;
					//cout << "IDE indirection" << endl;
					//~ $$ = makeColumnRef($1, $2, @1, yyscanner);
				;}
    break;

  case 19:
#line 208 "PaQL_Grammar.y"
    {
						//cout << "POINT" << endl;
						(yyval) = (yyvsp[(2) - (2)]);
						//~ $$ = (Node *) makeString($2);
					;}
    break;

  case 20:
#line 222 "PaQL_Grammar.y"
    { (yyval) = "\"REL_NAME\":\"" + (yyvsp[(1) - (1)]) + "\""; ;}
    break;

  case 21:
#line 223 "PaQL_Grammar.y"
    { (yyval) = "\"REL_NAME\":\"" + (yyvsp[(1) - (3)]) + "." + (yyvsp[(3) - (3)]) + "\""; ;}
    break;

  case 22:
#line 224 "PaQL_Grammar.y"
    { (yyval) = "\"REL_NAME\":\"" + (yyvsp[(1) - (2)]) + "\",\"REL_ALIAS\":\"" + (yyvsp[(2) - (2)]) + "\""; ;}
    break;

  case 23:
#line 225 "PaQL_Grammar.y"
    { (yyval) = "\"REL_NAME\":\"" + (yyvsp[(1) - (4)]) + "." + (yyvsp[(3) - (4)]) + "\",\"REL_ALIAS\":\"" + (yyvsp[(4) - (4)]) + "\""; ;}
    break;

  case 24:
#line 226 "PaQL_Grammar.y"
    { (yyval) = "";
									  debug("Nested query recognized..." + (yyvsp[(4) - (4)]) << endl);
									  SQL_query* nested = new SQL_query;
									  *nested = q;
									  q.reset();
									  q.nested = nested; ;}
    break;

  case 25:
#line 234 "PaQL_Grammar.y"
    { (yyval) = (yyvsp[(1) - (3)]) + ",\"REPEAT\":" + (yyvsp[(3) - (3)]); ;}
    break;

  case 26:
#line 236 "PaQL_Grammar.y"
    { (yyval) = "\"AS\":null"; ;}
    break;

  case 27:
#line 237 "PaQL_Grammar.y"
    { (yyval) = "\"AS\":\"" + (yyvsp[(1) - (1)]) + "\""; ;}
    break;

  case 28:
#line 238 "PaQL_Grammar.y"
    { (yyval) = "\"AS\":\"" + (yyvsp[(2) - (2)]) + "\""; ;}
    break;

  case 29:
#line 245 "PaQL_Grammar.y"
    { (yyval) = "{" + (yyvsp[(1) - (1)]) + "}"; ;}
    break;

  case 30:
#line 246 "PaQL_Grammar.y"
    { (yyval) = "{" + (yyvsp[(1) - (3)]) + "}," + (yyvsp[(3) - (3)]); ;}
    break;

  case 31:
#line 249 "PaQL_Grammar.y"
    { (yyval) = "{" + (yyvsp[(1) - (1)]) + "}"; ;}
    break;

  case 32:
#line 250 "PaQL_Grammar.y"
    { (yyval) = "{" + (yyvsp[(1) - (3)]) + "}," + (yyvsp[(3) - (3)]); ;}
    break;

  case 33:
#line 254 "PaQL_Grammar.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 34:
#line 255 "PaQL_Grammar.y"
    { (yyval) = "\"NODE_TYPE\":\"PACKAGE\",\
															\"PACKAGE_RELS\":[" + (yyvsp[(3) - (5)]) + "]," + \
															(yyvsp[(5) - (5)]); ;}
    break;

  case 35:
#line 260 "PaQL_Grammar.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 37:
#line 268 "PaQL_Grammar.y"
    { (yyval) = "{" + (yyvsp[(1) - (1)]) + "}"; ;}
    break;

  case 38:
#line 269 "PaQL_Grammar.y"
    { (yyval) = "{" + (yyvsp[(1) - (1)]) + "}"; ;}
    break;

  case 39:
#line 270 "PaQL_Grammar.y"
    { (yyval) = "{" + (yyvsp[(1) - (3)]) + "}," + (yyvsp[(3) - (3)]); ;}
    break;

  case 40:
#line 271 "PaQL_Grammar.y"
    { (yyval) = "{" + (yyvsp[(1) - (3)]) + "}," + (yyvsp[(3) - (3)]); ;}
    break;

  case 41:
#line 277 "PaQL_Grammar.y"
    {
					debug("{ SELECTION: " << (yyvsp[(2) - (2)]) << " }" << endl);
					(yyval) = (yyvsp[(2) - (2)]);
				;}
    break;

  case 42:
#line 281 "PaQL_Grammar.y"
    { (yyval) = "null"; ;}
    break;

  case 43:
#line 286 "PaQL_Grammar.y"
    {
						debug("{ SUCH-THAT-CLAUSE: " << (yyvsp[(2) - (3)]) << " }" << endl);
						(yyval) = (yyvsp[(3) - (3)]);
					;}
    break;

  case 44:
#line 290 "PaQL_Grammar.y"
    {
						(yyval) = "null";
					;}
    break;

  case 45:
#line 299 "PaQL_Grammar.y"
    {
				(yyval) = "{\
				\"NODE_TYPE\":\"SUB_QUERY\",\
				\"CONTENT\":{\
				\"SELECT\":" + (yyvsp[(2) - (6)]) + ",\
				\"FROM\":{" + (yyvsp[(4) - (6)]) + "},\
				\"WHERE\":" + (yyvsp[(5) - (6)]) + ",\
				\"GROUP BY\":" + (yyvsp[(6) - (6)]) + \
				"}}";
			;}
    break;

  case 46:
#line 313 "PaQL_Grammar.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 47:
#line 316 "PaQL_Grammar.y"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 48:
#line 319 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"ALL\",\"CONTENT\":" + (yyvsp[(2) - (2)]) + "}"; ;}
    break;

  case 49:
#line 322 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"UN_OP\",\"OP\":\"+\",\"left\":" + (yyvsp[(2) - (2)]) + "}"; ;}
    break;

  case 50:
#line 324 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"UN_OP\",\"OP\":\"-\",\"left\":" + (yyvsp[(2) - (2)]) + "}"; ;}
    break;

  case 51:
#line 327 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"+\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 52:
#line 329 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"-\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 53:
#line 331 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"*\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 54:
#line 333 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"/\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 55:
#line 335 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"%\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 56:
#line 337 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"^\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 57:
#line 340 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"<\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 58:
#line 342 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\">\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 59:
#line 344 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"=\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 60:
#line 346 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"<>\",\"left\":" + (yyvsp[(1) - (4)]) + ",\"right\":" + (yyvsp[(4) - (4)]) + "}"; ;}
    break;

  case 61:
#line 348 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"!=\",\"left\":" + (yyvsp[(1) - (4)]) + ",\"right\":" + (yyvsp[(4) - (4)]) + "}"; ;}
    break;

  case 62:
#line 350 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"<=\",\"left\":" + (yyvsp[(1) - (4)]) + ",\"right\":" + (yyvsp[(4) - (4)]) + "}"; ;}
    break;

  case 63:
#line 352 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\">=\",\"left\":" + (yyvsp[(1) - (4)]) + ",\"right\":" + (yyvsp[(4) - (4)]) + "}"; ;}
    break;

  case 64:
#line 354 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"AND\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 65:
#line 356 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"OR\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 66:
#line 358 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"UN_OP\",\"OP\":\"NOT\",\"left\":" + (yyvsp[(2) - (2)]) + "}"; ;}
    break;

  case 67:
#line 359 "PaQL_Grammar.y"
    {
		(yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"AND\",\
			\"left\":{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\">=\",\"left\":" + (yyvsp[(1) - (5)]) + ",\"right\":" + (yyvsp[(3) - (5)]) + "},\
			\"right\":{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"<=\",\"left\":" + (yyvsp[(1) - (5)]) + ",\"right\":" + (yyvsp[(5) - (5)]) + "}}";
		;}
    break;

  case 68:
#line 364 "PaQL_Grammar.y"
    {

		;}
    break;

  case 69:
#line 371 "PaQL_Grammar.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 70:
#line 373 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"UN_OP\",\"OP\":\"+\",\"left\":" + (yyvsp[(2) - (2)]) + "}"; ;}
    break;

  case 71:
#line 375 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"UN_OP\",\"OP\":\"-\",\"left\":" + (yyvsp[(2) - (2)]) + "}"; ;}
    break;

  case 72:
#line 377 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"<\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 73:
#line 379 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\">\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 74:
#line 381 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"=\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 75:
#line 383 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"!=\",\"left\":" + (yyvsp[(1) - (4)]) + ",\"right\":" + (yyvsp[(4) - (4)]) + "}"; ;}
    break;

  case 76:
#line 385 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"<>\",\"left\":" + (yyvsp[(1) - (4)]) + ",\"right\":" + (yyvsp[(4) - (4)]) + "}"; ;}
    break;

  case 77:
#line 387 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"<=\",\"left\":" + (yyvsp[(1) - (4)]) + ",\"right\":" + (yyvsp[(4) - (4)]) + "}"; ;}
    break;

  case 78:
#line 389 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\">=\",\"left\":" + (yyvsp[(1) - (4)]) + ",\"right\":" + (yyvsp[(4) - (4)]) + "}"; ;}
    break;

  case 80:
#line 393 "PaQL_Grammar.y"
    { (yyval) = "{" + (yyvsp[(1) - (1)]) + "}"; ;}
    break;

  case 81:
#line 394 "PaQL_Grammar.y"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 82:
#line 400 "PaQL_Grammar.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 83:
#line 401 "PaQL_Grammar.y"
    { (yyval) = "null"; ;}
    break;

  case 84:
#line 404 "PaQL_Grammar.y"
    { (yyval) = "order by " + (yyvsp[(3) - (3)]); ;}
    break;

  case 85:
#line 405 "PaQL_Grammar.y"
    { (yyval) = "null"; ;}
    break;

  case 86:
#line 408 "PaQL_Grammar.y"
    { (yyval) = "{\"TYPE\":\"MAXIMIZE\",\"EXPR\":" + (yyvsp[(2) - (2)]) + "}"; ;}
    break;

  case 87:
#line 409 "PaQL_Grammar.y"
    { (yyval) = "{\"TYPE\":\"MINIMIZE\",\"EXPR\":" + (yyvsp[(2) - (2)]) + "}"; ;}
    break;

  case 88:
#line 410 "PaQL_Grammar.y"
    { (yyval) = "null"; ;}
    break;

  case 89:
#line 413 "PaQL_Grammar.y"
    { (yyval) = "{\"TYPE\":\"INPUT\",\"LIMIT\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 90:
#line 414 "PaQL_Grammar.y"
    { (yyval) = "{\"TYPE\":\"OUTPUT\",\"LIMIT\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 91:
#line 415 "PaQL_Grammar.y"
    { (yyval) = "null"; ;}
    break;

  case 92:
#line 426 "PaQL_Grammar.y"
    {
		(yyval) = "\"NODE_TYPE\":\"func\",\"func_name\":\"" + (yyvsp[(1) - (4)]) + "\",\"func_args\":[" + (yyvsp[(3) - (4)]) + "],\"distinct\":false";
	;}
    break;

  case 93:
#line 429 "PaQL_Grammar.y"
    {
		(yyval) = "\"NODE_TYPE\":\"func\",\"func_name\":\"" + (yyvsp[(1) - (5)]) + "\",\"func_args\":[" + (yyvsp[(4) - (5)]) + "],\"distinct\":true";
	;}
    break;

  case 95:
#line 441 "PaQL_Grammar.y"
    {
						(yyval) = (yyvsp[(1) - (1)]);
					;}
    break;

  case 96:
#line 445 "PaQL_Grammar.y"
    {
						(yyval) = (yyvsp[(1) - (3)]) + "," + (yyvsp[(3) - (3)]);
					;}
    break;

  case 97:
#line 450 "PaQL_Grammar.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 98:
#line 472 "PaQL_Grammar.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 99:
#line 483 "PaQL_Grammar.y"
    { (yyval) = "\"+\"" + (yyvsp[(1) - (2)]); ;}
    break;

  case 107:
#line 499 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"<\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 108:
#line 501 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\">\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 109:
#line 503 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"=\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 110:
#line 505 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"!=\",\"left\":" + (yyvsp[(1) - (4)]) + ",\"right\":" + (yyvsp[(4) - (4)]) + "}"; ;}
    break;

  case 111:
#line 507 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"<>\",\"left\":" + (yyvsp[(1) - (4)]) + ",\"right\":" + (yyvsp[(4) - (4)]) + "}"; ;}
    break;

  case 112:
#line 509 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"<=\",\"left\":" + (yyvsp[(1) - (4)]) + ",\"right\":" + (yyvsp[(4) - (4)]) + "}"; ;}
    break;

  case 113:
#line 511 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\">=\",\"left\":" + (yyvsp[(1) - (4)]) + ",\"right\":" + (yyvsp[(4) - (4)]) + "}"; ;}
    break;

  case 114:
#line 513 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"AND\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 115:
#line 515 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"OR\",\"left\":" + (yyvsp[(1) - (3)]) + ",\"right\":" + (yyvsp[(3) - (3)]) + "}"; ;}
    break;

  case 116:
#line 517 "PaQL_Grammar.y"
    { (yyval) = "{\"NODE_TYPE\":\"UN_OP\",\"OP\":\"NOT\",\"left\":" + (yyvsp[(2) - (2)]) + "}"; ;}
    break;

  case 117:
#line 524 "PaQL_Grammar.y"
    {
				(yyval) = "{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"AND\",\
					\"left\":{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\">=\",\"left\":" + (yyvsp[(1) - (5)]) + ",\"right\":" + (yyvsp[(3) - (5)]) + "},\
					\"right\":{\"NODE_TYPE\":\"BIN_OP\",\"OP\":\"<=\",\"left\":" + (yyvsp[(1) - (5)]) + ",\"right\":" + (yyvsp[(5) - (5)]) + "}}";
				;}
    break;

  case 118:
#line 534 "PaQL_Grammar.y"
    {
					//~ $$ = (Node *) makeA_Expr(AEXPR_OR, NIL,
						//~ (Node *) makeSimpleA_Expr(AEXPR_OP, "<", $1, $5, @2),
						//~ (Node *) makeSimpleA_Expr(AEXPR_OP, ">", $1, $7, @2),
											 //~ @2);
				;}
    break;

  case 119:
#line 552 "PaQL_Grammar.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 128:
#line 572 "PaQL_Grammar.y"
    { /*cout << "##################### <" << endl;*/ ;}
    break;

  case 133:
#line 579 "PaQL_Grammar.y"
    { /*cout << "##################### <=" << endl;*/ ;}
    break;

  case 135:
#line 584 "PaQL_Grammar.y"
    { (yyval) = "{" + (yyvsp[(1) - (1)]) + "}";;}
    break;

  case 138:
#line 588 "PaQL_Grammar.y"
    { (yyval) = "\"infinity\""; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2373 "parser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 600 "PaQL_Grammar.y"



/**** YYLEX ****/

bool is_integer(float k) {
  return std::floor(k) == k;
}

int yylex () {
	char c;
	
	// Ignore whitespaces, get first nonwhite character.
	//while ((c = getchar ()) == ' ' || c == '\t' || c == '\n');
	while (iswspace(c = getchar()));
	
	// Return when encouter end-of-file
	if (c == EOF) return 0;

	// Char starts a number => parse the number.
	if (c == '.' || isdigit (c)) {
		//cout << c << endl;
		char c2 = getchar();
		ungetc(c2, stdin);
		
		if (c != '.' || isdigit(c2)) {
			ungetc(c, stdin);
			
			double num;
			char *str = (char*) malloc(20);
			
			scanf("%lf", &num);
			sprintf(str, "%lf", num);
			yylval = (string) str;
			
			if (c2 != '.' && is_integer(num) && num >= 0) {
				//cout << "NUM_NAT: " << num << endl;
				//cout << "NUM_NAT: " << str << endl;
				scanf("%ld", (long int*)&num);
				sprintf(str, "%ld", (long int)num);
				yylval = (string) str;
				//cout << str << endl;
				return NAT_NUM;
			}
			
			return NUM;
		}
	}

	// Char starts an identifier => read the name.
	if (isalpha (c)) {
		string ide;
		
		do {
			ide += c;
			c = getchar();
		//} while (isalpha(c) || isdigit(c) || c == '_' || c == '.' || c == '<' || c == '>' || c == '=');
		} while (isalpha(c) || isdigit(c) || c == '_');
		ungetc(c, stdin);
		
		yylval = ide;
		
		if (strcasecmp(ide.c_str(), "INFINITY") == 0) return INFTY;
		if (strcasecmp(ide.c_str(), "SELECT") == 0) return SELECT;
		if (strcasecmp(ide.c_str(), "PACKAGE") == 0) return PACKAGE;
		if (strcasecmp(ide.c_str(), "REPEAT") == 0) return REPEAT;
		if (strcasecmp(ide.c_str(), "FROM") == 0) return FROM;
		if (strcasecmp(ide.c_str(), "WHERE") == 0) return WHERE;
		if (strcasecmp(ide.c_str(), "ORDER") == 0) return ORDER;
		if (strcasecmp(ide.c_str(), "GROUP") == 0) return GROUP;
		if (strcasecmp(ide.c_str(), "SUCH") == 0) return SUCH;
		if (strcasecmp(ide.c_str(), "THAT") == 0) return THAT;
		if (strcasecmp(ide.c_str(), "BY") == 0) return BY;
		if (strcasecmp(ide.c_str(), "AS") == 0) return AS;
		if (strcasecmp(ide.c_str(), "ALL") == 0) return ALL;
		if (strcasecmp(ide.c_str(), "LIMIT") == 0) return LIMIT;
		if (strcasecmp(ide.c_str(), "DEF") == 0) return DEF;
		if (strcasecmp(ide.c_str(), "AND") == 0) return AND;
		if (strcasecmp(ide.c_str(), "OR") == 0) return OR;
		if (strcasecmp(ide.c_str(), "NOT") == 0) return NOT;
		if (strcasecmp(ide.c_str(), "MAXIMIZE") == 0) return MAXIMIZE;
		if (strcasecmp(ide.c_str(), "MINIMIZE") == 0) return MINIMIZE;
		if (strcasecmp(ide.c_str(), "BETWEEN") == 0) return BETWEEN;
		if (strcasecmp(ide.c_str(), "INPUT") == 0) return INPUT;
		if (strcasecmp(ide.c_str(), "OUTPUT") == 0) return OUTPUT;
		if (strcasecmp(ide.c_str(), "DISTINCT") == 0) return DISTINCT;
		//~ if (strcasecmp(ide.c_str(), "<=") == 0) {cout << "LESS THAN" << endl; return LESS_THAN_OP;}
		//~ if (strcasecmp(ide.c_str(), ">=") == 0) return GREATER_THAN_OP;
		
		//cout << "IDE: " << yylval << endl;
		return IDE;
	}

	// Any other character is a token by itself.
	yylval = c;
	//cout << "OTHER TOKEN: " << c << endl;
	return c;
}

/*** MAIN ***
int main() {
	return yyparse();
}*/

//~ void yyerror(const char *error) { /* Called by yyparse on error */
	//~ cerr << error << endl;
//~ }

