#include <stdio.h>
#include <stdlib.h>


/*----------����----------*/
   /*��������*/
typedef struct
{
    char ID;/*���*/
    char Sex;/*�Ա�*/
    char name[20];/*����*/
}person;
    /*��������*/
/*----------����----------*/


/*----------���еĴ洢�ṹ----------*/
#define MAXQSIZE 40
typedef struct SqQueue
{
    person *base;
    int front;
    int rear;
}SqQueue;

/*----------���еĴ洢�ṹ----------*/


/*-------------���г�ʼ��--------------*/
char InitQueue (SqQueue *Q)
{
    Q->base = (person*)malloc(sizeof(MAXQSIZE*sizeof(person)));
    Q->front = Q->rear = 0;
    return 1;
}

/*-------------���г�ʼ��--------------*/

/*----------���г���----------*/
int QueueLength (SqQueue Q)
{
    return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}
/*----------���г���----------*/


/*----------�����----------*/
char EnQueue (SqQueue *Q,person e)
{
    if((Q->rear+1)%MAXQSIZE==Q->front)
        return 0;
    Q->base[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXQSIZE;
    return 1;
}
/*----------�����----------*/



/*----------������----------*/
char DeQueue(SqQueue *Q,person *e)
{
    if (Q->front==Q->rear)
        return 0;
    *e = Q->base[Q->front];
    Q->front = (Q->front+1)%MAXQSIZE;
    return 1;
}
/*----------������----------*/

/*----------ȡѭ�����ж�ͷ----------*/
person GetHead(SqQueue Q)
{
    if (Q.front!=Q.rear)
        return Q.base[Q.front];
}

/*----------ȡѭ�����ж�ͷ----------*/


/*----------�ж϶����Ƿ�Ϊ��----------*/
char QueueEmpty(SqQueue Q)
{
    if(Q.front == Q.rear)
        return 1;
    else return 0;

}


/*----------�ж϶����Ƿ�Ϊ��----------*/

/*----------������Ů����----------*/
void DancerDistribute(person dancer[],int num)
{
    SqQueue Mdancers,Fdancers;
    person p;
    int i;
    InitQueue(&Mdancers);
    InitQueue(&Fdancers);
    for(i=0;i<num;i++)
    {
        p=dancer[i];//��dancer�ж�������
        if(p.Sex=='F') EnQueue(&Fdancers,p);//��Ů��
        else EnQueue(&Mdancers,p);//���ж�
    }
    while (!QueueEmpty(Fdancers)&&!QueueEmpty(Mdancers))
    {
        DeQueue(&Fdancers,&p);
        printf("%s",p.name);
        DeQueue(&Mdancers,&p);
        printf("%s\n",p.name);
    }
    if(!QueueEmpty(Fdancers))
    {
        p=GetHead(Fdancers);
        printf("��һ�ֻص�һ���Ҵ��Ůʿ��:%s\n",p.name);
    }
    if(!QueueEmpty(Mdancers))
    {
        p=GetHead(Mdancers);
        printf("��һ�ֻص�һ���Ҵ����ʿ��:%s\n",p.name);

    }
}
/*----------������Ů����----------*/


int main()
{
    person dancer[MAXQSIZE];
    dancer[0] =(person) {1,"M","����"};
    dancer[1] = (person){2,"F","����"};
    dancer[2] =(person) {3,"M","����"};
    dancer[3] = (person){4,"F","����"};
    dancer[4] = (person){5,"M","����"};
    DancerDistribute(dancer,5);

}
