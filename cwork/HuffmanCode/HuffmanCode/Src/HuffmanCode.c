/*=====================
Author      :̷����
Name        :HuffmanCode.c
����������������
=====================*/

/****** Begain Includes *******/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Include/HuffmanCode.h"
/****** End    Includes *******/

/* Begain Function ParseText ****************
 *����    : char *Text_File_Path  -�ĵ�·��
 *���    : HuffmanCode *Huffman_Codes -�ĵ���������
          :char *Text - ��ȡ�ĵ�����������
 * *********************************************/

short ParseText(char *Text_File_Path, HuffmanCode *Huffman_Codes, char *Text)
{
    FILE *fp;         /*�ļ�ָ��*/
    char Read_Ch;    /*��ȡ�ļ����ַ�*/
    char Char_Exist; /*�����ж�ĳ���ַ��Ƿ��Ѿ�����*/
    unsigned int I_Cnt,J_Cnt;

    if((fp = fopen(Text_File_Path, "rt")) == NULL)
    {
        printf("��%s�ļ�ʧ��!\n", Text_File_Path);
        return 0;
    }
    J_Cnt = 0;

    while((Read_Ch = fgetc(fp)) != EOF)
    {
        /*��λ*/
        Char_Exist = 0;
        I_Cnt = 0;

        while(Huffman_Codes[I_Cnt].Char_Info.value != 0)
        {
            /*���Char_Map ���ַ����ĵ����ַ�һ��,Times +1*/
            if (Huffman_Codes[I_Cnt].Char_Info.value == Read_Ch)
            {
                Huffman_Codes[I_Cnt].Char_Info.Times += 1;
                Char_Exist = 1;
                break;
            }
            I_Cnt++;
        }

        /*����ַ������ڣ����������ַ�*/
        if(!Char_Exist)
        {
            Huffman_Codes[I_Cnt].Char_Info.value = Read_Ch;
            Huffman_Codes[I_Cnt].Char_Info.Times = 1;

        }
        /*���ĵ����ݿ������ڴ�*/
        Text[J_Cnt] = Read_Ch;
        J_Cnt++;


    }
    fclose(fp);
    return 1;


}
/* End    Function ParseText ************/



