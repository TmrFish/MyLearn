/*=====================
Author      :谭铭瑞
Name        :HuffmanCode.c
哈夫曼编码主函数
=====================*/

/****** Begain Includes *******/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Include/HuffmanCode.h"
/****** End    Includes *******/

/* Begain Function ParseText ****************
 *输入    : char *Text_File_Path  -文档路径
 *输出    : HuffmanCode *Huffman_Codes -文档初步解析
          :char *Text - 读取文档完整的内容
 * *********************************************/

short ParseText(char *Text_File_Path, HuffmanCode *Huffman_Codes, char *Text)
{
    FILE *fp;         /*文件指针*/
    char Read_Ch;    /*读取文件的字符*/
    char Char_Exist; /*勇于判断某个字符是否已经存在*/
    unsigned int I_Cnt,J_Cnt;

    if((fp = fopen(Text_File_Path, "rt")) == NULL)
    {
        printf("打开%s文件失败!\n", Text_File_Path);
        return 0;
    }
    J_Cnt = 0;

    while((Read_Ch = fgetc(fp)) != EOF)
    {
        /*复位*/
        Char_Exist = 0;
        I_Cnt = 0;

        while(Huffman_Codes[I_Cnt].Char_Info.value != 0)
        {
            /*如果Char_Map 的字符与文档的字符一样,Times +1*/
            if (Huffman_Codes[I_Cnt].Char_Info.value == Read_Ch)
            {
                Huffman_Codes[I_Cnt].Char_Info.Times += 1;
                Char_Exist = 1;
                break;
            }
            I_Cnt++;
        }

        /*如果字符不存在，既遇到新字符*/
        if(!Char_Exist)
        {
            Huffman_Codes[I_Cnt].Char_Info.value = Read_Ch;
            Huffman_Codes[I_Cnt].Char_Info.Times = 1;

        }
        /*把文档内容拷贝到内存*/
        Text[J_Cnt] = Read_Ch;
        J_Cnt++;


    }
    fclose(fp);
    return 1;


}
/* End    Function ParseText ************/



