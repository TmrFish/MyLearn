/*=====================
Author      :̷����
Name        :HuffmanCode.c
������
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
    /*�����������������*/
    HuffmanCode Huffman_Codes[MAX_NUM_CHAR];
    char *Text;
    /*�����������*/
    HuffmanTree Huffman_Tree[2 * MAX_NUM_CHAR - 1];
    /*�ĵ��������ֽ���*/
    unsigned int Encode_Len;
    char *Decode_Text;

    /*�����ڴ�ռ䲢��ʼ��*/
    Text = malloc(sizeof(char) * MAX_TEXT_LEN);
    memset(Text, 0, sizeof(char) * MAX_TEXT_LEN);
    memset(Huffman_Codes, 0, sizeof(HuffmanCode) * MAX_NUM_CHAR);
    memset(Huffman_Tree, 0, sizeof(HuffmanTree) * (2 * MAX_NUM_CHAR - 1));
    /*��һ���������ı�*/
    printf("���ڽ����ı�.....\n");
    if(!ParseText(TEXT_FILE_PATH, Huffman_Codes, Text))
    {
        printf("�����ĵ�ʧ��!\n");
        return -1;
    }
    printf("�����ı����.....\n");

    /*�ڶ��������ɹ�������*/
    printf("�������ɹ�������.....\n");
    if(!CreateHuffmanTree(Huffman_Codes,Huffman_Tree,HUFFMANTREE_SAVE_PATH))
    {
        printf("���ɹ�������ʧ��!\n");
        return -1;
    }
    printf("���ɹ����������.....\n");

    /*���������ɹ���������*/
    printf("�������ɹ���������.....\n");
    if(!CreateHuffmanCode(Huffman_Tree,Huffman_Codes))
    {
        printf("���ɹ���������ʧ��!\n");
        return -1;
    }
    printf("���ɹ������������.....\n");

    /*���Ĳ�:��ָ���ĵ����б��벢����*/
    printf("���ڶ�ָ���ĵ����б���.....\n");
    Encode_Len = HuffmanEnCode(Huffman_Codes,Text,ENCODE_SAVE_PATH);
    if(Encode_Len > 0)
    {
        printf("��ָ���ĵ����б������!....\n");
    }
    else
    {
        printf("��ָ���ĵ����б���ʧ��!\n");
        return -1;
    }

    /*���岽:�������뻹ԭ*/
    printf("���ڶ�ָ���ĵ���������.....\n");
    Decode_Text = HuffmanDnCode(Huffman_Tree, Huffman_Codes, Encode_Len, ENCODE_SAVE_PATH);
    if(Decode_Text)
    {
        printf("��ָ���ĵ������������!....\n");
        printf("%s \n",Decode_Text);
    }
    else
    {
        printf("��ָ���ĵ���������ʧ��!\n");
        return -1;
    }





    return 0;
}