/* Begain CreateHuffmanTree ****************
 *����    : HuffmanCode *Huffman_Codes -�������ɵĹ���������
          :char *Save_File_Path - ��ż���ܹ�����������·����������򲻱���
 *���    : HuffmanTree *Huffman_Tree - ���ɵĹ�������

 * *********************************************/
 short CreateHuffmanTree(HuffmanCode *Huffman_Codes,HuffmanTree *Huffman_Tree,char *Save_File_Path)
 {
     /*�ı���ͬ�ַ�������*/
     int Num_Chars;
     /*�����������нڵ�����*/
     int Num_Tree_Nodes;
     /*������*/
     unsigned int I_Cnt;
     /*��ǰ��С�������ڵ��±�*/
     unsigned int Min_Idx1 = 0,Min_Idx2 = 0;
     /*��ȡ��ͬ�ַ�������*/
     Num_Chars = GetHuffmanCodeslength(Huffman_Codes);
     Num_Tree_Nodes = 2 * Num_Chars - 1;

     /*����û���δ�����ĵ������Ƚ����ĵ�*/
     if(!Huffman_Codes || Huffman_Codes[0].Char_Info.value == 0)
     {
         printf("���Ƚ����ĵ�!\n");
         return 0;
     }

     /*��ʼ���ڵ���Ϣ*/
     for(I_Cnt = 0;I_Cnt < Num_Tree_Nodes;I_Cnt++)
     {
         Huffman_Tree[I_Cnt].Parent = 0;
         Huffman_Tree[I_Cnt].LChild = 0;
         Huffman_Tree[I_Cnt].RChild = 0;
     }

     /*��ʼ��Ȩ�ؽڵ�*/
     for(I_Cnt = 0;I_Cnt < Num_Chars;I_Cnt++)
     {
         Huffman_Tree[I_Cnt].Weight = Huffman_Codes[I_Cnt].Char_Info.Times;
     }

     /*ͨ��n-1��ѡ��ɾ�����ϲ���������������*/
     for(I_Cnt = Num_Chars;I_Cnt < Num_Tree_Nodes;I_Cnt++)
     {
         /*ѡ����ǰȨֵ��С�������ڵ��±�*/
         SelectHufftree(Huffman_Tree, I_Cnt - 1, &Min_Idx1, &Min_Idx2);
         /*��Min_Idx1��Min_Idx2��ɭ����ɾ��������ӵ�����������*/
         Huffman_Tree[Min_Idx1].Parent = I_Cnt;
         Huffman_Tree[Min_Idx2].Parent = I_Cnt;
         Huffman_Tree[I_Cnt].LChild = Min_Idx1;
         Huffman_Tree[I_Cnt].RChild = Min_Idx2;
         Huffman_Tree[I_Cnt].Weight = Huffman_Tree[Min_Idx1].Weight + Huffman_Tree[Min_Idx2].Weight;

     }
     /*����û��ƶ��˴洢·��������Ҫ�洢��������*/
     if(Save_File_Path && strcmp(Save_File_Path,""))
     {
         printf("���ڱ����������.....\n");
         if(SaveHuffmanTree(Huffman_Tree,Num_Tree_Nodes,Save_File_Path))
         {
             printf("������������ɹ���\n");
         }

     }




     return 1;
 }


 /*End CreateHuffmanTree************************/



 /* Begain CreateHuffmanCode ****************
 *����    : HuffmanTree *Huffman_Tree - ���ɵĹ�������
 *���    : HuffmanCode *Huffman_Codes -�������ɵĹ���������

 * *********************************************/
 short CreateHuffmanCode(HuffmanTree *Huffman_Tree,HuffmanCode *Huffman_Codes)
 {
     /*���ַ���������*/
     unsigned int Num_Chars;
     /*��ʱ����ÿ���ַ�����Ķ�̬����ռ�*/
     char *Tmp_Ch;
     unsigned int I_Cnt;
     /*ָ����ʱ�ռ���±�*/
     unsigned int Start;
     /*ÿ��ѭ�����ݵ�ʱ��ֱ�ָ��ǰ�ڵ��˫�׵��±�*/
     unsigned int Current_Node,Current_Parent;

     /*����û���δ�����ĵ������Ƚ����ĵ�*/
     if(!Huffman_Codes || Huffman_Codes[0].Char_Info.value == 0)
     {
         printf("���Ƚ����ĵ�!\n");
         return 0;
     }

     else if(!Huffman_Tree || Huffman_Tree[0].Parent == 0)
     {
         printf("��δ�����������������ȴ�����������!\n");
         return 0;
     }

     /*�õ��ܵ��ַ�����*/
     Num_Chars = GetHuffmanCodeslength(Huffman_Codes);
     /*��ʼ����ʱ�ռ�*/
     Tmp_Ch = malloc(sizeof(char) * Num_Chars);
     memset(Tmp_Ch, 0, sizeof(char) * Num_Chars);
     /*����ַ������������*/
     for(I_Cnt = 0; I_Cnt < Num_Chars; I_Cnt++)
     {
         /*����ÿһ���ַ��Ĺ����������ʼ���ڴ�ռ�*/
         Huffman_Codes[I_Cnt].Codes = malloc(sizeof(char)*Num_Chars + 1);
         memset(Huffman_Codes[I_Cnt].Codes, 0, sizeof(char)*Num_Chars + 1);

         /*��������01�ַ�*/
         Start = Num_Chars - 1;
         /*��ʼ����ǰ�ڵ��˫�׵��±�*/
         Current_Node = I_Cnt;
         Current_Parent = Huffman_Tree[I_Cnt].Parent;
         /*��Ҷ�Ӵ��������ݵ����ڵ�*/
         while(Current_Parent != 0)
         {
             Start--;
             /*���Current_Node��curr_parent���ӣ�����'0'*/
             if(Huffman_Tree[Current_Parent].LChild == Current_Node)
             {
                 Tmp_Ch[Start] = '0';
             }
             /*���Current_Node��curr_parent�Һ��ӣ�����'1'*/
             else
             {
                 Tmp_Ch[Start] = '1';
             }
             /*��������*/
             Current_Node = Current_Parent;
             Current_Parent = Huffman_Tree[Current_Node].Parent;

         }
         /*����ʱ�ռ��ַ�����������Ӧ�Ĺ���������*/
         strcpy(Huffman_Codes[I_Cnt].Codes, &Tmp_Ch[Start]);
     }
     free(Tmp_Ch);
     return 1;
 }

