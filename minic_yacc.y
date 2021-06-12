%{
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
extern int line_no;
int yyerror(char*);
int flag_var_def = 0;

%}
%union
{
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
	}all;
	char str[20];
    char character;
    int integer;
}
%token ERRORCHAR 600
%token LE 500
%token GE 501
%token AND 502
%token OR 503
%token EQ 504
%token NE 505
%token SELFPULS 506
%token SELPMINUS 507

%token INT 401
%token CHAR 402
%token VOID 403
%token IF 405
%token ELSE 406
%token WHILE 407
%token RETURN 410
%token BREAK 411
%token CONTINUE 412

%token <str> ID 300
%token <integer> INTEGER 301
%token <str> STRING 302
%token <character> CHARACTER

%left OR
%left AND
%nonassoc '!'
%nonassoc '<' '>' '=' LE GE NE EQ
%left '+' '-'
%left '*' '/'

%type <all> program
%type <all> LVal
%type <all> Number
%type <all> Ident
%type <all> BType
%type <all> addOp
%type <all> mulOp
%type <all> UnaryOp
%type <all> RelOp
%type <all> EqOp
%type <all> ConstSubscripts
%type <all> Block
%type <all> BlockItem
%type <all> ExpSubscripts
%type <all> FuncRParams
%type <all> Cond
%type <all> Exp
%type <all> ConstExp
%type <all> LOrExp
%type <all> LAndExp
%type <all> EqExp
%type <all> RelExp
%type <all> AddExp
%type <all> MulExp
%type <all> UnaryExp
%type <all> PrimaryExp
%type <all> CompUnit
%type <all> Decl
%type <all> VarDecl
%type <all> VarDefList
%type <all> VarDef
%type <all> FuncDef
%type <all> FuncFParam
%type <all> FuncFParams
%type <all> Stmt


//%locations
%error-verbose
%start program
%%
program:
    CompUnit {
        $$.ast_node=&ast_root;
        $$.ast_node->type = program;
        set_node_val_str($$.ast_node,"program");
        add_son_node(&ast_root,$1.ast_node);
        printf("\n");}
    ;

CompUnit:
    CompUnit Decl {
        new_node(&($$.ast_node));
        $$.ast_node->type=decList;
        set_node_val_str($$.ast_node,"compUnit");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$2.ast_node);}

    | CompUnit FuncDef {
        new_node(&($$.ast_node));
        $$.ast_node->type=decList;
        set_node_val_str($$.ast_node,"compUnit");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$2.ast_node);}

    | Decl {
        new_node(&($$.ast_node));
        $$.ast_node->type=decList;
        set_node_val_str($$.ast_node,"compUnit");
        add_son_node($$.ast_node,$1.ast_node);}

    | FuncDef {
        new_node(&($$.ast_node));
        $$.ast_node->type=decList;
        set_node_val_str($$.ast_node,"compUnit");
        add_son_node($$.ast_node,$1.ast_node);}
    ;

Decl:
    VarDecl {
        new_node(&($$.ast_node));
        $$.ast_node->type=decList;
        set_node_val_str($$.ast_node,"Decl");
        add_son_node($$.ast_node,$1.ast_node);}
    ;


BType:
    INT
    {
        new_node(&($$.ast_node));
        $$.ast_node->type=sym;
        set_node_val_str($$.ast_node,"int");
        //$$.var_type = "int";
        //TODO
    }
    | INT '*'
    {
        new_node(&($$.ast_node));
        $$.ast_node->type=sym;
        set_node_val_str($$.ast_node,"int*");
    }
    ;

ConstSubscripts:
    ConstSubscripts '[' ConstExp ']' {
        new_node(&($$.ast_node));
        $$.ast_node->type = expList;
        set_node_val_str($$.ast_node,"ConstSubscripts");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$3.ast_node);
    }
    | '[' ConstExp ']' {
        new_node(&($$.ast_node));
        $$.ast_node->type = expList;
        set_node_val_str($$.ast_node,"ConstSubscripts");
        add_son_node($$.ast_node,$2.ast_node);
        }
    ;

