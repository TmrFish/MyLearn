#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MaxInt 32767
#define MVNum 100
#define MAX_CH_SIZE 10
#define MAX_SIZE 20
#define INF 100000
typedef char VerTexType;
typedef int ArcType;
typedef struct
{
    VerTexType vexs[MVNum][6];
    ArcType arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;
typedef struct{
    /**记录已经的放入路径顶点**/
    int S[MAX_SIZE];

    /**记录出发点到各个顶点的距离**/
    int Dist[MAX_SIZE];

    /***记录出发点到各个顶点所经过的路径***/
    int Path[MAX_SIZE];
}DijkStra;
/*邻接矩阵结构体*/
char Out[14][6] = {"广州","广州","广州","深圳","深圳","深圳","北京","北京","北京","上海","上海","上海","上海","拉萨"};
char In[14][6] = {"北京","深圳","上海","北京","上海","拉萨","广州","上海","深圳","广州","北京","深圳","拉萨","上海"};
int Win[] = {1000,200,800,700,600,1000,1000,500,700,700,500,700,1200,1100};


/* Begain Function CreateUDN ****************
 *输入    : AMGraph &G     -邻接矩阵
          :char Out[14][6]  -出发地
          :char In[14][6]    -目的地
          :int Win[]         -费用
 * *********************************************/

short CreateUDN(AMGraph *Gotree,char Out[14][6], char In[14][6],int Win[])
{
    char Only[5][6] = {"广州","深圳","北京","上海","拉萨"};
    int i,j,k,x,y;
    Gotree->vexnum = 5;
    Gotree->arcnum = 14;
    /*设定顶点数和总边数*/
    /*建立顶点表*/
    for(i=0;i<5;i++)
    {
        for(j=0;j<6;j++)
        {
            Gotree->vexs[i][j]= Only[i][j];
        }
    }

    /*设定顶点信息*/
    for(i=0;i<Gotree->vexnum;i++)
    {
        for(j=0;j<Gotree->vexnum;j++)
        {
            Gotree->arcs[i][j] = MaxInt;
        }
    }
    /*初始化邻接矩阵*/
    for (k=0;k<Gotree->arcnum;k++)/*遍历14条边*/
    {

        for (i=0;i<Gotree->vexnum;i++)
        {
            if(!strcmp(Gotree->vexs[i],Out[k]))
            {
                x = i;
            }

        }
        for (i=0;i<Gotree->vexnum;i++)
        {
            if(!strcmp(Gotree->vexs[i],In[k]))
            {
                y = i;
            }

        }
        Gotree->arcs[x][y] = Win[k];





    }
    return 1;

}


/* Begain Function Djkstra ****************
 *输入    : AMGraph G           -邻接矩阵
          :DijkStra  Dijk      -DJK结构体
 * *********************************************/

short Djkstra(AMGraph *Gotree, DijkStra *Dijk)
{
    /**出发点的地名**/
    char* Start_Place;
    /**目的地的地名**/
    char* Destination;
    /**出发点地名对应顶点表的下标**/
    unsigned int Start_Vex;
    /**目的地地名对应顶点表的下标**/
    unsigned int Desti_Vex;
    /**Dist数组里最小花费边的下标**/
    unsigned int Min_Index = -1;
    /**用于临时存储数值的数组**/
    int Tmp_Path[MAX_SIZE];
    /**用于临时存储数值的变量**/
    int Tmp_Num = 0;
    /**计数器**/
    unsigned int Counter,Counter_A;

    Start_Place = malloc(sizeof(char)*MAX_CH_SIZE);
    Destination = malloc(sizeof(char)*MAX_CH_SIZE);

    printf("现有以下几个地点可以出发:\n");

    /**顶点表展示**/
    for(Counter = 0;Counter < Gotree->vexnum;Counter++)
    {
        printf("%d:%s  ",Counter + 1,Gotree->vexs[Counter]);
    }

    /*** 出发点和目的地的地点输入 ***/
    printf("\n请输入出发点的地名(输入中文,请勿输入序号)：");
    scanf("%s",Start_Place);
    printf("\n请输入目的地的地名(输入中文,请勿输入序号)：");
    scanf("%s",Destination);

    /**通过比对，得到出发点地名对应顶点表的下标**/
    for(Counter = 0;Counter < Gotree->vexnum;Counter++)
    {
        if(!strcmp(Gotree->vexs[Counter],Start_Place))
        {
           Start_Vex = Counter;
           break;
        }
        /**遍历完后，如果输入的出发点不在顶点表里，则重新输入**/
        if(Gotree->vexnum == (Counter + 1))
        {
            printf("现有的路程里没有该地点，请重启程序重新输入！");
            return 0;
        }
    }

    /**通过比对，得到目的地地名对应顶点表的下标**/
    for(Counter = 0;Counter < Gotree->vexnum;Counter++)
    {
        if(!strcmp(Gotree->vexs[Counter],Destination))
        {
           Desti_Vex = Counter;
           break;
        }
        /**遍历完后，如果输入的目的地不在顶点表里，则重新输入**/
        if(Gotree->vexnum == (Counter + 1))
        {
            printf("现有的路程里没有该地点，请重启程序重新输入！");
            return 0;
        }
    }

    /**比对出发点是否和目的地一致**/
    if(!strcmp(Start_Place,Destination))
    {
        printf("请勿原地打转！您原地打转的费用为0！\n\n");
    }

    /**通过输入的出发点，对DijkStra所需的几个数组进行初始化**/
    Dijk->S[Start_Vex] = 1;
    for(Counter = 0;Counter < Gotree->vexnum;Counter++)
    {
        /**将出发点初始到各个顶点的费用赋值给Dist数组**/
        Dijk->Dist[Counter] = Gotree->arcs[Start_Vex][Counter];
        /**如果出发点能直达其他顶点**/
        if(Dijk->Dist[Counter] != INF)
        {
            /**将出发点的下标赋给各个顶点**/
            Dijk->Path[Counter] = Start_Vex;
        }
        else
        {
            /**如果出发点无法直达其他顶点，就赋值Path数组值指向虚空**/
            Dijk->Path[Counter] = -1;
        }
    }

    /**查找Dist数组中最小花费的顶点下标**/
    for(Counter = 1;Counter < Gotree->vexnum;Counter++)
    {
        /**定义极大值，查找下标**/
        unsigned int Cost = INF;
        for(Counter = 0;Counter < Gotree->vexnum; Counter++)
        {
        /**在还未加入路径的顶点里，寻找最小的花费**/
            if( (!Dijk->S[Counter]) && (Dijk->Dist[Counter] < Cost))
            {
                Cost = Dijk->Dist[Counter];
                Min_Index = Counter;
            }
        }

        /**最小花费的顶点加入到数组当中**/
        Dijk->S[Min_Index] = 1;
        for(Counter_A = 0;Counter_A < Gotree->vexnum;Counter_A++)
        {
            /**如果新加入顶点后存在新路径的花费小于原来路径的花费，那么计入Dist数组中，同时更新路径**/
            if((Dijk->S[Counter_A] == 0)&& (Gotree->arcs[Min_Index][Counter_A] + Dijk->Dist[Min_Index]) < Dijk->Dist[Counter_A])
            {
                /**更新Dist数组**/
                Dijk->Dist[Counter_A] = Dijk->Dist[Min_Index] + Gotree->arcs[Min_Index][Counter_A];
                /**更新Path数组为最小花费的顶点下标**/
                Dijk->Path[Counter_A] = Min_Index;
            }
        }
    }

    /*** 展示开销和路径 ***/
    printf("\n此次出游路程最省的开销为：%d\n",Dijk->Dist[Desti_Vex]);

    /**初始化临时的路径数组为目的地下标**/
    Tmp_Path[0] = Desti_Vex;
    /**存储出发点到目的地途径的顶点（此时为逆序存储）**/
    for(Counter = 0;Counter < Gotree->vexnum;Counter++)
    {
        /**从目的地开始向前存储顶点，直到回到出发点**/
        Tmp_Path[Counter+1] = Dijk->Path[Tmp_Path[Counter]];
        /**记录路径的长度**/
        Tmp_Num = Counter;
        /**存储到出发点时，退出循环**/
        if(Tmp_Path[Counter] == Start_Vex)
        {
            break;
        }
    }
    printf("\n您此次路程的路径为：");
    /**倒序输出到达目的地前的路径**/
    for(Counter = Tmp_Num;Counter > 0;Counter--)
    {
        printf("%s -> ",Gotree->vexs[Tmp_Path[Counter]]);
    }
    /**补上目的地，最终输出完整路径**/
    printf("%s\n",Gotree->vexs[Desti_Vex]);
    return 1;
}




int main()
{

    AMGraph Gotree ;
    DijkStra Dijk;
    memset(&Gotree,0,sizeof(AMGraph));
    memset(&Dijk,0,sizeof(DijkStra));
    CreateUDN(&Gotree,Out,In,Win);
    Djkstra(&Gotree, &Dijk);
}
