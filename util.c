//
// Created by loyx on 2021/6/12.
//

#include "util.h"

#include <stdlib.h>
#include <string.h>

char* String(char *str){
    unsigned len = strlen(str)+10;
    char* p = (char*)malloc(len * sizeof(char));
    strcpy(p, str);
    return p;
}
varInfo VarInfo(char* id){
    varInfo var_info = (varInfo) malloc(sizeof(struct varInfo_));
    var_info->id = id;
    var_info->isArray = 0;
    return var_info;
}

List appendList(List list, varInfo value){
    if(list == NULL){
        list = (List)malloc(sizeof(struct List_));
        list->value = value;
        list->next = NULL;
        return list;
    }
    List iter;
    for(iter = list; iter->next; iter = iter->next);
    List node = (List) malloc(sizeof(struct List_));
    node->value = value;
    node->next = NULL;
    iter->next = node;
    return list;
}
