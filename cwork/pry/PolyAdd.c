/* ===============================
Name         : PolyAdd.c
Author       : 谭铭瑞
Version      : 1.0
Copyright    : None
Description  : 用单向链表实现多项式加法
==================================*/

/******** Begin Includes ***** */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/******** End Includes ********/

/******** Begin Defines ******/

/* 定义多项式链表的结构，代表多项式一项的具体结构 */
typedef struct PNode
{
    float Coef; /* 系数 */
    int Expn; /* 指数 */

    /* 指向下一个节点的指针 */
    struct PNode* Next;
}PNode, *Poly_LinkedList;

#define EMPTY_LIST -3

/******** End Defines ******/

/* Begin Function: CreatePolynomial ********
 * 函数描述 : 创建单链表的多项式
 * 输入     : int N_Nodes - 节点的数量
 * 输出     : 无
 * 返回     : PNode *Head - 返回多项式链表的头指针
*******************************************/
PNode* CreatePolynomial(int N_Nodes)
{
    int I_Cnt; /* 计数器 */
    /* 分别是头指针、新节点的指针、遍历指针、
     * 指向要插入位置的前驱指针 */
    PNode *Head, *New_Node, *Iterator, *Pre;
    Head = NULL; /* 头指针初始化为空 */

    /* 需要用户进行输入，对于每一项的
     * 指数和系数分别输入 */
    for(I_Cnt = 0; I_Cnt < N_Nodes; I_Cnt++)
    {
       /* TODO: 创建新节点 */
       New_Node = malloc(sizeof(PNode));


       /* 计算机已经没有内存了，
        * 所以得到了空指针 */
       if(!New_Node)
       {
           printf("计算机没有内存可以分配！");
           exit(OVERFLOW);
       }

       /* 新节点的下一个节点初始化为空 */
       New_Node->Next = NULL;
       printf("请分别输入该多项式第%d项的系数及指数\n", I_Cnt + 1);
       scanf("%f,%d",&New_Node->Coef, &New_Node->Expn);

       /* TODO: 如果头指针没有初始化，先初始化 */
       if(!Head)
       {
           Head = malloc(sizeof(PNode));
           Head->Coef = 0.0;
           Head->Expn = 0;
           Head->Next = NULL;
       }


       /* 重置一下前驱指针和遍历指针 */
       Pre = Head;
       Iterator = Head->Next;

       /* TODO: 一直遍历，直到找到链表中指数
        * 比新节点指数大或相等的点 */
        while(Iterator && (Iterator->Expn< New_Node->Expn))
        {
            Pre = Iterator; /* 找到插入的位置 */
            Iterator = Iterator->Next;
        }

       /* TODO: 插入新节点 */
       New_Node->Next = Iterator;
       Pre->Next = New_Node;


       if(!(Head->Next) && New_Node)
       {
           Head->Next = New_Node;
       }
    }
    return Head;
}
/* End Function: CreatePolynomial ********/

/* Begin Function: PrintPolynomial ********
 * 函数描述 : 把多项式打印出来
 * 输入     : PNode *Head - 多项式的头指针
 * 输出     : 无
 * 返回     : 无
*******************************************/
void PrintPolynomial(PNode *Head)
{
    PNode *Iterator; /* 遍历指针 */
    if((!Head) || !(Head->Next))
    {
        printf("多项式为空，请先创建多项式\n");
        exit(EMPTY_LIST);
    }
    else
    {
        /* 遍历链表中的每一个节点 */
        Iterator = Head->Next;
        while(Iterator)
        {
            /* 如果Iterator的下一项非空
             * 那么我们要打印加号 */
            if(Iterator->Next)
            {
                printf("%fx^%d+", Iterator->Coef, Iterator->Expn);
            }
            /* 如果Iterator的下一项为空，不要打加号，换行 */
            else
            {
                printf("%fx^%d\n", Iterator->Coef, Iterator->Expn);
            }
            Iterator = Iterator->Next;
        }
    }
}
/* End Function: PrintPolynomial ********/