/* Begain CreateHuffmanTree ****************
 *输入    : HuffmanCode *Huffman_Codes -初步生成的哈夫曼编码
          :char *Save_File_Path - 把偶才能哈弗曼树完整路径，如果空则不保存
 *输出    : HuffmanTree *Huffman_Tree - 生成的哈弗曼树

 * *********************************************/
 short CreateHuffmanTree(HuffmanCode *Huffman_Codes,HuffmanTree *Huffman_Tree,char *Save_File_Path)
 {
     /*文本不同字符的数量*/
     int Num_Chars;
     /*哈弗曼树所有节点数量*/
     int Num_Tree_Nodes;
     /*计数器*/
     unsigned int I_Cnt;
     /*当前最小的两个节点下标*/
     unsigned int Min_Idx1 = 0,Min_Idx2 = 0;
     /*获取不同字符的数量*/
     Num_Chars = GetHuffmanCodeslength(Huffman_Codes);
     Num_Tree_Nodes = 2 * Num_Chars - 1;

     /*如果用户还未解析文档，请先解析文档*/
     if(!Huffman_Codes || Huffman_Codes[0].Char_Info.value == 0)
     {
         printf("请先解析文档!\n");
         return 0;
     }

     /*初始化节点信息*/
     for(I_Cnt = 0;I_Cnt < Num_Tree_Nodes;I_Cnt++)
     {
         Huffman_Tree[I_Cnt].Parent = 0;
         Huffman_Tree[I_Cnt].LChild = 0;
         Huffman_Tree[I_Cnt].RChild = 0;
     }

     /*初始化权重节点*/
     for(I_Cnt = 0;I_Cnt < Num_Chars;I_Cnt++)
     {
         Huffman_Tree[I_Cnt].Weight = Huffman_Codes[I_Cnt].Char_Info.Times;
     }

     /*通过n-1次选择、删除、合并来创建哈夫曼树*/
     for(I_Cnt = Num_Chars;I_Cnt < Num_Tree_Nodes;I_Cnt++)
     {
         /*选出当前权值最小的两个节点下标*/
         SelectHufftree(Huffman_Tree, I_Cnt - 1, &Min_Idx1, &Min_Idx2);
         /*将Min_Idx1和Min_Idx2从森铃中删除，并添加到哈夫曼树中*/
         Huffman_Tree[Min_Idx1].Parent = I_Cnt;
         Huffman_Tree[Min_Idx2].Parent = I_Cnt;
         Huffman_Tree[I_Cnt].LChild = Min_Idx1;
         Huffman_Tree[I_Cnt].RChild = Min_Idx2;
         Huffman_Tree[I_Cnt].Weight = Huffman_Tree[Min_Idx1].Weight + Huffman_Tree[Min_Idx2].Weight;

     }
     /*如果用户制定了存储路径，则需要存储哈夫曼树*/
     if(Save_File_Path && strcmp(Save_File_Path,""))
     {
         printf("正在保存哈弗曼树.....\n");
         if(SaveHuffmanTree(Huffman_Tree,Num_Tree_Nodes,Save_File_Path))
         {
             printf("保存哈夫曼树成功！\n");
         }

     }




     return 1;
 }


 /*End CreateHuffmanTree************************/



 /* Begain CreateHuffmanCode ****************
 *输入    : HuffmanTree *Huffman_Tree - 生成的哈弗曼树
 *输出    : HuffmanCode *Huffman_Codes -完整生成的哈夫曼编码

 * *********************************************/
 short CreateHuffmanCode(HuffmanTree *Huffman_Tree,HuffmanCode *Huffman_Codes)
 {
     /*总字符种类数量*/
     unsigned int Num_Chars;
     /*临时放置每个字符编码的动态数组空间*/
     char *Tmp_Ch;
     unsigned int I_Cnt;
     /*指向临时空间的下标*/
     unsigned int Start;
     /*每次循环回溯的时候分别指向当前节点和双亲的下标*/
     unsigned int Current_Node,Current_Parent;

     /*如果用户还未解析文档，请先解析文档*/
     if(!Huffman_Codes || Huffman_Codes[0].Char_Info.value == 0)
     {
         printf("请先解析文档!\n");
         return 0;
     }

     else if(!Huffman_Tree || Huffman_Tree[0].Parent == 0)
     {
         printf("还未创建哈夫曼树，请先创建哈夫曼树!\n");
         return 0;
     }

     /*得到总的字符个数*/
     Num_Chars = GetHuffmanCodeslength(Huffman_Codes);
     /*初始化临时空间*/
     Tmp_Ch = malloc(sizeof(char) * Num_Chars);
     memset(Tmp_Ch, 0, sizeof(char) * Num_Chars);
     /*逐个字符求哈弗曼编码*/
     for(I_Cnt = 0; I_Cnt < Num_Chars; I_Cnt++)
     {
         /*对于每一个字符的哈夫曼编码初始化内存空间*/
         Huffman_Codes[I_Cnt].Codes = malloc(sizeof(char)*Num_Chars + 1);
         memset(Huffman_Codes[I_Cnt].Codes, 0, sizeof(char)*Num_Chars + 1);

         /*倒过来存01字符*/
         Start = Num_Chars - 1;
         /*初始化当前节点和双亲的下标*/
         Current_Node = I_Cnt;
         Current_Parent = Huffman_Tree[I_Cnt].Parent;
         /*从叶子触发，回溯到根节点*/
         while(Current_Parent != 0)
         {
             Start--;
             /*如果Current_Node是curr_parent左孩子，生成'0'*/
             if(Huffman_Tree[Current_Parent].LChild == Current_Node)
             {
                 Tmp_Ch[Start] = '0';
             }
             /*如果Current_Node是curr_parent右孩子，生成'1'*/
             else
             {
                 Tmp_Ch[Start] = '1';
             }
             /*继续回溯*/
             Current_Node = Current_Parent;
             Current_Parent = Huffman_Tree[Current_Node].Parent;

         }
         /*将临时空间字符串拷贝给相应的哈夫曼编码*/
         strcpy(Huffman_Codes[I_Cnt].Codes, &Tmp_Ch[Start]);
     }
     free(Tmp_Ch);
     return 1;
 }

