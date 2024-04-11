#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define TEXT_SAVE_PATH "./people.txt"
#define MAX_CH_SIZE 20
#define MAX_SIZE 10
#define OK 1
#define ERROR 0
/*��������������洢��ʾ*/
typedef struct
{
    char Name_Key;
    char Name;
    char Age;
    char Occupation;
    char Friends;
    struct BSTree *lchild,*rchild;
}BSTree;

/*** �����ĵ����õ��ĵ�������� ***/
short Parse_Text(char *Text_File_Path,char (*Name)[MAX_CH_SIZE],char (*Name_Key)[MAX_CH_SIZE],char (*Age)[MAX_CH_SIZE],char (*Occupation)[MAX_CH_SIZE],char (*Friends)[MAX_CH_SIZE])
{
    FILE *fp;
    /**��ȡ�ַ�**/
    char Read_Ch;
    /**�ж��Ƿ�Ϊ�ո��**/
    short Hit_Space = 0;
    /**�ж��Ƿ�Ϊ�ļ��ĵ�һ��**/
    unsigned int Row = 0;

    /**�±�����**/
    unsigned int Current_Line = 0;
    unsigned int Name_Index = 0;
    unsigned int Name_Key_Index = 0;
    unsigned int Age_Index = 0;
    unsigned int Occupation_Index = 0;
    unsigned int Friends_Index = 0;

    /**���ļ�**/
    if( (fp = fopen(Text_File_Path,"rt")) == NULL)
    {
        printf("%s�ļ������ڣ�\n",Text_File_Path);
        return 0;
    }

    /**��ȡ�ļ�**/
    while( (Read_Ch =fgetc(fp)) != EOF)
    {
        /**������һ��**/
        if(Row == 0)
        {
            if(Read_Ch == '\n')
            {
                /**����һ��ĩβ�Ļ��з�ʱ��������һ**/
                Row++;
            }
        }
        else
        {
            /**��û�����ո񣬶�ȡ����**/
            if(!Hit_Space && Read_Ch != ' ' && Read_Ch != '\n')
            {
                Name[Current_Line][Name_Index] = Read_Ch;
                Name_Index++;
            }
            /**����һ�οո񣬶�ȡ��������ĸƴ��**/
            if(Hit_Space == 1 && Read_Ch != ' ' && Read_Ch != '\n')
            {
                Name_Key[Current_Line][Name_Key_Index] = Read_Ch;
                Name_Key_Index++;
            }

            /**�������οո񣬶�ȡ����**/
            if(Hit_Space == 2 && Read_Ch != ' ' && Read_Ch != '\n')
            {
                Age[Current_Line][Age_Index] = Read_Ch;
                Age_Index++;
            }

            /**�������οո񣬶�ȡְҵ**/
            if(Hit_Space == 3 && Read_Ch != ' ' && Read_Ch != '\n')
            {
                Occupation[Current_Line][Occupation_Index] = Read_Ch;
                Occupation_Index++;
            }
            /**�����Ĵοո񣬶�ȡ�����б�**/
            if(Hit_Space == 4 && Read_Ch != ' ' && Read_Ch != '\n')
            {
                Friends[Current_Line][Friends_Index] = Read_Ch;
                Friends_Index++;
            }

            /***��������ո����ÿո�λ***/
            if(Read_Ch == ' ')
            {
                Hit_Space++;

            }

            /***����������У��Ƶ���һ�У������ò���***/
            if(Read_Ch == '\n')
            {
                Current_Line++;
                Hit_Space = 0;
                Name_Index = 0;
                Name_Key_Index = 0;
                Age_Index = 0;
                Occupation_Index = 0;
                Friends_Index = 0;

            }
        }
    }
    fclose(fp);
    return OK;
}

