#ifndef __TABLE_H__
#define __TABLE_H__

#define TABLE_MAX_IDENT_NAME_LEN 50
#define TABLE_MAX_VAR_NUM 200

struct arr_info {
    int DIM;
    int *Vector; // 内情向量
};
typedef struct Node {
    char var_name[TABLE_MAX_IDENT_NAME_LEN];
    struct Node *next;
} Node,*var_ids;
typedef struct table_variable__ {
    char name[TABLE_MAX_IDENT_NAME_LEN]; // 变量名
    int type; // 类型
    int isture; //是否为指针
    int isfunc; //是否为函数
    int addr; // 地址
    struct arr_info *ADDR;
} table_variable;

extern table_variable VarList[TABLE_MAX_VAR_NUM];

void OutputVarList(void);

int id_or_keyword(char *);

int lookup(char *name);
int enter(char *name);
int entry(char *name);
int NewTemp();

void FillArrMSG_C(int NO);
int Access_C(int no);
int Access_a(int no);
int Access_d(int no, int k);

#endif
