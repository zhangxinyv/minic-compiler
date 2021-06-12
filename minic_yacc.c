/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 ".\\minic_yacc.y"

/*
    问题：
    1. ++ --还没加到文法里
    2. 词法分析可能还存在问题，在识别数字和字符串的时候，8进制和16进制数先不考虑
    3. 错误信息：变量重复定义 变量未定义 函数重复定义 函数未定义
    4. 数组如何存符号表里
*/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "ast.h"
#include "ir.h"
#include "table.h"
#include "minic_lex.h"
#include "util.h"
extern int line_no;
int yyerror(char*);
int flag_var_def = 0;



/* Line 189 of yacc.c  */
#line 97 "minic_yacc.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 25 ".\\minic_yacc.y"

#include "util.h"



/* Line 209 of yacc.c  */
#line 127 "minic_yacc.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ERRORCHAR = 600,
     LE = 500,
     GE = 501,
     AND = 502,
     OR = 503,
     EQ = 504,
     NE = 505,
     SELFPULS = 506,
     SELPMINUS = 507,
     INT = 401,
     CHAR = 402,
     VOID = 403,
     IF = 405,
     ELSE = 406,
     WHILE = 407,
     RETURN = 410,
     BREAK = 411,
     CONTINUE = 412,
     ID = 300,
     INTEGER = 301,
     STRING = 302,
     CHARACTER = 602
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 29 ".\\minic_yacc.y"

	struct
	{
		union
		{
			int Iv;
			int CH;
			int NO;
			struct { int TC,FC;} _BExpr;
 			struct { int QUAD,CH;} _WBD;
 			struct { int type,place;union{int Iv;float Rv;}Value;} _Expr;
			char _Rop[5];
			int First;
			struct {int PLACE,OFFSET;}_Var;
			struct {int NO,DIM,PLACE;}_Elist;
		}attr;
		struct node *ast_node;


		// for symbol table
		varInfo var;
		List var_list;
		int type;

	}all;
	char str[20];
    char character;
    int integer;