/*End CreateHuffmanCode************************/



/* Begain HuffmanEnCode ****************
 *��ָ�����ı����ݽ��й���������
 *����    : HuffmanCode *Huffman_Codes -�������ɵĹ���������
          :char *Text - ָ������Ȼ�����ı�
          :char *Save_File_Path - �洢ָ���ı���Ӧ�Ĺ���������Ķ������ļ�·��
 *���    : ��
 * *********************************************/
unsigned int HuffmanEnCode(HuffmanCode *Huffman_Codes,char *Text,char *Save_File_Path)
{
    unsigned int Num_Chars;
    /* ȫ�ĵĹ���������(�ַ�����01)*/
    char *Full_Codes;
    /* ȫ�ĵĹ���������(��������01)*/
    char *Bin_Chars;
    FILE *fp;
    unsigned I_Cnt,J_Cnt,K_Cnt;

    /*�õ��ַ����������*/
    Num_Chars = GetHuffmanCodeslength(Huffman_Codes);
    /*��ʼ��*/
    Full_Codes = malloc(sizeof(char) * strlen(Text) * Num_Chars);
    Bin_Chars = malloc(sizeof(char) * strlen(Text) * Num_Chars / 8 + 2);
    memset(Full_Codes, 0,sizeof(char) * strlen(Text) * Num_Chars);
    memset(Bin_Chars, 0,sizeof(char) * strlen(Text) * Num_Chars / 8 + 2);


    /*���������ĵ�������ÿ���ַ���ѯ��Ӧ�Ĺ��������룬ƴ�ӵ�FUll*/
    for(I_Cnt = 0; I_Cnt <= strlen(Text);I_Cnt++)
    {
        for(J_Cnt = 0;J_Cnt < Num_Chars;J_Cnt++)
        {
            if(Text[I_Cnt] == Huffman_Codes[J_Cnt].Char_Info.value)
            {
                strcat(Full_Codes,Huffman_Codes[J_Cnt].Codes);
                break;
            }
        }
    }

     /*������������תΪ������*/
     K_Cnt = 0;
     for(J_Cnt = 0;J_Cnt < strlen(Full_Codes) - 8;J_Cnt += 8)
     {
         Bin_Chars[K_Cnt] |= (Full_Codes[J_Cnt] - 48) << 7;
         Bin_Chars[K_Cnt] |= (Full_Codes[J_Cnt + 1] - 48) << 6;
         Bin_Chars[K_Cnt] |= (Full_Codes[J_Cnt + 2] - 48) << 5;
         Bin_Chars[K_Cnt] |= (Full_Codes[J_Cnt + 3] - 48) << 4;
         Bin_Chars[K_Cnt] |= (Full_Codes[J_Cnt + 4] - 48) << 3;
         Bin_Chars[K_Cnt] |= (Full_Codes[J_Cnt + 5] - 48) << 2;
         Bin_Chars[K_Cnt] |= (Full_Codes[J_Cnt + 6] - 48) << 1;
         Bin_Chars[K_Cnt] |= (Full_Codes[J_Cnt + 7] - 48) << 0;
         K_Cnt++;
     }
     /*�����Ҫ���伸λ*/
     for(I_Cnt = 0;I_Cnt < strlen(Full_Codes) - J_Cnt;I_Cnt++)
     {
         Bin_Chars[K_Cnt] |= (Full_Codes[J_Cnt + I_Cnt] - 48) << (7 - I_Cnt);
     }
     /*����*/
     if(Save_File_Path && strcmp(Save_File_Path, ""))
     {
         printf("���ڱ���ָ���ĵ�����������.....\n");
         if((fp = fopen(Save_File_Path,"wb")) == NULL)
         {
             printf("��%sʧ��!\n",Save_File_Path);
             return 0;
         }
         fwrite(Bin_Chars,sizeof(char),K_Cnt,fp);
         printf("����ָ���ĵ����������뵽%s�ɹ���\n",Save_File_Path);

     }
     fclose(fp);
     return K_Cnt;


}

 /*End HuffmanEnCode************************/

 /* Begain HuffmanDnCode ****************
 *��ָ���Ĺ����������Ʊ����������
 *����    : HuffmanTree *Huffman_Tree - ���ɵĹ�������
          ��HuffmanCode *Huffman_Codes -�������ɵĹ���������
          :unsigned int Encode_Len - �����Ķ����ƹ���������ĳ���
          :char *Save_File_Path - �洢ָ���ı���Ӧ�Ĺ���������Ķ������ļ�·��
 *���    : ��
 * *********************************************/