VarDecl:
    BType VarDefList ';'
    {
        new_node(&($$.ast_node));
        $$.ast_node->type = decList;
        set_node_val_str($$.ast_node,"VarDecl");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$2.ast_node);
        /*$2.var_ids = [a, b, c, d]
        $1.var_type = "int";

        for id in $2.var_ids:
            if $1.var_type == "int":
                no = enter(id, 0);
            else:
                no = enter(id, 1);*/
        //TODO
    }
    ;

VarDefList:
    VarDefList ',' VarDef
    {
        new_node(&($$.ast_node));
        $$.ast_node->type = decList;
        set_node_val_str($$.ast_node,"VarDefList");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$3.ast_node);
        //$3.var_id <-
        //insert($1.var_ids, $3.var_id);
        //copy($$, $1);
        //TODO
    }
    | VarDef {
        new_node(&($$.ast_node));
        $$.ast_node->type = decList;
        set_node_val_str($$.ast_node,"VarDefList");
        add_son_node($$.ast_node,$1.ast_node);
        // $$.var_ids: List;
        //insert($$.var_ids, $1.var_id);
        // $1.var_id <-
        //TODO

        }
    ;

VarDef:
    Ident {
        new_node(&($$.ast_node));
        $$.ast_node->type = dec;
        set_node_val_str($$.ast_node,"VarDef");
        add_son_node($$.ast_node,$1.ast_node);
        //$$.var_id = $1.var_id;
        //TODO
        }

    | Ident ConstSubscripts {
        new_node(&($$.ast_node));
        $$.ast_node->type = dec;
        set_node_val_str($$.ast_node,"VarDef");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$2.ast_node);
        //TODO

    }
    ;


FuncDef:
    VOID Ident '(' FuncFParams ')' Block
    {
        new_node(&($$.ast_node));
        $$.ast_node->type = dec;
        set_node_val_str($$.ast_node,"FuncDef");
        add_son_node($$.ast_node,$2.ast_node);
        add_son_node($$.ast_node,$4.ast_node);
        add_son_node($$.ast_node,$6.ast_node);
    }
    | VOID Ident '(' ')' Block {
        new_node(&($$.ast_node));
        $$.ast_node->type = dec;
        set_node_val_str($$.ast_node,"FuncDef");
        add_son_node($$.ast_node,$2.ast_node);
        add_son_node($$.ast_node,$5.ast_node);
    }
    | BType Ident '(' FuncFParams ')' Block {
        new_node(&($$.ast_node));
        $$.ast_node->type = dec;
        set_node_val_str($$.ast_node,"FuncDef");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$2.ast_node);
        add_son_node($$.ast_node,$4.ast_node);
        add_son_node($$.ast_node,$6.ast_node);
    }
    | BType Ident '(' ')' Block {
        new_node(&($$.ast_node));
        $$.ast_node->type = dec;
        set_node_val_str($$.ast_node,"FuncDef");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$2.ast_node);
        add_son_node($$.ast_node,$5.ast_node);
    }
    ;

FuncFParams:
    FuncFParams ',' FuncFParam
    {
        new_node(&($$.ast_node));
        $$.ast_node->type = fieldList;
        set_node_val_str($$.ast_node,"FuncFParams");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$3.ast_node);
    }
    | FuncFParam {
        new_node(&($$.ast_node));
        $$.ast_node->type = fieldList;
        set_node_val_str($$.ast_node,"FuncFParams");
        add_son_node($$.ast_node,$1.ast_node);
        }
    ;

FuncFParam:
    BType Ident {
        new_node(&($$.ast_node));
        $$.ast_node->type = field;
        set_node_val_str($$.ast_node,"FuncFParam");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$2.ast_node);
        }
    | BType Ident  ExpSubscripts {
        new_node(&($$.ast_node));
        $$.ast_node->type = field;
        set_node_val_str($$.ast_node,"FuncFParam");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$2.ast_node);
        add_son_node($$.ast_node,$3.ast_node);
        }
    ;

