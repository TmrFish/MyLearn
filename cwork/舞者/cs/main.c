#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char ID;/*���*/
    char Sex;/*�Ա�*/
    char name;/*����*/
}dancer;
int main()
{

dancer female_danders[]= {{1,"M","����"},{2,"F","����"},{3,"M","����"},{4,"F","����"},{5,"M","����"}};
printf("%s",female_danders[1].Sex);
}
