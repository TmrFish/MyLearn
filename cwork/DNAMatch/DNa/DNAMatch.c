/* =============================================================
Name        : DNAMatch.c
Author      : YX
Version     : 1.0.0
Copyright   : None
Description : 利用KMP算法实现DNA匹配，判断检测者是否感染病毒
================================================================*/

/******** Begin Includes *******/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/******** End Includes *******/

/******** Begin Defines ********/
#define MAX_LINES     20
#define MAX_DNA_LEN   30
/* 在当前文件目录，可以跟据具体情况修改 */
#define DNA_FILE_PATH "./DNA-data.txt"
/******** End Defines **********/

/* Begin Function : ParseDNAData ***************************************************************************
 * 函数描述 : 根据文件读取病毒DNA序列和检测者DNA序列
 * 输入     : char *File_Path - 要读取的文件的完整路径，需要包括文件名和扩展名
 * 输出     : char (*Virus_DNA)[MAX_DNA_LEN] - 病毒的DNA序列，二维数组，第一维是行，第二维是对应的DNA字符串
            : char (*Human_DNA)[MAX_DNA_LEN] - 人的DNA序列，二维数组，第一维是行，第二维是对应的DNA字符串
 * 返回     : 返回0表示函数运行失败，返回1表示运行成功
************************************************************************************************************/
short ParseDNAData(char *File_Path, char (*Virus_DNA)[MAX_DNA_LEN], char (*Human_DNA)[MAX_DNA_LEN])
{
    FILE *fp;
    char Read_Ch;
    char Hit_Space = 0 ;
    unsigned int Human_DNA_Index = 0;
    unsigned int Virus_DNA_Index = 0;
    unsigned int Current_Line = 0;
    if((fp = fopen(File_Path,"rt"))==NULL)
    {
        printf("打开文件%s失败，请检查文件是否存在!\n",File_Path);
        return 0;
    }
    else
    {
        while((Read_Ch = fgetc(fp))!=EOF)
        {
            if(Read_Ch!=' '&&!Hit_Space && Read_Ch != '\n')
            {
                Virus_DNA[Current_Line][Virus_DNA_Index] = Read_Ch;
                Virus_DNA_Index++;
            }
            if(Read_Ch != ' '&&Hit_Space && Read_Ch !='\n')
            {
                Human_DNA[Current_Line][Human_DNA_Index] = Read_Ch;
                Human_DNA_Index++;
            }
            if (Read_Ch == ' ' && !Hit_Space)
            {
                Hit_Space = 1;

            }
            if (Read_Ch == '\n')
            {
                Current_Line++;
                Virus_DNA_Index = 0;
                Human_DNA_Index = 0;
                Hit_Space = 0;
            }
        }

    }
    fclose(fp);
    return 1;
}
/* End Function : ParseDNAData ***************************************************************************/

/* Begin Function : KMP ***************************************************************************
 * 函数描述 : KMP算法的主函数
 * 输入     : char S[] - 主串
 * 输出     : char T[] - 模式串，子串
            : int Next[] - 前缀表
            : int pos - 从主串的pos位置开始进行匹配
 * 返回     : 返回匹配的字符串在主串的第一位的位置，-1代表没有匹配成功
***************************************************************************************************/
int KMP(char S[], char T[], int Next[], int pos)
{
    int i = pos;
    int j = 0;
    while(i<(int)strlen(S)&&j<(int)strlen(T))
    {
        if(j==0||S[i]==T[j])
        {
            i++;
            j++;
        }
        else j = Next[j];
    }
    if(j>=(int)strlen(T))
    {
        return i-(int)strlen(T);
    }
    return -1;
}
/* End Function : KMP ***************************************************************************/

/* Begin Function : Get_Next *****************************************
 * 函数描述 : KMP算法中Get_Next算法
 * 输入     : char T[] - 模式串，模式串既为主串，也为子串
 * 输出     : int Next[] - 前缀表
 * 返回     : 无
**********************************************************************/
void Get_Next(char T[], int Next[])
{
    int i = 0,j = -1;
    Next[0] = -1;
    while(i<(int)strlen(T))
    {
        if(j<0||T[i]==T[j])
        {
            i++;
            j++;
            Next[i]=j;
        }
        else j = Next[j];
    }

}
/* End Function : Get_Next ********************************************/

/* Begin Function : CheckInfection **************************************************************************
 * 函数描述 : 根据病毒DNA序列和人的DNA序列判断是否有感染
 * 输入     : char (*Virus_DNA)[MAX_DNA_LEN] - 病毒的DNA序列，二维数组，第一维是行，第二维是对应的DNA字符串
            : char (*Human_DNA)[MAX_DNA_LEN] - 人的DNA序列，二维数组，第一维是行，第二维是对应的DNA字符串
 * 输出     : 无
 * 返回     : 无
*************************************************************************************************************/
void CheckInfection(char (*Virus_DNA)[MAX_DNA_LEN], char (*Human_DNA)[MAX_DNA_LEN])
{
    unsigned int Line_Index = 0;
    unsigned int Virus_DNA_Len;
    unsigned int I_Cnt,J_Cut;
    char Virus_DNA_Orig[MAX_DNA_LEN];
    char Tmp_Str[MAX_DNA_LEN] = {0};
    short IsMatched = 0;
    int Next[MAX_DNA_LEN];
    memset(Next,-1,MAX_DNA_LEN * sizeof(int));

    while(Virus_DNA[Line_Index][0])
    {
        I_Cnt = strlen(Virus_DNA[Line_Index]);
        Virus_DNA_Len = I_Cnt;
        strcpy(Virus_DNA_Orig,Virus_DNA[Line_Index]);

        for(;I_Cnt < 2 * Virus_DNA_Len;I_Cnt++)
        {

            Virus_DNA[Line_Index][I_Cnt] = Virus_DNA[Line_Index][I_Cnt - Virus_DNA_Len];
        }
        for(I_Cnt = 0;I_Cnt < Virus_DNA_Len;I_Cnt++)
        {
            for (J_Cut = 0;J_Cut<Virus_DNA_Len;J_Cut++)
            {
                Tmp_Str[J_Cut] = Virus_DNA[Line_Index][I_Cnt + J_Cut];
            }
            Get_Next(Tmp_Str,Next);
            if(KMP(Human_DNA[Line_Index],Tmp_Str,Next,0) >= 0)
            {
                IsMatched = 1;
                break;
            }
        }

        if (IsMatched)
        {
            printf("病毒DNA：%s,检查者DNA：%s,感染结果：阳性\n",Virus_DNA_Orig,Human_DNA[Line_Index]);
        }
        else
        {
            printf("病毒DNA：%s,检查者DNA：%s,感染结果：阴性\n",Virus_DNA_Orig,Human_DNA[Line_Index]);
        }
        memset(Tmp_Str,0,sizeof(char)*MAX_DNA_LEN);
        Line_Index++;
        IsMatched = 0;

    }


}
/* End Function : CheckInfection ****************************************************************************/

int main()
{
    char Virus_DNA[MAX_LINES][MAX_DNA_LEN];
    char Human_DNA[MAX_LINES][MAX_DNA_LEN];

    /* 将数组全部初始化为0 */
    memset(Virus_DNA, 0, MAX_DNA_LEN * MAX_LINES * sizeof(char));
    memset(Human_DNA, 0, MAX_DNA_LEN * MAX_LINES * sizeof(char));

    if(ParseDNAData(DNA_FILE_PATH, Virus_DNA, Human_DNA))
    {
        CheckInfection(Virus_DNA, Human_DNA);
    }
    return 0;
}
