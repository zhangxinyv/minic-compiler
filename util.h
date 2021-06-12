//
// Created by loyx on 2021/6/12.
//

#ifndef MINIC_UTIL_H
#define MINIC_UTIL_H
char* String(char *str);

typedef struct varInfo_* varInfo;
struct varInfo_{
    char *id;
    int isArray;
    int arrayLen;
    int arraySize;
};

varInfo VarInfo(char* id);

// 通用链表实现，不安全
typedef struct List_* List;
struct List_ {varInfo value; List next;};
List appendList(List list, varInfo value);

#endif //MINIC_UTIL_H
