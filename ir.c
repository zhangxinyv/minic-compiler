#include <stdio.h>
#include <string.h>
#include "ir.h"
#include "table.h"

/*
 * 请在本文件中编写有关四元式创建与维护、打印等相关的函数接口
 */
//用于指示下一个四元式序列
int NXQ = 0;  /* used to indicate the number of next Quater*/

ir_quarter_expression QuaterList[MAX_IR_EXP_NUM];

void OutputQuaterList(void)
{
    int i = 0;
    if(i>NXQ){
        printf("no quarter exists!");
    }
    for (i = 0;i<NXQ;i++) {

        printf("(%3d) ( %5s, ", i, QuaterList[i].op);
        if (QuaterList[i].arg1)
            printf("%6s, ", VarList[QuaterList[i].arg1].name);
        else
            printf("      , ");

        if (QuaterList[i].arg2)
            printf("%6s, ", VarList[QuaterList[i].arg2].name);
        else printf("      , ");

        if ((QuaterList[i].op[0] == 'j') || (QuaterList[i].op[0] == 'S'))
            printf("%6d )\n", QuaterList[i].result);
        else if (QuaterList[i].result)
            printf("%6s )\n", VarList[QuaterList[i].result].name);
        else printf("-\t )\n");
    }

    return;
}

/*
 * 根据所给的实参产生一个四元式:(op,arg1,arg2,result)且送入四元式表中
 * 每调用一次均执行NXQ++
 * arg为0表示缺省
*/
void gen(char *op,int arg1,int arg2,int result){
    strcpy(QuaterList[NXQ].op, op);
    QuaterList[NXQ].arg1 = arg1;
    QuaterList[NXQ].arg2 = arg2;
    QuaterList[NXQ].result = result;
    NXQ++;
}
/*
 * 回填函数,课本页码203页,pdf的话215页
 * 用四元式序号t回填以p为首的链
 * 用链中每个四元式的Result域改写为t的值
*/
void backpatch(int p,int t)
{
    int q = p, q1;
    while (q)
    {
        q1 = QuaterList[q].result;
        QuaterList[q].result = t;
        q = q1;
    }
}

/*
 * 将链首“指针”分别为p1和p2的两条链合并为一条
 * 并返回新联的链首“指针”
 * 此处的指针实际上是四元式的序号，为整数值
*/
int merge(int p1, int p2)
{
    int p;
    if (!p2) {
        // p2 = 0即第二条链为空
        return p1;
    } else {
        p = p2;
        while (QuaterList[p].result) {
            p = QuaterList[p].result;
        }
        QuaterList[p].result = p1;
        return p2;
    }
}