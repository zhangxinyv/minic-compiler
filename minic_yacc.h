/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* "%code requires" blocks.  */

/* Line 1685 of yacc.c  */
#line 25 ".\\minic_yacc.y"

#include "util.h"



/* Line 1685 of yacc.c  */
#line 45 "minic_yacc.h"

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

/* Line 1685 of yacc.c  */
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



/* Line 1685 of yacc.c  */
#line 118 "minic_yacc.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


