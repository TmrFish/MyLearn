#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EMPTY_LIST -3
typedef struct PNode
{
    int Xin; /* 数据 */
    struct PNode* Next;/* 指向下一个节点的指针 */
}PNode, *Poly_LinkedList;

/* Begin Function: CreatePolynomial ********
 * 函数描述 : 创建单链表的集合
*******************************************/
PNode* CreatePolynomial(int N_Nodes)
{
    int I_Cnt; /* 计数器 */
    /* 分别是头指针、新节点的指针、遍历指针、
     * 指向要插入位置的前驱指针 */
    PNode *Head, *New_Node, *Iterator, *Pre;
    Head = NULL; /* 头指针初始化为空 */
    if (!N_Nodes)
    {
        Head = malloc(sizeof(PNode));
        Head->Xin = 0;
        Head->Next = NULL;
        return Head;
    }
    /* 需要用户进行输入集合数据 */
    for(I_Cnt = 0; I_Cnt < N_Nodes; I_Cnt++)
    {
        New_Node = malloc(sizeof(PNode));
       /* 创建新节点 */
       /* 新节点的下一个节点初始化为空 */
       New_Node->Next = NULL;
       printf("请输入该集合第%d项的数字\n", I_Cnt + 1);
       scanf("%d",&New_Node->Xin);

       /* 如果头指针没有初始化，先初始化 */
       if(!Head)
       {
           Head = malloc(sizeof(PNode));
           Head->Xin = 0;
           Head->Next = NULL;
       }


       /* 重置一下前驱指针和遍历指针 */
       Pre = Head;
       Iterator = Head->Next;

       /* 一直遍历，直到找到链表中数
        * 比新节点指数大或相等的点 */
        while(Iterator && (Iterator->Xin< New_Node->Xin))
        {
            Pre = Iterator; /* 找到插入的位置 */
            Iterator = Iterator->Next;
        }

       /*  插入新节点 */
       New_Node->Next = Iterator;
       Pre->Next = New_Node;


       if(!(Head->Next) && New_Node)
       {
           Head->Next = New_Node;
       }

    }
return Head;

}

/* Begin Function: PrintPolynomial ********
 * 函数描述 : 打印集合数据
*******************************************/
void PrintPolynomial(PNode *Head)
{
    PNode *Iterator; /* 遍历指针 */
    if((!Head) || !(Head->Next))
    {
        printf("集合为空，请先创建集合\n");
        exit(EMPTY_LIST);
    }
    else
    {
        /* 遍历链表中的每一个节点 */
        Iterator = Head->Next;
        while(Iterator)
        {
            /* 如果Iterator的下一项非空
             * 那么我们要打印逗号 */
            if(Iterator->Next)
            {
                printf("%d,", Iterator->Xin);
            }
            /* 如果Iterator的下一项为空，换行 */
            else
            {
                printf("%d\n",Iterator->Xin);
            }
            Iterator = Iterator->Next;
        }
    }
}

/* Begin Function: MergeList ********
 * 函数描述 : 将A与B集合进行交集操作
*******************************************/
PNode* MergeList(PNode *P1,PNode *P2,PNode *P3)
{
    PNode *Pre1,*Pre2,*Pre3,*Dele;
    Pre1 = P1->Next;
    Pre2 = P2->Next;
    P3 = P1;
    Pre3 = P3;
    while (Pre1&&Pre2)
    {
        /*相同则取集合A*/
        if(Pre1->Xin==Pre2->Xin)
        {
            Pre3->Next=Pre1;
            Pre3=Pre1;
            Pre1 = Pre1->Next;
            Dele = Pre2;
            Pre2 = Pre2->Next;
            free(Dele);
        }
        else
        {
            /*不相同时，哪个小删除哪一个*/
            if(Pre1->Xin<Pre2->Xin)
            {
                Dele = Pre1;
                Pre1 = Pre1->Next;
                free(Dele);
            }
            else
            {
                Dele = Pre2;
                Pre2 = Pre2->Next;
                free(Dele);
            }
        }

    }
    /*将多余的删除*/
    while(Pre1)
    {
        Dele = Pre1;
        Pre1 = Pre1->Next;
        free(Dele);
    }
    while(Pre2)
    {
        Dele = Pre2;
        Pre2 = Pre2->Next;
        free(Dele);
    }
    Pre3->Next = NULL;
    return P3;
}


int main()
{
    PNode *P1, *P2, *P3;
    P1 = CreatePolynomial(4);
    P2 = CreatePolynomial(3);
    PrintPolynomial(P1);
    PrintPolynomial(P2);
    P3 = MergeList(P1,P2,P3);
    printf("将A与B集合交集为C，C集合为：");
    PrintPolynomial(P3);
    return 0;
}
