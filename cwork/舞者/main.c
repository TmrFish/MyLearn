#include <stdio.h>
#include <stdlib.h>


/*----------定义----------*/
   /*定义舞者*/
typedef struct
{
    char ID;/*序号*/
    char Sex;/*性别*/
    char name[20];/*名字*/
}person;
    /*定义舞者*/
/*----------定义----------*/


/*----------队列的存储结构----------*/
#define MAXQSIZE 40
typedef struct SqQueue
{
    person *base;
    int front;
    int rear;
}SqQueue;

/*----------队列的存储结构----------*/


/*-------------队列初始化--------------*/
char InitQueue (SqQueue *Q)
{
    Q->base = (person*)malloc(sizeof(MAXQSIZE*sizeof(person)));
    Q->front = Q->rear = 0;
    return 1;
}

/*-------------队列初始化--------------*/

/*----------队列长度----------*/
int QueueLength (SqQueue Q)
{
    return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}
/*----------队列长度----------*/


/*----------入队列----------*/
char EnQueue (SqQueue *Q,person e)
{
    if((Q->rear+1)%MAXQSIZE==Q->front)
        return 0;
    Q->base[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXQSIZE;
    return 1;
}
/*----------入队列----------*/



/*----------出队列----------*/
char DeQueue(SqQueue *Q,person *e)
{
    if (Q->front==Q->rear)
        return 0;
    *e = Q->base[Q->front];
    Q->front = (Q->front+1)%MAXQSIZE;
    return 1;
}
/*----------出队列----------*/

/*----------取循环队列队头----------*/
person GetHead(SqQueue Q)
{
    if (Q.front!=Q.rear)
        return Q.base[Q.front];
}

/*----------取循环队列队头----------*/


/*----------判断队列是否为空----------*/
char QueueEmpty(SqQueue Q)
{
    if(Q.front == Q.rear)
        return 1;
    else return 0;

}


/*----------判断队列是否为空----------*/

/*----------分配男女队列----------*/
void DancerDistribute(person dancer[],int num)
{
    SqQueue Mdancers,Fdancers;
    person p;
    int i;
    InitQueue(&Mdancers);
    InitQueue(&Fdancers);
    for(i=0;i<num;i++)
    {
        p=dancer[i];//从dancer中读出舞者
        if(p.Sex=='F') EnQueue(&Fdancers,p);//入女队
        else EnQueue(&Mdancers,p);//入男队
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
        printf("下一轮回第一个找搭档的女士是:%s\n",p.name);
    }
    if(!QueueEmpty(Mdancers))
    {
        p=GetHead(Mdancers);
        printf("下一轮回第一个找搭档的男士是:%s\n",p.name);

    }
}
/*----------分配男女队列----------*/


int main()
{
    person dancer[MAXQSIZE];
    dancer[0] =(person) {1,"M","阿丑"};
    dancer[1] = (person){2,"F","阿妹"};
    dancer[2] =(person) {3,"M","阿弟"};
    dancer[3] = (person){4,"F","阿美"};
    dancer[4] = (person){5,"M","阿夏"};
    DancerDistribute(dancer,5);

}
