/*=====================
Author      :谭铭瑞
Name        :HuffmanCode.c
主函数
=====================*/

/****** Begain Includes *******/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Include/HuffmanCode.h"
/****** End    Includes *******/

/****** Begain Defines *******/
#define HUFFMANTREE_SAVE_PATH  "./huffmantree.bin"
#define ENCODE_SAVE_PATH     "./encode.bin"
/****** end    Defines *******/





int main()
{
    /*定义哈夫曼编码数组*/
    HuffmanCode Huffman_Codes[MAX_NUM_CHAR];
    char *Text;
    /*定义哈夫曼树*/
    HuffmanTree Huffman_Tree[2 * MAX_NUM_CHAR - 1];
    /*文档编码后的字节数*/
    unsigned int Encode_Len;
    char *Decode_Text;

    /*分配内存空间并初始化*/
    Text = malloc(sizeof(char) * MAX_TEXT_LEN);
    memset(Text, 0, sizeof(char) * MAX_TEXT_LEN);
    memset(Huffman_Codes, 0, sizeof(HuffmanCode) * MAX_NUM_CHAR);
    memset(Huffman_Tree, 0, sizeof(HuffmanTree) * (2 * MAX_NUM_CHAR - 1));
    /*第一步：解析文本*/
    printf("正在解析文本.....\n");
    if(!ParseText(TEXT_FILE_PATH, Huffman_Codes, Text))
    {
        printf("解析文档失败!\n");
        return -1;
    }
    printf("解析文本完成.....\n");

    /*第二步：生成哈夫曼树*/
    printf("正在生成哈夫曼树.....\n");
    if(!CreateHuffmanTree(Huffman_Codes,Huffman_Tree,HUFFMANTREE_SAVE_PATH))
    {
        printf("生成哈夫曼树失败!\n");
        return -1;
    }
    printf("生成哈夫曼树完成.....\n");

    /*第三部生成哈夫曼编码*/
    printf("正在生成哈夫曼编码.....\n");
    if(!CreateHuffmanCode(Huffman_Tree,Huffman_Codes))
    {
        printf("生成哈夫曼编码失败!\n");
        return -1;
    }
    printf("生成哈夫曼编码完成.....\n");

    /*第四步:对指定文档进行编码并保存*/
    printf("正在对指定文档进行编码.....\n");
    Encode_Len = HuffmanEnCode(Huffman_Codes,Text,ENCODE_SAVE_PATH);
    if(Encode_Len > 0)
    {
        printf("对指定文档进行编码完成!....\n");
    }
    else
    {
        printf("对指定文档进行编码失败!\n");
        return -1;
    }

    /*第五步:进行译码还原*/
    printf("正在对指定文档进行译码.....\n");
    Decode_Text = HuffmanDnCode(Huffman_Tree, Huffman_Codes, Encode_Len, ENCODE_SAVE_PATH);
    if(Decode_Text)
    {
        printf("对指定文档进行译码完成!....\n");
        printf("%s \n",Decode_Text);
    }
    else
    {
        printf("对指定文档进行译码失败!\n");
        return -1;
    }





    return 0;
}
