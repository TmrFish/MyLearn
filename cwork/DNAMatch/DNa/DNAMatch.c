/* =============================================================
Name        : DNAMatch.c
Author      : YX
Version     : 1.0.0
Copyright   : None
Description : ����KMP�㷨ʵ��DNAƥ�䣬�жϼ�����Ƿ��Ⱦ����
================================================================*/

/******** Begin Includes *******/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/******** End Includes *******/

/******** Begin Defines ********/
#define MAX_LINES     20
#define MAX_DNA_LEN   30
/* �ڵ�ǰ�ļ�Ŀ¼�����Ը��ݾ�������޸� */
#define DNA_FILE_PATH "./DNA-data.txt"
/******** End Defines **********/

/* Begin Function : ParseDNAData ***************************************************************************
 * �������� : �����ļ���ȡ����DNA���кͼ����DNA����
 * ����     : char *File_Path - Ҫ��ȡ���ļ�������·������Ҫ�����ļ�������չ��
 * ���     : char (*Virus_DNA)[MAX_DNA_LEN] - ������DNA���У���ά���飬��һά���У��ڶ�ά�Ƕ�Ӧ��DNA�ַ���
            : char (*Human_DNA)[MAX_DNA_LEN] - �˵�DNA���У���ά���飬��һά���У��ڶ�ά�Ƕ�Ӧ��DNA�ַ���
 * ����     : ����0��ʾ��������ʧ�ܣ�����1��ʾ���гɹ�
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
        printf("���ļ�%sʧ�ܣ������ļ��Ƿ����!\n",File_Path);
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
 * �������� : KMP�㷨��������
 * ����     : char S[] - ����
 * ���     : char T[] - ģʽ�����Ӵ�
            : int Next[] - ǰ׺��
            : int pos - ��������posλ�ÿ�ʼ����ƥ��
 * ����     : ����ƥ����ַ����������ĵ�һλ��λ�ã�-1����û��ƥ��ɹ�
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
 * �������� : KMP�㷨��Get_Next�㷨
 * ����     : char T[] - ģʽ����ģʽ����Ϊ������ҲΪ�Ӵ�
 * ���     : int Next[] - ǰ׺��
 * ����     : ��
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
 * �������� : ���ݲ���DNA���к��˵�DNA�����ж��Ƿ��и�Ⱦ
 * ����     : char (*Virus_DNA)[MAX_DNA_LEN] - ������DNA���У���ά���飬��һά���У��ڶ�ά�Ƕ�Ӧ��DNA�ַ���
            : char (*Human_DNA)[MAX_DNA_LEN] - �˵�DNA���У���ά���飬��һά���У��ڶ�ά�Ƕ�Ӧ��DNA�ַ���
 * ���     : ��
 * ����     : ��
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
            printf("����DNA��%s,�����DNA��%s,��Ⱦ���������\n",Virus_DNA_Orig,Human_DNA[Line_Index]);
        }
        else
        {
            printf("����DNA��%s,�����DNA��%s,��Ⱦ���������\n",Virus_DNA_Orig,Human_DNA[Line_Index]);
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

    /* ������ȫ����ʼ��Ϊ0 */
    memset(Virus_DNA, 0, MAX_DNA_LEN * MAX_LINES * sizeof(char));
    memset(Human_DNA, 0, MAX_DNA_LEN * MAX_LINES * sizeof(char));

    if(ParseDNAData(DNA_FILE_PATH, Virus_DNA, Human_DNA))
    {
        CheckInfection(Virus_DNA, Human_DNA);
    }
    return 0;
}