/* Line 214 of yacc.c  */
#line 200 "minic_yacc.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 212 "minic_yacc.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   208

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   602

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,     2,     2,    41,     2,     2,
      37,    38,    31,    29,    36,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      26,    28,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      21,    22,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    12,    13,    14,     2,    15,    16,    17,     2,     2,
      18,    19,    20,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       4,     5,     6,     7,     8,     9,    10,    11,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     2,    24
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    13,    15,    17,    19,
      22,    27,    31,    35,    39,    41,    43,    46,    53,    59,
      66,    72,    76,    78,    81,    85,    90,    93,    97,   101,
     104,   107,   110,   112,   114,   119,   122,   124,   126,   132,
     140,   146,   149,   152,   156,   159,   163,   165,   167,   172,
     174,   176,   180,   182,   186,   188,   192,   194,   198,   200,
     202,   204,   206,   208,   210,   212,   214,   216,   218,   220,
     222,   224,   226,   228,   230,   234,   236,   240,   242,   247,
     251,   254,   258,   260,   262,   264,   266,   268
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,    -1,    44,    45,    -1,    44,    51,
      -1,    45,    -1,    51,    -1,    48,    -1,    12,    -1,    12,
      31,    -1,    47,    33,    75,    34,    -1,    33,    75,    34,
      -1,    46,    49,    35,    -1,    49,    36,    50,    -1,    50,
      -1,    77,    -1,    77,    47,    -1,    14,    77,    37,    52,
      38,    55,    -1,    14,    77,    37,    38,    55,    -1,    46,
      77,    37,    52,    38,    55,    -1,    46,    77,    37,    38,
      55,    -1,    52,    36,    53,    -1,    53,    -1,    46,    77,
      -1,    46,    77,    54,    -1,    54,    33,    70,    34,    -1,
      33,    34,    -1,    33,    70,    34,    -1,    39,    56,    40,
      -1,    39,    40,    -1,    56,    45,    -1,    56,    57,    -1,
      45,    -1,    57,    -1,    59,    28,    70,    35,    -1,    70,
      35,    -1,    35,    -1,    55,    -1,    15,    37,    60,    38,
      57,    -1,    15,    37,    60,    38,    57,    16,    57,    -1,
      17,    37,    60,    38,    57,    -1,    19,    35,    -1,    20,
      35,    -1,    18,    70,    35,    -1,    18,    35,    -1,    58,
      36,    70,    -1,    70,    -1,    77,    -1,    59,    33,    70,
      34,    -1,    61,    -1,    62,    -1,    61,     7,    62,    -1,
      63,    -1,    62,     6,    63,    -1,    64,    -1,    63,    66,
      64,    -1,    71,    -1,    64,    65,    71,    -1,    26,    -1,
       4,    -1,    27,    -1,     5,    -1,     8,    -1,     9,    -1,
      29,    -1,    30,    -1,    31,    -1,    32,    -1,    41,    -1,
      29,    -1,    30,    -1,    25,    -1,    71,    -1,    72,    -1,
      71,    67,    72,    -1,    73,    -1,    72,    68,    73,    -1,
      74,    -1,    77,    37,    58,    38,    -1,    77,    37,    38,
      -1,    69,    73,    -1,    37,    70,    38,    -1,    59,    -1,
      76,    -1,    23,    -1,    71,    -1,    22,    -1,    21,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   141,   150,   159,   167,   178,   187,   195,
     206,   213,   222,   236,   247,   259,   268,   283,   295,   305,
     317,   331,   339,   348,   357,   370,   377,   382,   391,   397,
     405,   412,   419,   425,   434,   441,   447,   452,   458,   468,
     482,   492,   497,   502,   508,   516,   523,   532,   538,   548,
     557,   563,   573,   579,   589,   595,   606,   612,   623,   628,
     633,   638,   646,   651,   659,   664,   672,   677,   682,   690,
     695,   700,   708,   717,   723,   734,   740,   751,   757,   764,
     770,   780,   786,   792,   798,   806,   815,   823
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ERRORCHAR", "LE", "GE", "AND", "OR",
  "EQ", "NE", "SELFPULS", "SELPMINUS", "INT", "CHAR", "VOID", "IF", "ELSE",
  "WHILE", "RETURN", "BREAK", "CONTINUE", "ID", "INTEGER", "STRING",
  "CHARACTER", "'!'", "'<'", "'>'", "'='", "'+'", "'-'", "'*'", "'/'",
  "'['", "']'", "';'", "','", "'('", "')'", "'{'", "'}'", "'%'", "$accept",
  "program", "CompUnit", "Decl", "BType", "ConstSubscripts", "VarDecl",
  "VarDefList", "VarDef", "FuncDef", "FuncFParams", "FuncFParam",
  "ExpSubscripts", "Block", "BlockItem", "Stmt", "FuncRParams", "LVal",
  "Cond", "LOrExp", "LAndExp", "EqExp", "RelExp", "RelOp", "EqOp", "addOp",
  "mulOp", "UnaryOp", "Exp", "AddExp", "MulExp", "UnaryExp", "PrimaryExp",
  "ConstExp", "Number", "Ident", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   601,   600,   500,   501,   502,   503,   504,   505,
     506,   507,   401,   402,   403,   405,   406,   407,   410,   411,
     412,   300,   301,   302,   602,    33,    60,    62,    61,    43,
      45,    42,    47,    91,    93,    59,    44,    40,    41,   123,
     125,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    44,    45,    46,    46,
      47,    47,    48,    49,    49,    50,    50,    51,    51,    51,
      51,    52,    52,    53,    53,    54,    54,    54,    55,    55,
      56,    56,    56,    56,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    59,    59,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      65,    65,    66,    66,    67,    67,    68,    68,    68,    69,
      69,    69,    70,    71,    71,    72,    72,    73,    73,    73,
      73,    74,    74,    74,    74,    75,    76,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     1,     2,
       4,     3,     3,     3,     1,     1,     2,     6,     5,     6,
       5,     3,     1,     2,     3,     4,     2,     3,     3,     2,
       2,     2,     1,     1,     4,     2,     1,     1,     5,     7,
       5,     2,     2,     3,     2,     3,     1,     1,     4,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     4,     3,
       2,     3,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,     0,     0,     2,     5,     0,     7,     6,     9,
      87,     0,     1,     3,     4,     0,    14,    15,     0,    12,
       0,     0,     0,    16,     0,     0,     0,    22,    13,    15,
      86,    84,    71,    69,    70,     0,    82,     0,    85,    73,
      75,    77,     0,    83,    47,     0,     0,     0,     0,    18,
      23,     0,     0,     0,    72,     0,    80,    64,    65,     0,
      66,    67,    68,     0,    11,     0,    20,     0,     0,     0,
       0,     0,     0,     0,    36,    29,    32,     0,    37,     0,
      33,    82,     0,     0,    24,    21,    17,    81,     0,    74,
      76,    79,     0,    46,    19,    10,     0,     0,    44,     0,
      41,    42,    28,    30,    31,     0,    35,    26,     0,     0,
      48,     0,    78,     0,    49,    50,    52,    54,    56,     0,
      43,     0,    27,     0,    45,     0,     0,     0,    62,    63,
       0,    59,    61,    58,    60,     0,     0,    34,    25,    38,
      51,    53,    55,    57,    40,     0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    25,    23,     7,    15,    16,     8,
      26,    27,    84,    78,    79,    80,    92,    36,   113,   114,
     115,   116,   117,   135,   130,    59,    63,    37,    82,    54,
      39,    40,    41,    42,    43,    44
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -72
static const yytype_int16 yypact[] =
{
       4,   -27,    -4,    29,     4,   -72,    -4,   -72,   -72,   -72,
     -72,     0,   -72,   -72,   -72,    -8,   -72,    11,    -3,   -72,
      -4,   171,     3,    13,    30,    -4,    -2,   -72,   -72,    19,
     -72,   -72,   -72,   -72,   -72,   171,    35,   171,    32,   -19,
     -72,   -72,    36,   -72,    49,    30,     9,   171,    98,   -72,
      55,    78,    30,    56,    32,   171,   -72,   -72,   -72,   171,
     -72,   -72,   -72,   171,   -72,    34,   -72,    30,    59,    63,
      64,    62,    60,    61,   -72,   -72,   -72,    -4,   -72,   124,
     -72,    -9,    67,   161,    70,   -72,   -72,   -72,    73,   -19,
     -72,   -72,    22,   -72,   -72,   -72,   171,   171,   -72,    69,
     -72,   -72,   -72,   -72,   -72,   171,   -72,   -72,    74,   171,
     -72,   171,   -72,    84,   104,   106,    58,    16,    32,    86,
     -72,    90,   -72,    92,   -72,   150,   171,   171,   -72,   -72,
     171,   -72,   -72,   -72,   -72,   171,   150,   -72,   -72,   113,
     106,    58,    16,    32,   -72,   150,   -72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,   -72,     1,     2,   -72,   -72,   -72,   110,   127,
     112,    81,   -72,   -14,   -72,   -71,   -72,   -47,    43,   -72,
      24,    21,    25,   -72,   -72,   -72,   -72,   -72,   -32,   -21,
      93,   -23,   -72,   109,   -72,     5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      38,    81,     6,    53,     9,    13,     6,    11,   104,     1,
      49,    17,    60,    61,    56,     1,     1,    10,     2,   105,
     131,   132,    62,    88,    55,    29,    38,    19,    20,    12,
      50,    66,    81,    93,    51,    24,    52,    18,    86,    99,
      90,    45,   133,   134,    21,    51,    47,    67,    22,    76,
      77,   108,    21,    94,   139,    10,    30,    31,   111,    32,
     112,    57,    58,    33,    34,   144,   128,   129,    55,    48,
      64,    35,    91,   121,   146,   118,   118,   123,    81,   124,
     103,    77,    29,    10,    30,    31,    65,    32,    83,    81,
       1,    33,    34,    95,    87,   100,   101,    98,    81,    35,
      96,    97,   106,   109,   120,   118,   118,   110,   122,   118,
       1,   126,   127,    69,   143,    70,    71,    72,    73,    10,
      30,    31,   125,    32,   136,   137,   138,    33,    34,   145,
      28,    14,    85,    74,    46,    35,     1,    48,    75,    69,
     119,    70,    71,    72,    73,    10,    30,    31,   141,    32,
     140,     0,    89,    33,    34,   142,    68,     0,     0,    74,
       0,    35,     0,    48,   102,    69,     0,    70,    71,    72,
      73,    10,    30,    31,     0,    32,     0,     0,     0,    33,
      34,     0,    10,    30,    31,    74,    32,    35,     0,    48,
      33,    34,    10,    30,    31,   107,    32,     0,    35,     0,
      33,    34,     0,     0,     0,     0,     0,     0,    35
};

