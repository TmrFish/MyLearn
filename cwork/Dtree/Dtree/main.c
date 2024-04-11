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
    /**��¼�Ѿ��ķ���·������**/
    int S[MAX_SIZE];

    /**��¼�����㵽��������ľ���**/
    int Dist[MAX_SIZE];

    /***��¼�����㵽����������������·��***/
    int Path[MAX_SIZE];
}DijkStra;
/*�ڽӾ���ṹ��*/
char Out[14][6] = {"����","����","����","����","����","����","����","����","����","�Ϻ�","�Ϻ�","�Ϻ�","�Ϻ�","����"};
char In[14][6] = {"����","����","�Ϻ�","����","�Ϻ�","����","����","�Ϻ�","����","����","����","����","����","�Ϻ�"};
int Win[] = {1000,200,800,700,600,1000,1000,500,700,700,500,700,1200,1100};


/* Begain Function CreateUDN ****************
 *����    : AMGraph &G     -�ڽӾ���
          :char Out[14][6]  -������
          :char In[14][6]    -Ŀ�ĵ�
          :int Win[]         -����
 * *********************************************/

short CreateUDN(AMGraph *Gotree,char Out[14][6], char In[14][6],int Win[])
{
    char Only[5][6] = {"����","����","����","�Ϻ�","����"};
    int i,j,k,x,y;
    Gotree->vexnum = 5;
    Gotree->arcnum = 14;
    /*�趨���������ܱ���*/
    /*���������*/
    for(i=0;i<5;i++)
    {
        for(j=0;j<6;j++)
        {
            Gotree->vexs[i][j]= Only[i][j];
        }
    }

    /*�趨������Ϣ*/
    for(i=0;i<Gotree->vexnum;i++)
    {
        for(j=0;j<Gotree->vexnum;j++)
        {
            Gotree->arcs[i][j] = MaxInt;
        }
    }
    /*��ʼ���ڽӾ���*/
    for (k=0;k<Gotree->arcnum;k++)/*����14����*/
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
 *����    : AMGraph G           -�ڽӾ���
          :DijkStra  Dijk      -DJK�ṹ��
 * *********************************************/

short Djkstra(AMGraph *Gotree, DijkStra *Dijk)
{
    /**������ĵ���**/
    char* Start_Place;
    /**Ŀ�ĵصĵ���**/
    char* Destination;
    /**�����������Ӧ�������±�**/
    unsigned int Start_Vex;
    /**Ŀ�ĵص�����Ӧ�������±�**/
    unsigned int Desti_Vex;
    /**Dist��������С���ѱߵ��±�**/
    unsigned int Min_Index = -1;
    /**������ʱ�洢��ֵ������**/
    int Tmp_Path[MAX_SIZE];
    /**������ʱ�洢��ֵ�ı���**/
    int Tmp_Num = 0;
    /**������**/
    unsigned int Counter,Counter_A;

    Start_Place = malloc(sizeof(char)*MAX_CH_SIZE);
    Destination = malloc(sizeof(char)*MAX_CH_SIZE);

    printf("�������¼����ص���Գ���:\n");

    /**�����չʾ**/
    for(Counter = 0;Counter < Gotree->vexnum;Counter++)
    {
        printf("%d:%s  ",Counter + 1,Gotree->vexs[Counter]);
    }

    /*** �������Ŀ�ĵصĵص����� ***/
    printf("\n�����������ĵ���(��������,�����������)��");
    scanf("%s",Start_Place);
    printf("\n������Ŀ�ĵصĵ���(��������,�����������)��");
    scanf("%s",Destination);

    /**ͨ���ȶԣ��õ������������Ӧ�������±�**/
    for(Counter = 0;Counter < Gotree->vexnum;Counter++)
    {
        if(!strcmp(Gotree->vexs[Counter],Start_Place))
        {
           Start_Vex = Counter;
           break;
        }
        /**��������������ĳ����㲻�ڶ���������������**/
        if(Gotree->vexnum == (Counter + 1))
        {
            printf("���е�·����û�иõص㣬�����������������룡");
            return 0;
        }
    }

    /**ͨ���ȶԣ��õ�Ŀ�ĵص�����Ӧ�������±�**/
    for(Counter = 0;Counter < Gotree->vexnum;Counter++)
    {
        if(!strcmp(Gotree->vexs[Counter],Destination))
        {
           Desti_Vex = Counter;
           break;
        }
        /**���������������Ŀ�ĵز��ڶ���������������**/
        if(Gotree->vexnum == (Counter + 1))
        {
            printf("���е�·����û�иõص㣬�����������������룡");
            return 0;
        }
    }

    /**�ȶԳ������Ƿ��Ŀ�ĵ�һ��**/
    if(!strcmp(Start_Place,Destination))
    {
        printf("����ԭ�ش�ת����ԭ�ش�ת�ķ���Ϊ0��\n\n");
    }

    /**ͨ������ĳ����㣬��DijkStra����ļ���������г�ʼ��**/
    Dijk->S[Start_Vex] = 1;
    for(Counter = 0;Counter < Gotree->vexnum;Counter++)
    {
        /**���������ʼ����������ķ��ø�ֵ��Dist����**/
        Dijk->Dist[Counter] = Gotree->arcs[Start_Vex][Counter];
        /**�����������ֱ����������**/
        if(Dijk->Dist[Counter] != INF)
        {
            /**����������±긳����������**/
            Dijk->Path[Counter] = Start_Vex;
        }
        else
        {
            /**����������޷�ֱ���������㣬�͸�ֵPath����ֵָ�����**/
            Dijk->Path[Counter] = -1;
        }
    }

    /**����Dist��������С���ѵĶ����±�**/
    for(Counter = 1;Counter < Gotree->vexnum;Counter++)
    {
        /**���弫��ֵ�������±�**/
        unsigned int Cost = INF;
        for(Counter = 0;Counter < Gotree->vexnum; Counter++)
        {
        /**�ڻ�δ����·���Ķ����Ѱ����С�Ļ���**/
            if( (!Dijk->S[Counter]) && (Dijk->Dist[Counter] < Cost))
            {
                Cost = Dijk->Dist[Counter];
                Min_Index = Counter;
            }
        }

        /**��С���ѵĶ�����뵽���鵱��**/
        Dijk->S[Min_Index] = 1;
        for(Counter_A = 0;Counter_A < Gotree->vexnum;Counter_A++)
        {
            /**����¼��붥��������·���Ļ���С��ԭ��·���Ļ��ѣ���ô����Dist�����У�ͬʱ����·��**/
            if((Dijk->S[Counter_A] == 0)&& (Gotree->arcs[Min_Index][Counter_A] + Dijk->Dist[Min_Index]) < Dijk->Dist[Counter_A])
            {
                /**����Dist����**/
                Dijk->Dist[Counter_A] = Dijk->Dist[Min_Index] + Gotree->arcs[Min_Index][Counter_A];
                /**����Path����Ϊ��С���ѵĶ����±�**/
                Dijk->Path[Counter_A] = Min_Index;
            }
        }
    }

    /*** չʾ������·�� ***/
    printf("\n�˴γ���·����ʡ�Ŀ���Ϊ��%d\n",Dijk->Dist[Desti_Vex]);

    /**��ʼ����ʱ��·������ΪĿ�ĵ��±�**/
    Tmp_Path[0] = Desti_Vex;
    /**�洢�����㵽Ŀ�ĵ�;���Ķ��㣨��ʱΪ����洢��**/
    for(Counter = 0;Counter < Gotree->vexnum;Counter++)
    {
        /**��Ŀ�ĵؿ�ʼ��ǰ�洢���㣬ֱ���ص�������**/
        Tmp_Path[Counter+1] = Dijk->Path[Tmp_Path[Counter]];
        /**��¼·���ĳ���**/
        Tmp_Num = Counter;
        /**�洢��������ʱ���˳�ѭ��**/
        if(Tmp_Path[Counter] == Start_Vex)
        {
            break;
        }
    }
    printf("\n���˴�·�̵�·��Ϊ��");
    /**�����������Ŀ�ĵ�ǰ��·��**/
    for(Counter = Tmp_Num;Counter > 0;Counter--)
    {
        printf("%s -> ",Gotree->vexs[Tmp_Path[Counter]]);
    }
    /**����Ŀ�ĵأ������������·��**/
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
