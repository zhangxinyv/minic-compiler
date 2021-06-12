%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "minic_yacc.h"
#include "table.h"

/* 行号 */
int line_no = 1;
// 行号还有问题
#define MAXSTR 20
char varname[MAXSTR];

%}
%option yylineno
add_ops "+"|"-"
mul_ops "*"|"/"
letter [_a-zA-z]
no_zero_num [1-9]
num 0|{no_zero_num}
unsign_int {no_zero_num}({num})*
character \'{add_ops}?\'|\'{mul_ops}?\'|\'{letter}?\'|\'{num}?\'
string \"[^"]*\"

%%

"<" {ECHO;return '<';}
">" {ECHO;return '>';}
"=" {ECHO;return '=';}
"+" {ECHO;return '+';}
"-" {ECHO;return '-';}
"*" {ECHO;return '*';}
"/" {ECHO;return '/';}
"!" {ECHO;return '!';}
"%" {ECHO;return '%';}
";" {ECHO;return ';';}
"," {ECHO;return ',';}
":" {ECHO;return ':';}
"(" {ECHO;return '(';}
")" {ECHO;return ')';}
"[" {ECHO;return '[';}
"]" {ECHO;return ']';}
"{" {ECHO;return '{';}
"}" {ECHO;return '}';}

"<=" {ECHO;return LE;}
">=" {ECHO;return GE;}
"==" {ECHO;return EQ;}
"!=" {ECHO;return NE;}
"&&" {ECHO;return AND;}
"||" {ECHO;return OR;}
"++" {ECHO;return SELFPULS;}
"--" {ECHO;return SELPMINUS;}

int {ECHO;return INT;}
void {ECHO;return VOID;}
char {ECHO;return CHAR;}
if {ECHO;return IF;}
else {ECHO;return ELSE;}
while {ECHO;return WHILE;}
return {ECHO;return RETURN;}
break {ECHO;return BREAK;}
continue {ECHO;return CONTINUE;}
[a-zA-Z_][a-zA-Z0-9_]* { ECHO; strcpy(varname,yytext); return ID; }
{unsign_int}|0 { ECHO;  return INTEGER;  }
{string} { ECHO; return STRING; }
{character} { ECHO;  return CHARACTER; }

[\r\n] {ECHO;line_no++;}
[ \t\f]+  { ECHO; }

.	{printf("Invalid char %s\n",yytext);return ERRORCHAR; }

%%

#ifndef yywrap
int yywrap()
{
	return 1;
}
#endif