static const yytype_int16 yycheck[] =
{
      21,    48,     0,    35,    31,     4,     4,     2,    79,    12,
      24,     6,    31,    32,    37,    12,    12,    21,    14,    28,
       4,     5,    41,    55,    33,    20,    47,    35,    36,     0,
      25,    45,    79,    65,    36,    38,    38,    37,    52,    71,
      63,    38,    26,    27,    33,    36,    33,    38,    37,    48,
      48,    83,    33,    67,   125,    21,    22,    23,    36,    25,
      38,    29,    30,    29,    30,   136,     8,     9,    33,    39,
      34,    37,    38,   105,   145,    96,    97,   109,   125,   111,
      79,    79,    77,    21,    22,    23,    37,    25,    33,   136,
      12,    29,    30,    34,    38,    35,    35,    35,   145,    37,
      37,    37,    35,    33,    35,   126,   127,    34,    34,   130,
      12,     7,     6,    15,   135,    17,    18,    19,    20,    21,
      22,    23,    38,    25,    38,    35,    34,    29,    30,    16,
      20,     4,    51,    35,    22,    37,    12,    39,    40,    15,
      97,    17,    18,    19,    20,    21,    22,    23,   127,    25,
     126,    -1,    59,    29,    30,   130,    47,    -1,    -1,    35,
      -1,    37,    -1,    39,    40,    15,    -1,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    -1,    -1,    -1,    29,
      30,    -1,    21,    22,    23,    35,    25,    37,    -1,    39,
      29,    30,    21,    22,    23,    34,    25,    -1,    37,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    14,    43,    44,    45,    46,    48,    51,    31,
      21,    77,     0,    45,    51,    49,    50,    77,    37,    35,
      36,    33,    37,    47,    38,    46,    52,    53,    50,    77,
      22,    23,    25,    29,    30,    37,    59,    69,    71,    72,
      73,    74,    75,    76,    77,    38,    52,    33,    39,    55,
      77,    36,    38,    70,    71,    33,    73,    29,    30,    67,
      31,    32,    41,    68,    34,    37,    55,    38,    75,    15,
      17,    18,    19,    20,    35,    40,    45,    46,    55,    56,
      57,    59,    70,    33,    54,    53,    55,    38,    70,    72,
      73,    38,    58,    70,    55,    34,    37,    37,    35,    70,
      35,    35,    40,    45,    57,    28,    35,    34,    70,    33,
      34,    36,    38,    60,    61,    62,    63,    64,    71,    60,
      35,    70,    34,    70,    70,    38,     7,     6,     8,     9,
      66,     4,     5,    26,    27,    65,    38,    35,    34,    57,
      62,    63,    64,    71,    57,    16,    57
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1464 of yacc.c  */
#line 132 ".\\minic_yacc.y"
    {
        (yyval.all).ast_node=&ast_root;
        (yyval.all).ast_node->type = program;
        set_node_val_str((yyval.all).ast_node,"program");
        add_son_node(&ast_root,(yyvsp[(1) - (1)].all).ast_node);
        printf("\n");;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 141 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type=decList;
        set_node_val_str((yyval.all).ast_node,"compUnit");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (2)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (2)].all).ast_node);

        setScope("GLOBAL");
        ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 150 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type=decList;
        set_node_val_str((yyval.all).ast_node,"compUnit");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (2)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (2)].all).ast_node);

        setScope("GLOBAL");
        ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 159 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type=decList;
        set_node_val_str((yyval.all).ast_node,"compUnit");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);

        setScope("GLOBAL");
        ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 167 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type=decList;
        set_node_val_str((yyval.all).ast_node,"compUnit");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);

        setScope("GLOBAL");
        ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 178 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type=decList;
        set_node_val_str((yyval.all).ast_node,"Decl");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 188 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type=sym;
        set_node_val_str((yyval.all).ast_node,"int");

        (yyval.all).type = TYPE_INT;
    ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 196 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type=sym;
        set_node_val_str((yyval.all).ast_node,"int*");

        (yyval.all).type = TYPE_INT_START;
    ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 206 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expList;
        set_node_val_str((yyval.all).ast_node,"ConstSubscripts");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (4)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (4)].all).ast_node);
    ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 213 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expList;
        set_node_val_str((yyval.all).ast_node,"ConstSubscripts");
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (3)].all).ast_node);
        ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 223 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = decList;
        set_node_val_str((yyval.all).ast_node,"VarDecl");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (3)].all).ast_node);

        // for symbol table
        registerVariables((yyvsp[(1) - (3)].all).type, (yyvsp[(2) - (3)].all).var_list);
    ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 237 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = decList;
        set_node_val_str((yyval.all).ast_node,"VarDefList");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (3)].all).ast_node);

        // for symbol table
        (yyval.all).var_list = appendList((yyvsp[(1) - (3)].all).var_list, (yyvsp[(3) - (3)].all).var);
    ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 247 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = decList;
        set_node_val_str((yyval.all).ast_node,"VarDefList");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);

        // for symbol table
        (yyval.all).var_list = appendList(NULL, (yyvsp[(1) - (1)].all).var);
        ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 259 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = dec;
        set_node_val_str((yyval.all).ast_node,"VarDef");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        //entry($1.id_str);
        (yyval.all).var = (yyvsp[(1) - (1)].all).var;
        ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 268 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = dec;
        set_node_val_str((yyval.all).ast_node,"VarDef");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (2)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (2)].all).ast_node);

        //entry($1.id_str);
        (yyval.all).var = (yyvsp[(1) - (2)].all).var;
        (yyval.all).var->isArray = 1;
    ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 284 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = dec;
        set_node_val_str((yyval.all).ast_node,"FuncDef");
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (6)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(4) - (6)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(6) - (6)].all).ast_node);

        setScope((yyvsp[(2) - (6)].all).var->id);
        registerFunc(TYPE_VOID, (yyvsp[(2) - (6)].all).var->id);
    ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 295 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = dec;
        set_node_val_str((yyval.all).ast_node,"FuncDef");
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (5)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(5) - (5)].all).ast_node);

        setScope((yyvsp[(2) - (5)].all).var->id);
        registerFunc(TYPE_VOID, (yyvsp[(2) - (5)].all).var->id);
    ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 305 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = dec;
        set_node_val_str((yyval.all).ast_node,"FuncDef");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (6)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (6)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(4) - (6)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(6) - (6)].all).ast_node);

        setScope((yyvsp[(2) - (6)].all).var->id);
        registerFunc((yyvsp[(1) - (6)].all).type, (yyvsp[(2) - (6)].all).var->id);
    ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 317 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = dec;
        set_node_val_str((yyval.all).ast_node,"FuncDef");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (5)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (5)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(5) - (5)].all).ast_node);

        setScope((yyvsp[(2) - (5)].all).var->id);
        registerFunc((yyvsp[(1) - (5)].all).type, (yyvsp[(2) - (5)].all).var->id);
    ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 332 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = fieldList;
        set_node_val_str((yyval.all).ast_node,"FuncFParams");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (3)].all).ast_node);
    ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 339 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = fieldList;
        set_node_val_str((yyval.all).ast_node,"FuncFParams");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 348 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = field;
        set_node_val_str((yyval.all).ast_node,"FuncFParam");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (2)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (2)].all).ast_node);

        registerVariable((yyvsp[(1) - (2)].all).type, (yyvsp[(2) - (2)].all).var->id, 0);
        ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 357 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = field;
        set_node_val_str((yyval.all).ast_node,"FuncFParam");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (3)].all).ast_node);

        registerVariable((yyvsp[(1) - (3)].all).type, (yyvsp[(2) - (3)].all).var->id, 1);
        ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 370 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expList;
        set_node_val_str((yyval.all).ast_node,"ExpSubscripts");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (4)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (4)].all).ast_node);
        ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 377 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expList;
        set_node_val_str((yyval.all).ast_node,"ExpSubscripts");
        ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 382 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expList;
        set_node_val_str((yyval.all).ast_node,"ExpSubscripts");
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (3)].all).ast_node);
       ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 391 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = stm;
        set_node_val_str((yyval.all).ast_node,"Block");
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (3)].all).ast_node);
        ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 397 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = stm;
        set_node_val_str((yyval.all).ast_node,"Block");
        ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 405 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = comStmList;
        set_node_val_str((yyval.all).ast_node,"BlockItem");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (2)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (2)].all).ast_node);
        ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 412 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = comStmList;
        set_node_val_str((yyval.all).ast_node,"BlockItem");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (2)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (2)].all).ast_node);
        ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 419 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = comStmList;
        set_node_val_str((yyval.all).ast_node,"BlockItem");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 425 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = comStmList;
        set_node_val_str((yyval.all).ast_node,"BlockItem");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 434 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = stm;
        set_node_val_str((yyval.all).ast_node,"=");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (4)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (4)].all).ast_node);
        ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 441 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = stm;
        set_node_val_str((yyval.all).ast_node,"Stmt");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (2)].all).ast_node);
        ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 447 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = stm;
        set_node_val_str((yyval.all).ast_node,"null_Stmt");
        ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 452 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = stm;
        set_node_val_str((yyval.all).ast_node,"Stmt");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 458 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = stm;
        set_node_val_str((yyval.all).ast_node,"IF_Statement");
        struct ndoe *tmpnode = NULL;
        set_node_val_str(tmpnode,"if");
        add_son_node((yyval.all).ast_node,tmpnode);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (5)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(5) - (5)].all).ast_node);
        ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 468 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = stm;
        set_node_val_str((yyval.all).ast_node,"IF_ELSE_Statement");
        struct ndoe *tmpnode1 = NULL;
        struct ndoe *tmpnode2 = NULL;
        set_node_val_str(tmpnode1,"if");
        set_node_val_str(tmpnode2,"else");
        add_son_node((yyval.all).ast_node,tmpnode1);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (7)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(5) - (7)].all).ast_node);
        add_son_node((yyval.all).ast_node,tmpnode2);
        add_son_node((yyval.all).ast_node,(yyvsp[(7) - (7)].all).ast_node);
        ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 482 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = stm;
        set_node_val_str((yyval.all).ast_node,"WHILE_Statement");
        struct ndoe *tmpnode = NULL;
    set_node_val_str(tmpnode,"while");
        add_son_node((yyval.all).ast_node,tmpnode);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (5)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(5) - (5)].all).ast_node);
        ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 492 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = stm;
        set_node_val_str((yyval.all).ast_node,"break");
        ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 497 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = stm;
        set_node_val_str((yyval.all).ast_node,"continue");
        ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 502 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = stm;
        set_node_val_str((yyval.all).ast_node,"return");
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (3)].all).ast_node);
        ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 508 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = stm;
        set_node_val_str((yyval.all).ast_node,"return");
        ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 516 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expList;
        set_node_val_str((yyval.all).ast_node,"FuncRParams");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (3)].all).ast_node);
        ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 523 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expList;
        set_node_val_str((yyval.all).ast_node,"FuncRParams");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 532 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = var;
        set_node_val_str((yyval.all).ast_node,"LVal");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 538 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = var;
        set_node_val_str((yyval.all).ast_node,"LVal");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (4)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (4)].all).ast_node);
        ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 548 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"Cond");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 557 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"LOrExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 563 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"LOrExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (3)].all).ast_node);
        ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 573 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"LAndExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 579 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"LAndExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (3)].all).ast_node);
        ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 589 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"EqExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 595 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"EqExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (3)].all).ast_node);
        ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 606 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"RelExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 612 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"RelExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (3)].all).ast_node);
        ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 623 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = binOp;
        set_node_val_str((yyval.all).ast_node,"<");
        ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 628 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = binOp;
        set_node_val_str((yyval.all).ast_node,"<=");
        ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 633 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = binOp;
        set_node_val_str((yyval.all).ast_node,">");
        ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 638 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = binOp;
        set_node_val_str((yyval.all).ast_node,">=");
        ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 646 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = binOp;
        set_node_val_str((yyval.all).ast_node,"==");
        ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 651 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = binOp;
        set_node_val_str((yyval.all).ast_node,"!=");
        ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 659 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = binOp;
        set_node_val_str((yyval.all).ast_node,"+");
        ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 664 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = binOp;
        set_node_val_str((yyval.all).ast_node,"-");
        ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 672 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = binOp;
        set_node_val_str((yyval.all).ast_node,"*");
        ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 677 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = binOp;
        set_node_val_str((yyval.all).ast_node,"/");
        ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 682 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = binOp;
        set_node_val_str((yyval.all).ast_node,"%");
        ;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 690 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = binOp;
        set_node_val_str((yyval.all).ast_node,"+");
        ;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 695 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = binOp;
        set_node_val_str((yyval.all).ast_node,"-");
        ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 700 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = binOp;
        set_node_val_str((yyval.all).ast_node,"!");
        ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 708 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"Exp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 717 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"AddExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 723 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"AddExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (3)].all).ast_node);
        ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 734 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"MulExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 740 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"MulExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (3)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (3)].all).ast_node);
        ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 751 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"UnaryExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 757 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"UnaryExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (4)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(3) - (4)].all).ast_node);
    ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 764 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"UnaryExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (3)].all).ast_node);
    ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 770 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"UnaryExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (2)].all).ast_node);
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (2)].all).ast_node);
    ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 780 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"PrimaryExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(2) - (3)].all).ast_node);
        ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 786 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"PrimaryExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 792 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"PrimaryExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
    ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 798 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,yytext);
        ;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 806 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = expr;
        set_node_val_str((yyval.all).ast_node,"ConstExp");
        add_son_node((yyval.all).ast_node,(yyvsp[(1) - (1)].all).ast_node);
        ;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 815 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = integer;
        set_node_val_str((yyval.all).ast_node,yytext);
        ;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 823 ".\\minic_yacc.y"
    {
        new_node(&((yyval.all).ast_node));
        (yyval.all).ast_node->type = integer;
        set_node_val_str((yyval.all).ast_node,yytext);
        //entry(yytext);
        //$$.id_str = String(yytext);
        (yyval.all).var = VarInfo(String(yytext));
        ;}
    break;



/* Line 1464 of yacc.c  */
#line 2696 "minic_yacc.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1684 of yacc.c  */
#line 833 ".\\minic_yacc.y"


int yyerror(char *errstr)
{
	// printf("\nReason:%s\nline_no:%d\n", errstr,line_no);
	printf("\n%d: %s at %s\n\n",yylineno,errstr,yytext);
	return 0;
}