ExpSubscripts:
    ExpSubscripts '[' Exp ']' {
        new_node(&($$.ast_node));
        $$.ast_node->type = expList;
        set_node_val_str($$.ast_node,"ExpSubscripts");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$3.ast_node);
        }
    | '[' ']' {
        new_node(&($$.ast_node));
        $$.ast_node->type = expList;
        set_node_val_str($$.ast_node,"ExpSubscripts");
        }
    | '[' Exp ']' {
        new_node(&($$.ast_node));
        $$.ast_node->type = expList;
        set_node_val_str($$.ast_node,"ExpSubscripts");
        add_son_node($$.ast_node,$2.ast_node);
       }
    ;

Block:
    '{' BlockItem '}' {
        new_node(&($$.ast_node));
        $$.ast_node->type = stm;
        set_node_val_str($$.ast_node,"Block");
        add_son_node($$.ast_node,$2.ast_node);
        }
	|'{' '}' {
        new_node(&($$.ast_node));
        $$.ast_node->type = stm;
        set_node_val_str($$.ast_node,"Block");
        }
    ;

BlockItem:
    BlockItem Decl {
        new_node(&($$.ast_node));
        $$.ast_node->type = comStmList;
        set_node_val_str($$.ast_node,"BlockItem");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$2.ast_node);
        }
    | BlockItem Stmt {
        new_node(&($$.ast_node));
        $$.ast_node->type = comStmList;
        set_node_val_str($$.ast_node,"BlockItem");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$2.ast_node);
        }
    | Decl {
        new_node(&($$.ast_node));
        $$.ast_node->type = comStmList;
        set_node_val_str($$.ast_node,"BlockItem");
        add_son_node($$.ast_node,$1.ast_node);
        }
    | Stmt {
        new_node(&($$.ast_node));
        $$.ast_node->type = comStmList;
        set_node_val_str($$.ast_node,"BlockItem");
        add_son_node($$.ast_node,$1.ast_node);
        }
    ;

Stmt:
    LVal '=' Exp ';' {
        new_node(&($$.ast_node));
        $$.ast_node->type = stm;
        set_node_val_str($$.ast_node,"=");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$3.ast_node);
        }
    | Exp ';' {
        new_node(&($$.ast_node));
        $$.ast_node->type = stm;
        set_node_val_str($$.ast_node,"Stmt");
        add_son_node($$.ast_node,$1.ast_node);
        }
	| ';' {
        new_node(&($$.ast_node));
        $$.ast_node->type = stm;
        set_node_val_str($$.ast_node,"null_Stmt");
        }
    | Block {
        new_node(&($$.ast_node));
        $$.ast_node->type = stm;
        set_node_val_str($$.ast_node,"Stmt");
        add_son_node($$.ast_node,$1.ast_node);
        }
    | IF '(' Cond ')' Stmt {
        new_node(&($$.ast_node));
        $$.ast_node->type = stm;
        set_node_val_str($$.ast_node,"IF_Statement");
        struct ndoe *tmpnode = NULL;
        set_node_val_str(tmpnode,"if");
        add_son_node($$.ast_node,tmpnode);
        add_son_node($$.ast_node,$3.ast_node);
        add_son_node($$.ast_node,$5.ast_node);
        }
    | IF '(' Cond ')' Stmt ELSE Stmt {
        new_node(&($$.ast_node));
        $$.ast_node->type = stm;
        set_node_val_str($$.ast_node,"IF_ELSE_Statement");
        struct ndoe *tmpnode1 = NULL;
        struct ndoe *tmpnode2 = NULL;
        set_node_val_str(tmpnode1,"if");
        set_node_val_str(tmpnode2,"else");
        add_son_node($$.ast_node,tmpnode1);
        add_son_node($$.ast_node,$3.ast_node);
        add_son_node($$.ast_node,$5.ast_node);
        add_son_node($$.ast_node,tmpnode2);
        add_son_node($$.ast_node,$7.ast_node);
        }
    | WHILE '(' Cond ')' Stmt {
        new_node(&($$.ast_node));
        $$.ast_node->type = stm;
        set_node_val_str($$.ast_node,"WHILE_Statement");
        struct ndoe *tmpnode = NULL;
        set_node_val_str(tmpnode1,"while");
        add_son_node($$.ast_node,tmpnode);
        add_son_node($$.ast_node,$3.ast_node);
        add_son_node($$.ast_node,$5.ast_node);
        }
    | BREAK ';' {
        new_node(&($$.ast_node));
        $$.ast_node->type = stm;
        set_node_val_str($$.ast_node,"break");
        }
    | CONTINUE ';' {
        new_node(&($$.ast_node));
        $$.ast_node->type = stm;
        set_node_val_str($$.ast_node,"continue");
        }
    | RETURN Exp ';' {
        new_node(&($$.ast_node));
        $$.ast_node->type = stm;
        set_node_val_str($$.ast_node,"return");
        add_son_node($$.ast_node,$2.ast_node);
        }
    | RETURN ';' {
        new_node(&($$.ast_node));
        $$.ast_node->type = stm;
        set_node_val_str($$.ast_node,"return");
        }
    ;