/*End CreateHuffmanCode************************/



/* Begain HuffmanEnCode ****************
 *对指定的文本内容进行哈夫曼编码
 *输入    : HuffmanCode *Huffman_Codes -完整生成的哈夫曼编码
          :char *Text - 指定的自然语言文本
          :char *Save_File_Path - 存储指定文本对应的哈夫曼编码的二进制文件路径
 *输出    : 无
 * *********************************************/
unsigned int HuffmanEnCode(HuffmanCode *Huffman_Codes,char *Text,char *Save_File_Path)
{
    unsigned int Num_Chars;
    /* 全文的哈夫曼编码(字符来存01)*/
    char *Full_Codes;
    /* 全文的哈夫曼编码(比特来存01)*/
    char *Bin_Chars;
    FILE *fp;
    unsigned I_Cnt,J_Cnt,K_Cnt;

    /*得到字符种类的总数*/
    Num_Chars = GetHuffmanCodeslength(Huffman_Codes);
    /*初始化*/
    Full_Codes = malloc(sizeof(char) * strlen(Text) * Num_Chars);
    Bin_Chars = malloc(sizeof(char) * strlen(Text) * Num_Chars / 8 + 2);
    memset(Full_Codes, 0,sizeof(char) * strlen(Text) * Num_Chars);
    memset(Bin_Chars, 0,sizeof(char) * strlen(Text) * Num_Chars / 8 + 2);


    /*遍历整个文档，对于每个字符查询相应的哈夫曼编码，拼接到FUll*/
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

     /*将哈夫曼编码转为二进制*/
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
     /*最后还需要补充几位*/
     for(I_Cnt = 0;I_Cnt < strlen(Full_Codes) - J_Cnt;I_Cnt++)
     {
         Bin_Chars[K_Cnt] |= (Full_Codes[J_Cnt + I_Cnt] - 48) << (7 - I_Cnt);
     }
     /*保存*/
     if(Save_File_Path && strcmp(Save_File_Path, ""))
     {
         printf("正在保存指定文档哈弗曼编码.....\n");
         if((fp = fopen(Save_File_Path,"wb")) == NULL)
         {
             printf("打开%s失败!\n",Save_File_Path);
             return 0;
         }
         fwrite(Bin_Chars,sizeof(char),K_Cnt,fp);
         printf("保存指定文档哈夫曼编码到%s成功！\n",Save_File_Path);

     }
     fclose(fp);
     return K_Cnt;


}

 /*End HuffmanEnCode************************/

 /* Begain HuffmanDnCode ****************
 *对指定的哈夫曼二进制编码进行译码
 *输入    : HuffmanTree *Huffman_Tree - 生成的哈弗曼树
          ：HuffmanCode *Huffman_Codes -完整生成的哈夫曼编码
          :unsigned int Encode_Len - 编码后的二进制哈夫曼编码的长度
          :char *Save_File_Path - 存储指定文本对应的哈夫曼编码的二进制文件路径
 *输出    : 无
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

    /*如果用户还未解析文档，请先解析文档*/
     if(!Huffman_Codes || Huffman_Codes[0].Char_Info.value == 0)
     {
         printf("请先解析文档!\n");
         return NULL;
     }

     else if(!Huffman_Tree || Huffman_Tree[0].Parent == 0)
     {
         printf("还未创建哈夫曼树，请先创建哈夫曼树!\n");
         return NULL;
     }
     else if ((fp = fopen(Save_File_Path,"rb")) == NULL )
     {
         printf("打开%s失败!\n",Save_File_Path);
         return NULL;
     }


     /*给Bin分配空间*/
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
 *输入    : HuffmanCode *Huffman_Codes -初步生成的哈夫曼编码
 *输出    : 无
 *返回    哈弗曼编码数组长度
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
 *输入    : HuffmanTree *Huffman_Tree - 生成的哈弗曼树
          :int range - 指定范围
 *输出    :unsigned int *Min_Idx1 - 最小权重节点的下标
          :unsigned int *Min_Idx2 - 第二小权重节点的下标
 *返回    哈弗曼编码数组长度
 * *********************************************/
