#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char ID;/*ĞòºÅ*/
    char Sex;/*ĞÔ±ğ*/
    char name;/*Ãû×Ö*/
}dancer;
int main()
{

dancer female_danders[]= {{1,"M","°¢³ó"},{2,"F","°¢ÃÃ"},{3,"M","°¢µÜ"},{4,"F","°¢ÃÀ"},{5,"M","°¢ÏÄ"}};
printf("%s",female_danders[1].Sex);
}