char* HuffmanDnCode(HuffmanTree *Huffman_Tree,HuffmanCode *Huffman_Codes,unsigned int Encode_Len,char *Save_File_Path)
{
    FILE *fp;
    char *Bin_Chars;
    char Bin_Char ;
    unsigned I_Cnt,J_Cnt,K_Cnt = 0;
    unsigned int Iterator_Node;
    unsigned int Root_Node;
    char *Decode_Text;

    Decode_Text = malloc(sizeof(char) * MAX_TEXT_LEN);
    memset(Decode_Text, 0,sizeof(char) * MAX_TEXT_LEN);

    /*����û���δ�����ĵ������Ƚ����ĵ�*/
     if(!Huffman_Codes || Huffman_Codes[0].Char_Info.value == 0)
     {
         printf("���Ƚ����ĵ�!\n");
         return NULL;
     }

     else if(!Huffman_Tree || Huffman_Tree[0].Parent == 0)
     {
         printf("��δ�����������������ȴ�����������!\n");
         return NULL;
     }
     else if ((fp = fopen(Save_File_Path,"rb")) == NULL )
     {
         printf("��%sʧ��!\n",Save_File_Path);
         return NULL;
     }


     /*��Bin����ռ�*/
     Bin_Chars = malloc(sizeof(char) * Encode_Len);
     memset(Bin_Chars,0,sizeof(char) * Encode_Len);
     fread(Bin_Chars,sizeof(char),Encode_Len,fp);
     fclose(fp);
     Iterator_Node = 0;
     while(Huffman_Tree[Iterator_Node].Parent != 0)
     {
         Iterator_Node++;
     }
     Root_Node = Iterator_Node;
     for(I_Cnt = 0;I_Cnt < Encode_Len;I_Cnt++)
     {
         for(J_Cnt = 0;J_Cnt < 8; J_Cnt++)
         {
             Bin_Char = (Bin_Chars[I_Cnt] & (1 << (7 - J_Cnt))) >> (7 - J_Cnt);
             if(Bin_Char)
             {
                 Iterator_Node = Huffman_Tree[Iterator_Node].RChild;
             }
             else
             {
                 Iterator_Node = Huffman_Tree[Iterator_Node].LChild;
             }
             if(Huffman_Tree[Iterator_Node].RChild == 0 && Huffman_Tree[Iterator_Node].LChild == 0)
             {
                 Decode_Text[K_Cnt] = Huffman_Codes[Iterator_Node].Char_Info.value;
                 Iterator_Node = Root_Node;
                 K_Cnt++;
             }
         }


     }
     return Decode_Text;

}


 /*End HuffmanDnCode************************/



 /* Begain CreateHuffmanCodeLength ****************
 *����    : HuffmanCode *Huffman_Codes -�������ɵĹ���������
 *���    : ��
 *����    �������������鳤��
 * *********************************************/
 unsigned int GetHuffmanCodeslength(HuffmanCode *Huffman_Codes)
 {
     unsigned int Length = 0;
     while(Huffman_Codes[Length].Char_Info.value != 0)
     {
         Length++;
     }
     return Length;
 }

 /*End  CreateHuffmanCodeLength*****************/



 /* Begain SelectHufftree *******************
 *����    : HuffmanTree *Huffman_Tree - ���ɵĹ�������
          :int range - ָ����Χ
 *���    :unsigned int *Min_Idx1 - ��СȨ�ؽڵ���±�
          :unsigned int *Min_Idx2 - �ڶ�СȨ�ؽڵ���±�
 *����    �������������鳤��
 * *********************************************/