/* Begin Function: PolynomialAdd ********
 * 函数描述 : 把两个多项式相加
 * 输入     : PNode *P1 - 第一个多项式的头指针
 * 输入     : PNode *P2 - 第二个多项式的头指针
 * 输出     : PNode *P1 - 把结果存到第一个多项式链表
 * 返回     : 无
*******************************************/
void PolynomialAdd(PNode *P1, PNode *P2)
{
    /* 分别是第一个多项式的遍历指针，第二个多项式的遍历指针
     * 新的多项式链表指针，临时变量用于删除节点 */
    PNode *Iterator_P1, *Iterator_P2, *Iterator_P3, *Tmp;
    /* 假如两项的指数是一样，做系数和运算 */
    float Coef_Sum = 0.0;
    /* 初始化，分别把Iterator_P1和Iterator_P2指向
     * P1和P2的首元节点 */
    Iterator_P1 = P1->Next;
    Iterator_P2 = P2->Next;
    Iterator_P3 = P1;

    /* TODO: 开始遍历 */
    while(Iterator_P1 && Iterator_P2)
    {
        /* TODO: 如果两个多项式的两项的指数是相等的 */
        if(Iterator_P1->Expn == Iterator_P2->Expn)
        {
            /* 把两项的系数相加 */
            Coef_Sum = Iterator_P1->Coef + Iterator_P2->Coef;
            /* 如果两项相加系数为0，则各自的遍历指针往后移一个，
             * 并且删除当前节点 */
            if(fabs(Coef_Sum) < 1e-9)
            {
                /* TODO: 删除P1对应的节点 */
                Tmp = Iterator_P1;
                Iterator_P1 = Iterator_P1->Next;
                free(Tmp);
                /* TODO: 删除P2对应的节点 */
                Tmp = Iterator_P2;
                Iterator_P2 = Iterator_P2->Next;
                free(Tmp);
            }
            /* 同指数情况下，系数的和不为0
             * 系数相加，存到P1中，P1和P2都要往下移一个元素 */
            else
            {
                /* P1的操作 */
                Iterator_P1->Coef = Coef_Sum;
                Iterator_P3->Next = Iterator_P1;
                Iterator_P3 = Iterator_P1;
                Iterator_P1 = Iterator_P1->Next;

                /* TODO: P2的操作 */
                Tmp = Iterator_P2;
                Iterator_P2 = Iterator_P2->Next;
                free(Tmp);
            }
        }
        /* 当P1指数大于P2指数 */
        else if(Iterator_P1->Expn > Iterator_P2->Expn)
        {
            /* TODO: 把P2当前节点连接进入P3，然后P2指向下一个节点 */
            Iterator_P3->Next = Iterator_P2;
            Iterator_P3 = Iterator_P2;
            Iterator_P2 = Iterator_P2->Next;
        }
        /* 当P1的指数小于P2的指数 */
        else
        {
            /* TODO: 把P1当前节点连接进入P3，然后P1指向下一个节点 */
            Iterator_P3->Next = Iterator_P1;
            Iterator_P3 = Iterator_P1;
            Iterator_P1 = Iterator_P1->Next;
        }
    }
    /* TODO: 把剩下的多项式拼接到P3 */
    Iterator_P3->Next = Iterator_P1?Iterator_P1:Iterator_P2;
}
/* End Function: PolynomialAdd ********/

int main()
{
    PNode *P1, *P2;
    P1 = CreatePolynomial(3);
    P2 = CreatePolynomial(4);
    printf("两个多项式分别为：\n");
    PrintPolynomial(P1);
    PrintPolynomial(P2);
    PolynomialAdd(P1,P2);
    printf("两个多项式相加的结果为：\n");
    PrintPolynomial(P1);
    return 0;
}