FuncRParams:
    FuncRParams ',' Exp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expList;
        set_node_val_str($$.ast_node,"FuncRParams");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$3.ast_node);
        }
    | Exp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expList;
        set_node_val_str($$.ast_node,"FuncRParams");
        add_son_node($$.ast_node,$1.ast_node);
        }
    ;

LVal:
    Ident {
        new_node(&($$.ast_node));
        $$.ast_node->type = var;
        set_node_val_str($$.ast_node,"LVal");
        add_son_node($$.ast_node,$1.ast_node);
        }
    | LVal '[' Exp ']' {
        new_node(&($$.ast_node));
        $$.ast_node->type = var;
        set_node_val_str($$.ast_node,"LVal");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$3.ast_node);
        }
    ;

Cond:
    LOrExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"Cond");
        add_son_node($$.ast_node,$1.ast_node);
        }
    ;

LOrExp:
    LAndExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"LOrExp");
        add_son_node($$.ast_node,$1.ast_node);
        }
    | LOrExp OR LAndExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"LOrExp");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$3.ast_node);
        }
    ;

LAndExp:
    EqExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"LAndExp");
        add_son_node($$.ast_node,$1.ast_node);
        }
    | LAndExp AND EqExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"LAndExp");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$3.ast_node);
        }
    ;

EqExp:
    RelExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"EqExp");
        add_son_node($$.ast_node,$1.ast_node);
        }
    | EqExp EqOp RelExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"EqExp");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$2.ast_node);
        add_son_node($$.ast_node,$3.ast_node);
        }
    ;

RelExp:
    AddExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"RelExp");
        add_son_node($$.ast_node,$1.ast_node);
        }
    | RelExp RelOp AddExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"RelExp");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$2.ast_node);
        add_son_node($$.ast_node,$3.ast_node);
        }
    ;

RelOp:
    '<' {
        new_node(&($$.ast_node));
        $$.ast_node->type = binOp;
        set_node_val_str($$.ast_node,"<");
        }
    | LE {
        new_node(&($$.ast_node));
        $$.ast_node->type = binOp;
        set_node_val_str($$.ast_node,"<=");
        }
    | '>' {
        new_node(&($$.ast_node));
        $$.ast_node->type = binOp;
        set_node_val_str($$.ast_node,">");
        }
    | GE {
        new_node(&($$.ast_node));
        $$.ast_node->type = binOp;
        set_node_val_str($$.ast_node,">=");
        }
    ;

