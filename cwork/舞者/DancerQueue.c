/* ==============================
Name        : DancerQueue.c
Author      : YX
Version     : 1.0.0
Copyright   : None
Description : �ö���ʵ���������
================================== */

/******* Begin Includes *******/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/******* End Includes ********/

/******* Begin Defines *******/
#define MAX_NAME_LEN        30 /* ������󳤶� */
#define NUM_MALE_DANCERS    5  /* �����ߵ����� */
#define NUM_FEMALE_DANCERS  3  /* Ů���ߵ����� */

/* �������߽ṹ�� */
typedef struct Dancer
{
    char ID;                 /* ���ߵ�ID */
    char Sex;                /* �Ա�, M����F */
    char Name[MAX_NAME_LEN]; /* ���� */
    struct Dancer *Next;     /* ָ����һ���ڵ�ָ�� */
}Dancer;

/* ������ʽ���� */
typedef struct LinkedQueue
{
    Dancer *Front;  /* ͷ�ڵ��ָ�� */
    Dancer *Rear;   /* β�ڵ��ָ�� */
}DancerQueue;

/******* End Defines *******/

/* Begin Function: InitQueue *********
 * �������� : ��ʼ������
 * ����     : ��
 * ���     : ��
 * ����     : DancerQueue* ���س�ʼ����ɵ����߶���
 ************************************/
DancerQueue* InitQueue()
{

}
/* End Function: InitQueue *********/

/* Begin Function: isQueueEmpty *********
 * �������� : ��Ӻ���
 * ����     : DancerQueue *Q - ����ָ��
 * ����     : char - 1��ʾ����Ϊ�գ�0��ʾ���зǿ�
 ***********************************/
char isQueueEmpty(DancerQueue *Q)
{

}
/* End Function: isQueueEmpty *********/

/* Begin Function: EnQueue *********
 * �������� : ��Ӻ���
 * ����     : DancerQueue *Q - ����ָ��
            : char Name[] - ���������
            : char ID - ������˵�ID
            : char Sex - �Ա�
 * ���     : DancerQueue *Q - ����ָ��
 * ����     : 1��ʾ����ɹ���0��ʾ����ʧ��
 ***********************************/
 char EnQueue(DancerQueue *Q, char Name[], char ID, char Sex)
 {

 }

/* End Function: EnQueue *********/

/* Begin Function: DeQueue *********
 * �������� : ���Ӻ���
 * ����     : DancerQueue *Q - ����ָ��
 * ���     : Dancer *P - ���ӵĽڵ�
 * ����     : 1��ʾ���ӳɹ���0��ʾʧ��
 ***********************************/
char DeQueue(DancerQueue *Q, Dancer *P)
{

}
/* End Function: DeQueue *********/

/* Begin Function: GetFront *********
 * �������� : �õ���ͷ�ڵ㺯��
 * ����     : DancerQueue *Q - ����ָ��
 * ���     : Dancer *P - ��ͷ�Ľڵ�
 * ����     : 1��ʾ�õ���ͷ�ڵ�ɹ���0��ʾʧ��
 ***********************************/
char GetFront(DancerQueue *Q, Dancer *P)
{

}
/* End Function: GetFront *********/

int main()
{


    return 0;
}
