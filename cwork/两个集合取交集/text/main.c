#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EMPTY_LIST -3
typedef struct PNode
{
    int Xin; /* ���� */
    struct PNode* Next;/* ָ����һ���ڵ��ָ�� */
}PNode, *Poly_LinkedList;

/* Begin Function: CreatePolynomial ********
 * �������� : ����������ļ���
*******************************************/
PNode* CreatePolynomial(int N_Nodes)
{
    int I_Cnt; /* ������ */
    /* �ֱ���ͷָ�롢�½ڵ��ָ�롢����ָ�롢
     * ָ��Ҫ����λ�õ�ǰ��ָ�� */
    PNode *Head, *New_Node, *Iterator, *Pre;
    Head = NULL; /* ͷָ���ʼ��Ϊ�� */
    if (!N_Nodes)
    {
        Head = malloc(sizeof(PNode));
        Head->Xin = 0;
        Head->Next = NULL;
        return Head;
    }
    /* ��Ҫ�û��������뼯������ */
    for(I_Cnt = 0; I_Cnt < N_Nodes; I_Cnt++)
    {
        New_Node = malloc(sizeof(PNode));
       /* �����½ڵ� */
       /* �½ڵ����һ���ڵ��ʼ��Ϊ�� */
       New_Node->Next = NULL;
       printf("������ü��ϵ�%d�������\n", I_Cnt + 1);
       scanf("%d",&New_Node->Xin);

       /* ���ͷָ��û�г�ʼ�����ȳ�ʼ�� */
       if(!Head)
       {
           Head = malloc(sizeof(PNode));
           Head->Xin = 0;
           Head->Next = NULL;
       }


       /* ����һ��ǰ��ָ��ͱ���ָ�� */
       Pre = Head;
       Iterator = Head->Next;

       /* һֱ������ֱ���ҵ���������
        * ���½ڵ�ָ�������ȵĵ� */
        while(Iterator && (Iterator->Xin< New_Node->Xin))
        {
            Pre = Iterator; /* �ҵ������λ�� */
            Iterator = Iterator->Next;
        }

       /*  �����½ڵ� */
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
 * �������� : ��ӡ��������
*******************************************/
void PrintPolynomial(PNode *Head)
{
    PNode *Iterator; /* ����ָ�� */
    if((!Head) || !(Head->Next))
    {
        printf("����Ϊ�գ����ȴ�������\n");
        exit(EMPTY_LIST);
    }
    else
    {
        /* ���������е�ÿһ���ڵ� */
        Iterator = Head->Next;
        while(Iterator)
        {
            /* ���Iterator����һ��ǿ�
             * ��ô����Ҫ��ӡ���� */
            if(Iterator->Next)
            {
                printf("%d,", Iterator->Xin);
            }
            /* ���Iterator����һ��Ϊ�գ����� */
            else
            {
                printf("%d\n",Iterator->Xin);
            }
            Iterator = Iterator->Next;
        }
    }
}

/* Begin Function: MergeList ********
 * �������� : ��A��B���Ͻ��н�������
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
        /*��ͬ��ȡ����A*/
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
            /*����ͬʱ���ĸ�Сɾ����һ��*/
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
    /*�������ɾ��*/
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
    printf("��A��B���Ͻ���ΪC��C����Ϊ��");
    PrintPolynomial(P3);
    return 0;
}
