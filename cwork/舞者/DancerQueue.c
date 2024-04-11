/* ==============================
Name        : DancerQueue.c
Author      : YX
Version     : 1.0.0
Copyright   : None
Description : 用队列实现舞伴问题
================================== */

/******* Begin Includes *******/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/******* End Includes ********/

/******* Begin Defines *******/
#define MAX_NAME_LEN        30 /* 姓名最大长度 */
#define NUM_MALE_DANCERS    5  /* 男舞者的数量 */
#define NUM_FEMALE_DANCERS  3  /* 女舞者的数量 */

/* 定义舞者结构体 */
typedef struct Dancer
{
    char ID;                 /* 舞者的ID */
    char Sex;                /* 性别, M或者F */
    char Name[MAX_NAME_LEN]; /* 姓名 */
    struct Dancer *Next;     /* 指向下一个节点指针 */
}Dancer;

/* 定义链式队列 */
typedef struct LinkedQueue
{
    Dancer *Front;  /* 头节点的指针 */
    Dancer *Rear;   /* 尾节点的指针 */
}DancerQueue;

/******* End Defines *******/

/* Begin Function: InitQueue *********
 * 函数描述 : 初始化链队
 * 输入     : 无
 * 输出     : 无
 * 返回     : DancerQueue* 返回初始化完成的舞者队列
 ************************************/
DancerQueue* InitQueue()
{

}
/* End Function: InitQueue *********/

/* Begin Function: isQueueEmpty *********
 * 函数描述 : 入队函数
 * 输入     : DancerQueue *Q - 链队指针
 * 返回     : char - 1表示队列为空，0表示队列非空
 ***********************************/
char isQueueEmpty(DancerQueue *Q)
{

}
/* End Function: isQueueEmpty *********/

/* Begin Function: EnQueue *********
 * 函数描述 : 入队函数
 * 输入     : DancerQueue *Q - 链队指针
            : char Name[] - 插入的人名
            : char ID - 插入的人的ID
            : char Sex - 性别
 * 输出     : DancerQueue *Q - 链队指针
 * 返回     : 1表示插入成功，0表示插入失败
 ***********************************/
 char EnQueue(DancerQueue *Q, char Name[], char ID, char Sex)
 {

 }

/* End Function: EnQueue *********/

/* Begin Function: DeQueue *********
 * 函数描述 : 出队函数
 * 输入     : DancerQueue *Q - 链队指针
 * 输出     : Dancer *P - 出队的节点
 * 返回     : 1表示出队成功，0表示失败
 ***********************************/
char DeQueue(DancerQueue *Q, Dancer *P)
{

}
/* End Function: DeQueue *********/

/* Begin Function: GetFront *********
 * 函数描述 : 得到队头节点函数
 * 输入     : DancerQueue *Q - 链队指针
 * 输出     : Dancer *P - 对头的节点
 * 返回     : 1表示得到队头节点成功，0表示失败
 ***********************************/
char GetFront(DancerQueue *Q, Dancer *P)
{

}
/* End Function: GetFront *********/

int main()
{


    return 0;
}
