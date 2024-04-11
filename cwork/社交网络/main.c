#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define TEXT_SAVE_PATH "./people.txt"
#define MAX_CH_SIZE 20
#define MAX_SIZE 10
#define OK 1
#define ERROR 0
/*二叉排序树链表存储表示*/
typedef struct
{
    char Name_Key;
    char Name;
    char Age;
    char Occupation;
    char Friends;
    struct BSTree *lchild,*rchild;
}BSTree;

/*** 解析文档，得到文档里的数据 ***/
short Parse_Text(char *Text_File_Path,char (*Name)[MAX_CH_SIZE],char (*Name_Key)[MAX_CH_SIZE],char (*Age)[MAX_CH_SIZE],char (*Occupation)[MAX_CH_SIZE],char (*Friends)[MAX_CH_SIZE])
{
    FILE *fp;
    /**读取字符**/
    char Read_Ch;
    /**判断是否为空格键**/
    short Hit_Space = 0;
    /**判断是否为文件的第一行**/
    unsigned int Row = 0;

    /**下标索引**/
    unsigned int Current_Line = 0;
    unsigned int Name_Index = 0;
    unsigned int Name_Key_Index = 0;
    unsigned int Age_Index = 0;
    unsigned int Occupation_Index = 0;
    unsigned int Friends_Index = 0;

    /**打开文件**/
    if( (fp = fopen(Text_File_Path,"rt")) == NULL)
    {
        printf("%s文件不存在！\n",Text_File_Path);
        return 0;
    }

    /**读取文件**/
    while( (Read_Ch =fgetc(fp)) != EOF)
    {
        /**跳过第一行**/
        if(Row == 0)
        {
            if(Read_Ch == '\n')
            {
                /**到第一行末尾的换行符时，行数加一**/
                Row++;
            }
        }
        else
        {
            /**还没遇到空格，读取姓名**/
            if(!Hit_Space && Read_Ch != ' ' && Read_Ch != '\n')
            {
                Name[Current_Line][Name_Index] = Read_Ch;
                Name_Index++;
            }
            /**遇到一次空格，读取姓名首字母拼音**/
            if(Hit_Space == 1 && Read_Ch != ' ' && Read_Ch != '\n')
            {
                Name_Key[Current_Line][Name_Key_Index] = Read_Ch;
                Name_Key_Index++;
            }

            /**遇到二次空格，读取年龄**/
            if(Hit_Space == 2 && Read_Ch != ' ' && Read_Ch != '\n')
            {
                Age[Current_Line][Age_Index] = Read_Ch;
                Age_Index++;
            }

            /**遇到三次空格，读取职业**/
            if(Hit_Space == 3 && Read_Ch != ' ' && Read_Ch != '\n')
            {
                Occupation[Current_Line][Occupation_Index] = Read_Ch;
                Occupation_Index++;
            }
            /**遇到四次空格，读取好友列表**/
            if(Hit_Space == 4 && Read_Ch != ' ' && Read_Ch != '\n')
            {
                Friends[Current_Line][Friends_Index] = Read_Ch;
                Friends_Index++;
            }

            /***如果遇到空格，设置空格位***/
            if(Read_Ch == ' ')
            {
                Hit_Space++;

            }

            /***如果遇到换行，移到下一行，并重置参数***/
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

/*** 创建二叉排序树***/
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

/*** 二叉排序树插入节点 ***/

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
        /*有bug新节点无法连接树*/
        return OK;
    }
    else if(Key < Tree->Name_Key)
    {
        InsertBST(Tree->lchild,Key,i_cut,Name,Name_Key,Age,Occupation,Friends);
    }
    else if(Key > Tree->Name_Key)
        InsertBST(Tree->rchild,Key,i_cut,Name,Name_Key,Age,Occupation,Friends);
}

/*** 二叉排序树查找 ***/
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
    /**** 声明变量 ****/
    int Counter,SearchWho_Cout;
    /**姓名**/
    char Name[MAX_SIZE][MAX_CH_SIZE];
    /*姓名首字母拼音*/
    char Name_Key[MAX_SIZE][MAX_CH_SIZE];
    /**年龄**/
    char Age[MAX_SIZE][MAX_CH_SIZE];
    /**职业**/
    char Occupation[MAX_SIZE][MAX_CH_SIZE];
    /**好友列表**/
    char Friends[MAX_SIZE][MAX_CH_SIZE];
    char* SearchWho;
    SearchWho = malloc(sizeof(char)*MAX_CH_SIZE);
    char* WhoKey = (char*)malloc(sizeof(char));
    BSTree Tree,*P1;
    /**** 初始化变量 ****/
    memset(Name,0,MAX_SIZE * MAX_CH_SIZE * sizeof(char));
    memset(Name_Key,0,MAX_SIZE * MAX_CH_SIZE * sizeof(char));
    memset(Age,0,MAX_SIZE * MAX_CH_SIZE * sizeof(char));
    memset(Occupation,0,MAX_SIZE * MAX_CH_SIZE * sizeof(char));
    memset(Friends,0,MAX_SIZE * MAX_CH_SIZE * sizeof(char));
    memset(&Tree,0,sizeof(BSTree));
    Parse_Text(TEXT_SAVE_PATH,Name,Name_Key,Age,Occupation,Friends);
    CreatBST(&Tree,Name,Name_Key,Age,Occupation,Friends);
    printf("你要在社交网里找谁?\n");
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
