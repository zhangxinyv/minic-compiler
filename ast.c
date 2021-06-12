#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <gvc.h>
#include "ast.h"

/*
 * 请在本文件中编写有关抽象语法树创建、添加节点、图形输出语法树的接口函数
 */

/* 整个AST的根节点。该节点不允许有兄弟节点，即root.next==NULL */
struct node ast_root;
/***************************************
  init_node函数负责对nd节点进行初始化
****************************************/
int init_node(struct node *nd)
{
    nd->type = e_null_node;
    nd->val.str = NULL;
    nd->son = NULL;
    nd->parent = NULL;
    nd->next = NULL;
//    nd->gnode = NULL;

    return RET_SUCCESS;
}

// AST抽象语法树初始化
void init_ast()
{
    init_node(&ast_root);
}

//插入孩子节点
int add_son_node(struct node *parent, struct node *son)
{
    if (parent != NULL && son != NULL)
    {
        if (parent->son == NULL)
        {
            // 父母的孩子节点是空的时候,就把孩子节点直接连上
            parent->son = son;
            son->parent = parent;
        }
        else
        {
            // 父母的孩子节点非空,就把孩子节点挂在兄弟节点上
            struct node *tmpnode = parent->son;
            while (tmpnode->next != NULL)
            {
                tmpnode = tmpnode->next;
            }
            tmpnode->next = son;
            son->parent = parent;
        }
        return RET_SUCCESS;
    }
    else
    {
        return RET_ERROR;
    }
    return RET_SUCCESS;
}

//插入兄弟节点
int add_brother_node(struct node *last, struct node *new_brother)
{
    if(last!=NULL && new_brother!=NULL)
    {
        last->next = new_brother;
        new_brother->parent = last->parent;
        return RET_SUCCESS;
    }
    else
    {
        return RET_ERROR;
    }

    return RET_SUCCESS;
}

/*
 * 获取孩子节点中的最后一个节点
*/
struct node* get_last_node(struct node *nd)
{
    struct node *tmpnode = nd;
    if(nd==NULL){
        return NULL;
    }
    while (tmpnode->next!=NULL)
    {
        /* code */
        tmpnode = tmpnode->next;
    }
    return tmpnode;
}
//给节点赋值,也就是给nd->val.str赋值
int set_node_val_str(struct node *nd, char *str)
{
    if(nd==NULL || str==NULL){
        return RET_ERROR;
    }
    else{
        if(NULL!=nd->val.str){
            free(nd->val.str);
        }
        nd->val.str = (char *)malloc(strlen(str) + 1);
        strcpy(nd->val.str, str);
        return RET_SUCCESS;
    }
}

//获取儿子节点
int get_son_node(struct node *parent, struct node **result)
{
    if(parent!=NULL && result!=NULL){
        *result = parent->son;
        return RET_SUCCESS;
    }
    return RET_ERROR;
}

//获取下一个兄弟节点
int get_next_brother_node(struct node *cur_nd, struct node **result)
{
    if(cur_nd!=NULL && result !=NULL){
        *result = cur_nd->next;
        return RET_SUCCESS;
    }
    return RET_ERROR;
}

//创建一个初始化后的新节点
int new_node(struct node **result)
{
    if (result != NULL)
    {
        *result = (struct node *)malloc(sizeof(struct node));
        if (init_node(*result) == RET_SUCCESS)
        {
            return RET_SUCCESS;
        }
    }
    return RET_ERROR;
}

struct ast
{
    enum node_type type;
    struct node_val val;
    struct node *son;
    struct node *parent;
    struct node *next;
//    Agnode_t *gnode;
};

/*
 * 整型数字转字符串
 * 第一个参数是字符串
 * 第二个参数是整数值
*/
void Int2Str(char* str, int intnum)
{
    int i, Div = 1000000000, j = 0, Status = 0;
    //32位无符号数最大是10位整数,所以Div=10 0000 0000
    for (i = 0; i < 10; i++)
    {
        str[j++] = (intnum / Div) + '0';//取最高位 转化成字符 

        intnum = intnum % Div;//去掉最高位
        Div /= 10;//还剩下10-i位要转换
        if ((str[j-1] == '0') && (Status == 0))//忽略最高位的'0'
        {
            j = 0;
        }
        else
        {
            Status++;
        }
    }
}
// 给节点标号用的
int graph_number = 0;
// 将标号转为字符串类型
char graph_name[10]={0};
/*
 * 先序遍历
 * 给Agnode赋值
 * 给父亲节点赋值
*/

//void PreOrder(struct node *nd, Agraph_t **g)
//{
//    // struct node *son;
//    // son = nd->son;
//    graph_number++;
//    Int2Str(graph_name,graph_number);
//    if (nd != NULL)
//    {
//        nd->gnode = agnode(*g, graph_name,1);
//        agsafeset(nd->gnode, "label", nd->val.str, graph_name);
//        // printf("%s\n", nd->val.str);
//        // while(son!=NULL){
//        //   PreOrder(son, g);
//        //   son = son->next;
//        // }
//        PreOrder(nd->son, g);
//        struct node *temp;
//        temp = nd->next;
//        while (temp!=NULL)
//        {
//            if(temp->parent==NULL){
//                temp->parent = nd->parent;
//            }
//            // temp->gnode = agnode(*g, (char*)temp, 0);
//            temp = temp->next;
//        }
//        PreOrder(nd->next, g);
//    }
//}
//
///*
// * 先序遍历
// * 画线
//*/
//void PreOrder_draw(struct node *nd,Agraph_t **g)
//{
//    // printf("%d %s\n",nd!=NULL,nd->val.str);
//    // struct node *son;
//    // son = nd->son;
//    if ((nd) != NULL)
//    {
//
//        agedge(*g, nd->parent->gnode, nd->gnode, "", 1);
//        // printf("%d", nd->parent != NULL);
//        // printf("%s\n", nd->val.str);
//        PreOrder_draw(nd->son, g);
//        PreOrder_draw(nd->next,g);
//    }
//}
//
//
///*
// * 输出抽象语法树
//*/
//void DrawTree()
//{
//    Agraph_t *g;
//    g = agopen("AST", Agstrictdirected, 0);
//    PreOrder(&ast_root, &g);
//    // printf("preorder ok\n");
//    PreOrder_draw(ast_root.son, &g);
//    GVC_t *gv;
//    gv = gvContext();
//    gvLayout(gv, g, "dot");
//    gvRenderFilename(gv, g, "png", " test.png");
//    gvFreeLayout(gv, g);
//    agclose(g);
//    gvFreeContext(gv);
//}