void SelectHufftree(HuffmanTree *Huffman_Tree,int range,unsigned int *Min_Idx1,unsigned int *Min_Idx2)
{
    unsigned int Smallest = INF,Second_Smallest = INF;
    unsigned int I_Cnt;

    /*第一次循环找到最小值，记录下标Min_Idx1*/
    for(I_Cnt = 0;I_Cnt <= range; I_Cnt++)
    {
        /*注意双亲为0才算*/
        if(Huffman_Tree[I_Cnt].Weight <= Smallest && Huffman_Tree[I_Cnt].Parent == 0)
        {
            Smallest = Huffman_Tree[I_Cnt].Weight;
            *Min_Idx1 = I_Cnt;
        }
    }
    /*第二次循环找到第二小值，记录下标Min_Idx2*/
    for(I_Cnt = 0;I_Cnt <= range;I_Cnt++)
    {
        /*注意双亲为0才算*/
        if(Huffman_Tree[I_Cnt].Weight <= Second_Smallest && Huffman_Tree[I_Cnt].Parent == 0 && I_Cnt != *Min_Idx1)
        {
            Second_Smallest = Huffman_Tree[I_Cnt].Weight;
            *Min_Idx2 = I_Cnt;
        }
    }

}


  /* End SelectHufftree *****************/




/* Begain SaveHuffmanTree *******************
 *输入    : HuffmanTree *Huffman_Tree - 生成的哈弗曼树
          :int Num_Tree_Nodes - 树节点个数
          :char *Save_File_Path - 保存的文件路径
 *输出    无
 * *********************************************/
 short SaveHuffmanTree(HuffmanTree *Huffman_Tree,int Num_Tree_Nodes,char *Save_File_Path)
 {
     FILE *fp;
     if((fp = fopen(Save_File_Path, "wb")) == NULL)
     {
         printf("打开%s失败!\n",Save_File_Path);
         return 0;
     }
     fwrite(Huffman_Tree,sizeof(HuffmanTree) * Num_Tree_Nodes, 1, fp);
     fclose(fp);
     return 1;
 }


 /* End HuffmanTree *******************/

 /* Begain loadHuffmanTree *******************
 *输入    : char *Save_File_Path - 保存的文件路径
 *输出    :HuffmanTree *Huffman_Tree - 生成的哈弗曼树
 * *********************************************/
 short loadHuffmanTree(HuffmanTree *Huffman_Tree,char *Save_File_Path)
 {
     FILE *fp;
     Huffman_Tree = malloc(2 * sizeof(HuffmanTree) * MAX_NUM_CHAR - 1);
     memset(Huffman_Tree, 0, 2 * sizeof(HuffmanTree) * MAX_NUM_CHAR - 1);
     if((fp = fopen(Save_File_Path,"rb")) == NULL)
     {
         printf("打开%s失败!\n",Save_File_Path);
         return 0;
     }

     fread(Huffman_Tree,2 * sizeof(HuffmanTree) * MAX_NUM_CHAR - 1, 1, fp);
     fclose(fp);
     return 1;
 }


 /* End loadHuffmanTree *******************/
