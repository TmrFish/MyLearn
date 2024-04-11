/* ===============================
Name         : PolyAdd.c
Author       : ̷����
Version      : 1.0
Copyright    : None
Description  : �õ�������ʵ�ֶ���ʽ�ӷ�
==================================*/

/******** Begin Includes ***** */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/******** End Includes ********/

/******** Begin Defines ******/

/* �������ʽ����Ľṹ���������ʽһ��ľ���ṹ */
typedef struct PNode
{
    float Coef; /* ϵ�� */
    int Expn; /* ָ�� */

    /* ָ����һ���ڵ��ָ�� */
    struct PNode* Next;
}PNode, *Poly_LinkedList;

#define EMPTY_LIST -3

/******** End Defines ******/

/* Begin Function: CreatePolynomial ********
 * �������� : ����������Ķ���ʽ
 * ����     : int N_Nodes - �ڵ������
 * ���     : ��
 * ����     : PNode *Head - ���ض���ʽ�����ͷָ��
*******************************************/
PNode* CreatePolynomial(int N_Nodes)
{
    int I_Cnt; /* ������ */
    /* �ֱ���ͷָ�롢�½ڵ��ָ�롢����ָ�롢
     * ָ��Ҫ����λ�õ�ǰ��ָ�� */
    PNode *Head, *New_Node, *Iterator, *Pre;
    Head = NULL; /* ͷָ���ʼ��Ϊ�� */

    /* ��Ҫ�û��������룬����ÿһ���
     * ָ����ϵ���ֱ����� */
    for(I_Cnt = 0; I_Cnt < N_Nodes; I_Cnt++)
    {
       /* TODO: �����½ڵ� */
       New_Node = malloc(sizeof(PNode));


       /* ������Ѿ�û���ڴ��ˣ�
        * ���Եõ��˿�ָ�� */
       if(!New_Node)
       {
           printf("�����û���ڴ���Է��䣡");
           exit(OVERFLOW);
       }

       /* �½ڵ����һ���ڵ��ʼ��Ϊ�� */
       New_Node->Next = NULL;
       printf("��ֱ�����ö���ʽ��%d���ϵ����ָ��\n", I_Cnt + 1);
       scanf("%f,%d",&New_Node->Coef, &New_Node->Expn);

       /* TODO: ���ͷָ��û�г�ʼ�����ȳ�ʼ�� */
       if(!Head)
       {
           Head = malloc(sizeof(PNode));
           Head->Coef = 0.0;
           Head->Expn = 0;
           Head->Next = NULL;
       }


       /* ����һ��ǰ��ָ��ͱ���ָ�� */
       Pre = Head;
       Iterator = Head->Next;

       /* TODO: һֱ������ֱ���ҵ�������ָ��
        * ���½ڵ�ָ�������ȵĵ� */
        while(Iterator && (Iterator->Expn< New_Node->Expn))
        {
            Pre = Iterator; /* �ҵ������λ�� */
            Iterator = Iterator->Next;
        }

       /* TODO: �����½ڵ� */
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
 * �������� : �Ѷ���ʽ��ӡ����
 * ����     : PNode *Head - ����ʽ��ͷָ��
 * ���     : ��
 * ����     : ��
*******************************************/
void PrintPolynomial(PNode *Head)
{
    PNode *Iterator; /* ����ָ�� */
    if((!Head) || !(Head->Next))
    {
        printf("����ʽΪ�գ����ȴ�������ʽ\n");
        exit(EMPTY_LIST);
    }
    else
    {
        /* ���������е�ÿһ���ڵ� */
        Iterator = Head->Next;
        while(Iterator)
        {
            /* ���Iterator����һ��ǿ�
             * ��ô����Ҫ��ӡ�Ӻ� */
            if(Iterator->Next)
            {
                printf("%fx^%d+", Iterator->Coef, Iterator->Expn);
            }
            /* ���Iterator����һ��Ϊ�գ���Ҫ��Ӻţ����� */
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
 * �������� : ����������ʽ���
 * ����     : PNode *P1 - ��һ������ʽ��ͷָ��
 * ����     : PNode *P2 - �ڶ�������ʽ��ͷָ��
 * ���     : PNode *P1 - �ѽ���浽��һ������ʽ����
 * ����     : ��
*******************************************/
void PolynomialAdd(PNode *P1, PNode *P2)
{
    /* �ֱ��ǵ�һ������ʽ�ı���ָ�룬�ڶ�������ʽ�ı���ָ��
     * �µĶ���ʽ����ָ�룬��ʱ��������ɾ���ڵ� */
    PNode *Iterator_P1, *Iterator_P2, *Iterator_P3, *Tmp;
    /* ���������ָ����һ������ϵ�������� */
    float Coef_Sum = 0.0;
    /* ��ʼ�����ֱ��Iterator_P1��Iterator_P2ָ��
     * P1��P2����Ԫ�ڵ� */
    Iterator_P1 = P1->Next;
    Iterator_P2 = P2->Next;
    Iterator_P3 = P1;

    /* TODO: ��ʼ���� */
    while(Iterator_P1 && Iterator_P2)
    {
        /* TODO: �����������ʽ�������ָ������ȵ� */
        if(Iterator_P1->Expn == Iterator_P2->Expn)
        {
            /* �������ϵ����� */
            Coef_Sum = Iterator_P1->Coef + Iterator_P2->Coef;
            /* ����������ϵ��Ϊ0������Եı���ָ��������һ����
             * ����ɾ����ǰ�ڵ� */
            if(fabs(Coef_Sum) < 1e-9)
            {
                /* TODO: ɾ��P1��Ӧ�Ľڵ� */
                Tmp = Iterator_P1;
                Iterator_P1 = Iterator_P1->Next;
                free(Tmp);
                /* TODO: ɾ��P2��Ӧ�Ľڵ� */
                Tmp = Iterator_P2;
                Iterator_P2 = Iterator_P2->Next;
                free(Tmp);
            }
            /* ָͬ������£�ϵ���ĺͲ�Ϊ0
             * ϵ����ӣ��浽P1�У�P1��P2��Ҫ������һ��Ԫ�� */
            else
            {
                /* P1�Ĳ��� */
                Iterator_P1->Coef = Coef_Sum;
                Iterator_P3->Next = Iterator_P1;
                Iterator_P3 = Iterator_P1;
                Iterator_P1 = Iterator_P1->Next;

                /* TODO: P2�Ĳ��� */
                Tmp = Iterator_P2;
                Iterator_P2 = Iterator_P2->Next;
                free(Tmp);
            }
        }
        /* ��P1ָ������P2ָ�� */
        else if(Iterator_P1->Expn > Iterator_P2->Expn)
        {
            /* TODO: ��P2��ǰ�ڵ����ӽ���P3��Ȼ��P2ָ����һ���ڵ� */
            Iterator_P3->Next = Iterator_P2;
            Iterator_P3 = Iterator_P2;
            Iterator_P2 = Iterator_P2->Next;
        }
        /* ��P1��ָ��С��P2��ָ�� */
        else
        {
            /* TODO: ��P1��ǰ�ڵ����ӽ���P3��Ȼ��P1ָ����һ���ڵ� */
            Iterator_P3->Next = Iterator_P1;
            Iterator_P3 = Iterator_P1;
            Iterator_P1 = Iterator_P1->Next;
        }
    }
    /* TODO: ��ʣ�µĶ���ʽƴ�ӵ�P3 */
    Iterator_P3->Next = Iterator_P1?Iterator_P1:Iterator_P2;
}
/* End Function: PolynomialAdd ********/

int main()
{
    PNode *P1, *P2;
    P1 = CreatePolynomial(3);
    P2 = CreatePolynomial(4);
    printf("��������ʽ�ֱ�Ϊ��\n");
    PrintPolynomial(P1);
    PrintPolynomial(P2);
    PolynomialAdd(P1,P2);
    printf("��������ʽ��ӵĽ��Ϊ��\n");
    PrintPolynomial(P1);
    return 0;
}