/*** ��������������***/
void CreatBST(BSTree *Tree,char (*Name)[MAX_CH_SIZE],char (*Name_Key)[MAX_CH_SIZE],char (*Age)[MAX_CH_SIZE],char (*Occupation)[MAX_CH_SIZE],char (*Friends)[MAX_CH_SIZE])
{

    int i_cut;
    char* Key = malloc(sizeof(char*));
    Key = NULL;
    for(i_cut=0;i_cut<MAX_SIZE;i_cut++)
    {
        Key = Name_Key[i_cut];
        printf("%s",Key);
        InsertBST(Tree,Key,i_cut,*Name,*Name_Key,*Age,*Occupation,*Friends);
    }
}

/*** ��������������ڵ� ***/

void InsertBST(BSTree *Tree,char *Key,int i_cut,char (*Name)[MAX_CH_SIZE],char (*Name_Key)[MAX_CH_SIZE],char (*Age)[MAX_CH_SIZE],char (*Occupation)[MAX_CH_SIZE],char (*Friends)[MAX_CH_SIZE])
{
    if(!Tree)
    {
        int j_cut;
        BSTree New_node;
        New_node->child=Tree->rchild=NULL;
        New_node.Name = Name[i_cut];
        New_node.Name_Key = Name_Key[i_cut];
        New_node.Age = Age[i_cut];
        New_node.Occupation = Occupation[i_cut];
        New_node.Friends = Friends[i_cut];
        Tree = &New_node;
        /*��bug�½ڵ��޷�������*/
        return OK;
    }
    else if(Key < Tree->Name_Key)
    {
        InsertBST(Tree->lchild,Key,i_cut,Name,Name_Key,Age,Occupation,Friends);
    }
    else if(Key > Tree->Name_Key)
        InsertBST(Tree->rchild,Key,i_cut,Name,Name_Key,Age,Occupation,Friends);
}

/*** �������������� ***/
BSTree* SearchBST(BSTree *Tree,char* Key)
{
    if((!Tree)||Key==Tree->Name_Key)
    {
        return Tree;
    }
    else if(Key < Tree->Name_Key)
    {
        return SearchBST(&Tree->lchild,Key);
    }
    else if(Key > Tree->Name_Key)
    {
        return SearchBST(&Tree->rchild,Key);
    }
}
int main()
{
    /**** �������� ****/
    int Counter,SearchWho_Cout;
    /**����**/
    char Name[MAX_SIZE][MAX_CH_SIZE];
    /*��������ĸƴ��*/
    char Name_Key[MAX_SIZE][MAX_CH_SIZE];
    /**����**/
    char Age[MAX_SIZE][MAX_CH_SIZE];
    /**ְҵ**/
    char Occupation[MAX_SIZE][MAX_CH_SIZE];
    /**�����б�**/
    char Friends[MAX_SIZE][MAX_CH_SIZE];
    char* SearchWho;
    SearchWho = malloc(sizeof(char)*MAX_CH_SIZE);
    char* WhoKey = (char*)malloc(sizeof(char));
    BSTree Tree,*P1;
    /**** ��ʼ������ ****/
    memset(Name,0,MAX_SIZE * MAX_CH_SIZE * sizeof(char));
    memset(Name_Key,0,MAX_SIZE * MAX_CH_SIZE * sizeof(char));
    memset(Age,0,MAX_SIZE * MAX_CH_SIZE * sizeof(char));
    memset(Occupation,0,MAX_SIZE * MAX_CH_SIZE * sizeof(char));
    memset(Friends,0,MAX_SIZE * MAX_CH_SIZE * sizeof(char));
    memset(&Tree,0,sizeof(BSTree));
    Parse_Text(TEXT_SAVE_PATH,Name,Name_Key,Age,Occupation,Friends);
    CreatBST(&Tree,Name,Name_Key,Age,Occupation,Friends);
    printf("��Ҫ���罻������˭?\n");
    scanf("%s",SearchWho);
    for(Counter = 0;Counter < MAX_SIZE;Counter++)
    {
        if(!strcmp(Name[Counter],SearchWho))
        {
           SearchWho_Cout = Counter;
           break;
        }
    }
    WhoKey = Name_Key[SearchWho_Cout];
    P1 = SearchBST(&Tree,WhoKey);
    printf("%s",P1->Occupation);
    return 0;
}