EqOp:
    EQ {
        new_node(&($$.ast_node));
        $$.ast_node->type = binOp;
        set_node_val_str($$.ast_node,"==");
        }
    | NE {
        new_node(&($$.ast_node));
        $$.ast_node->type = binOp;
        set_node_val_str($$.ast_node,"!=");
        }
    ;

addOp:
    '+' {
        new_node(&($$.ast_node));
        $$.ast_node->type = binOp;
        set_node_val_str($$.ast_node,"+");
        }
    | '-' {
        new_node(&($$.ast_node));
        $$.ast_node->type = binOp;
        set_node_val_str($$.ast_node,"-");
        }
    ;

mulOp:
    '*' {
        new_node(&($$.ast_node));
        $$.ast_node->type = binOp;
        set_node_val_str($$.ast_node,"*");
        }
    |'/' {
        new_node(&($$.ast_node));
        $$.ast_node->type = binOp;
        set_node_val_str($$.ast_node,"/");
        }
    |'%' {
        new_node(&($$.ast_node));
        $$.ast_node->type = binOp;
        set_node_val_str($$.ast_node,"%");
        }
    ;

UnaryOp:
    '+' {
        new_node(&($$.ast_node));
        $$.ast_node->type = binOp;
        set_node_val_str($$.ast_node,"+");
        }
    | '-' {
        new_node(&($$.ast_node));
        $$.ast_node->type = binOp;
        set_node_val_str($$.ast_node,"-");
        }
    | '!' {
        new_node(&($$.ast_node));
        $$.ast_node->type = binOp;
        set_node_val_str($$.ast_node,"!");
        }
    ;

Exp:
    AddExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"Exp");
        add_son_node($$.ast_node,$1.ast_node);
        }
    ;

AddExp:
    MulExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"AddExp");
        add_son_node($$.ast_node,$1.ast_node);
        }
    | AddExp addOp MulExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"AddExp");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$2.ast_node);
        add_son_node($$.ast_node,$3.ast_node);
        }
    ;

MulExp:
    UnaryExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"MulExp");
        add_son_node($$.ast_node,$1.ast_node);
        }
    | MulExp mulOp UnaryExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"MulExp");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$2.ast_node);
        add_son_node($$.ast_node,$3.ast_node);
        }
    ;

UnaryExp:
    PrimaryExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"UnaryExp");
        add_son_node($$.ast_node,$1.ast_node);
        }
    | Ident '(' FuncRParams ')' {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"UnaryExp");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$3.ast_node);
    }
    | Ident '(' ')' {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"UnaryExp");
        add_son_node($$.ast_node,$1.ast_node);
    }
    | UnaryOp UnaryExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"UnaryExp");
        add_son_node($$.ast_node,$1.ast_node);
        add_son_node($$.ast_node,$2.ast_node);
    }
    ;

PrimaryExp:
    '(' Exp ')' {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"PrimaryExp");
        add_son_node($$.ast_node,$2.ast_node);
        }
    | LVal {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"PrimaryExp");
        add_son_node($$.ast_node,$1.ast_node);
        }
    | Number {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"PrimaryExp");
        add_son_node($$.ast_node,$1.ast_node);
    }
    | STRING {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,yytext);
        }
    ;

ConstExp:
    AddExp {
        new_node(&($$.ast_node));
        $$.ast_node->type = expr;
        set_node_val_str($$.ast_node,"ConstExp");
        add_son_node($$.ast_node,$1.ast_node);
        }
    ;

Number:
    INTEGER {
        new_node(&($$.ast_node));
        $$.ast_node->type = integer;
        set_node_val_str($$.ast_node,yytext);
        }
    ;

Ident:
    ID {
        new_node(&($$.ast_node));
        $$.ast_node->type = integer;
        set_node_val_str($$.ast_node,yytext);
        //$$.var_id = $1;
        //TODO
        }
    ;

%%

int yyerror(char *errstr)
{
	// printf("\nReason:%s\nline_no:%d\n", errstr,line_no);
	printf("\n%d: %s at %s\n\n",yylineno,errstr,yytext);
	return 0;
}


