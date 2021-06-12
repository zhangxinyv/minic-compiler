#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "table.h"
#include "minic_yacc.h"

/*
 * 请在本文件中编写有关词法与语法分析中所需要用到有关符号表相关的函数
 */

table_variable VarList[TABLE_MAX_VAR_NUM];

int VarCount = 1;

int tempVarCount = 1;

static char KeyWord[][TABLE_MAX_IDENT_NAME_LEN] = {
        "int",
        "void",
        "while",
        "if",
        "else",
        "break",
        "continue",
        "return",
};

int id_or_keyword(char *str)
{
    unsigned int i, j;
    char *p, buf[TABLE_MAX_IDENT_NAME_LEN];

    for (i = 0; i < sizeof(KeyWord) / sizeof(KeyWord[0]); i++) {
        p = str;

        for (j = 0; j < strlen(str); j++)
            buf[j] = (char)toupper(p[j]);

        buf[j] = '\0';

        if (!strcmp(KeyWord[i], buf)) {
            break;
        }
    }

    if (i < sizeof(KeyWord) / sizeof(KeyWord[0]))
        return i + 400;

    return ID;
}
/*
 * 输出符号表
*/
void OutputVarList(void)
{
    int i = 0;

    printf(" No.\tscope\t name \t\t   type\t\tisFunction\tisArray\n");

    if (i >= VarCount) {
        printf("Symbol Table is NULL!\n");
        return;
    }

    for (i = 1; i < VarCount; i++) {
        printf("%4d\t", i);
        printf("%s\t", VarList[i].scope);
        printf("%6s\t\t", VarList[i].name);
        switch (VarList[i].type) {
            case 0:
                printf(" INTEGER");
                break;
            case 1:
                printf(" INT*   ");
                break;
            case 2:
                printf(" VOID   ");
        }
        printf("\t%s", VarList[i].isfunc?"True": "    ");
        printf("\t\t%s", VarList[i].arrayType?"True": "    ");
        printf("\n");
    }

}


/*
 * 以name(变量名)查符号表中
 * 查到则返回相应登记项的序号
 * 否则返回0
*/
int lookup(char *name)
{
    int i;
    for (i = 1; i < VarCount;i++){
        if(!strcmp(name,VarList[i].name)){
            return i;
        }
    }
    return 0;
}

/*
 * 参考课本页码195,pdf207
 * 以name为名字在符号表中登记新的一项,返回值为该项的序号
*/
int enter(char *name)
{
    strcpy(VarList[VarCount].name, name);
    VarList[VarCount].type = 0;
    return VarCount++;
}

/*
 * 参考课本页码195,pdf207
 * 以name为名字查 填符号表
*/
int entry(char *name)
{
    int i = lookup(name);
    if(i){
        return i;
    }
    else
    {
        return enter(name);
    }
}

/*
 * pdf210
 * 产生临时变量的函数,每次调用都产生一个新的临时变量,返回值为该变量的编号
 * 为直观起见,我们把所产生的临时变量记为T1,T2,......
*/
int NewTemp()
{
    char temp[5];
    sprintf(temp,"T%d",tempVarCount);
    strcpy(VarList[TABLE_MAX_VAR_NUM - tempVarCount].name, temp);
    VarList[TABLE_MAX_VAR_NUM - tempVarCount].type = 0;
    return TABLE_MAX_VAR_NUM - (tempVarCount++);
}

/*
 * pdf233
 * 计算并填写符号表第NO登记项ADDR域所指的内情向量中的C值
 * C（CONSTPART）
 */
void FillArrMSG_C(int NO)
{
    int n = VarList[NO].ADDR->DIM;
    int C = 0, j, k, mul;
    for (j = 1; j < n; ++j) {
        mul = 1;
        for (k = j + 1; k < n + 1; ++k) {
            mul *= VarList[NO].ADDR->Vector[3*k + 1];
        }
        C += VarList[NO].ADDR->Vector[3 * j - 1] * mul;
    }
    VarList[NO].ADDR->Vector[0] = C;
}

/*
* 从符号表第no项的ADDR域所指内情向量中取C值
*/
int Access_C(int no)
{
    return VarList[no].ADDR->Vector[0];
}

/*
 * 取内情向量中的a值
*/
int Access_a(int no)
{
    // int length = sizeof(VarList[no].ADDR->Vector)/sizeof(int);
    // return VarList[no].ADDR->Vector[length-1];
    return VarList[no].ADDR->Vector[1];
}

/*
 * 取数组第k维的界差
*/
int Access_d(int no, int k)
{
    return VarList[no].ADDR->Vector[3 * k + 1];
}

void registerVariable(int type, char *id, int isArray) {
    int var_no = enter(id);
    VarList[var_no].type = type;
    VarList[var_no].arrayType = isArray;

}

void registerVariables(int type, List list){
    for (List iter = list; iter; iter = iter->next){
        varInfo var = iter->value;
        registerVariable(type, var->id, var->isArray);
    }
}
void registerFunc(int type, char* id){
    int no = enter(id);
    VarList[no].isfunc = 1;
    VarList[no].type = type;
}

int prePos = 0;
void setScope(char* scope){
    for(;prePos < VarCount; prePos++){
        VarList[prePos].scope = scope;
    }
}