void SelectHufftree(HuffmanTree *Huffman_Tree,int range,unsigned int *Min_Idx1,unsigned int *Min_Idx2)
{
    unsigned int Smallest = INF,Second_Smallest = INF;
    unsigned int I_Cnt;

    /*��һ��ѭ���ҵ���Сֵ����¼�±�Min_Idx1*/
    for(I_Cnt = 0;I_Cnt <= range; I_Cnt++)
    {
        /*ע��˫��Ϊ0����*/
        if(Huffman_Tree[I_Cnt].Weight <= Smallest && Huffman_Tree[I_Cnt].Parent == 0)
        {
            Smallest = Huffman_Tree[I_Cnt].Weight;
            *Min_Idx1 = I_Cnt;
        }
    }
    /*�ڶ���ѭ���ҵ��ڶ�Сֵ����¼�±�Min_Idx2*/
    for(I_Cnt = 0;I_Cnt <= range;I_Cnt++)
    {
        /*ע��˫��Ϊ0����*/
        if(Huffman_Tree[I_Cnt].Weight <= Second_Smallest && Huffman_Tree[I_Cnt].Parent == 0 && I_Cnt != *Min_Idx1)
        {
            Second_Smallest = Huffman_Tree[I_Cnt].Weight;
            *Min_Idx2 = I_Cnt;
        }
    }

}


  /* End SelectHufftree *****************/




/* Begain SaveHuffmanTree *******************
 *����    : HuffmanTree *Huffman_Tree - ���ɵĹ�������
          :int Num_Tree_Nodes - ���ڵ����
          :char *Save_File_Path - ������ļ�·��
 *���    ��
 * *********************************************/
 short SaveHuffmanTree(HuffmanTree *Huffman_Tree,int Num_Tree_Nodes,char *Save_File_Path)
 {
     FILE *fp;
     if((fp = fopen(Save_File_Path, "wb")) == NULL)
     {
         printf("��%sʧ��!\n",Save_File_Path);
         return 0;
     }
     fwrite(Huffman_Tree,sizeof(HuffmanTree) * Num_Tree_Nodes, 1, fp);
     fclose(fp);
     return 1;
 }


 /* End HuffmanTree *******************/

 /* Begain loadHuffmanTree *******************
 *����    : char *Save_File_Path - ������ļ�·��
 *���    :HuffmanTree *Huffman_Tree - ���ɵĹ�������
 * *********************************************/
 short loadHuffmanTree(HuffmanTree *Huffman_Tree,char *Save_File_Path)
 {
     FILE *fp;
     Huffman_Tree = malloc(2 * sizeof(HuffmanTree) * MAX_NUM_CHAR - 1);
     memset(Huffman_Tree, 0, 2 * sizeof(HuffmanTree) * MAX_NUM_CHAR - 1);
     if((fp = fopen(Save_File_Path,"rb")) == NULL)
     {
         printf("��%sʧ��!\n",Save_File_Path);
         return 0;
     }

     fread(Huffman_Tree,2 * sizeof(HuffmanTree) * MAX_NUM_CHAR - 1, 1, fp);
     fclose(fp);
     return 1;
 }


 /* End loadHuffmanTree *******************/
