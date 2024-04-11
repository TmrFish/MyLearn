/*=====================
Author      :̷����
Name        :HuffmanCode.c
���������뺯������
=====================*/
#ifndef HUFFMANCODE_H_INCLUDED
#define HUFFMANCODE_H_INCLUDED

/*Basic Settings ************/
/*�ĵ��������ַ�������� */
#define MAX_NUM_CHAR    1000
/*�ĵ�·��*/
#define TEXT_FILE_PATH   "./text1.txt"
/*�ĵ�����ֽ���*/
#define MAX_TEXT_LEN      500000
#define INF               999999
/*���������ı���*/
#define HUFFMANTREE_SAVE_PATH   "./huffmantree.bin"
/*ָ���ı��Ĺ���������Ĵ洢·��*/
#define ENCODE_SAVE_PATH        "./encode.bin"
/*Structures ***************/

/*ͳ���ַ����ִ���ӳ��Ľṹ��*/
typedef struct
{
    /*ֵ*/
    char value;
    /*����*/
    unsigned int Times;
}CharMap;

/*����������ṹ��*/
typedef struct
{
    /*���ַ���Ϣ*/
    CharMap Char_Info;
    /*���ַ���Ӧ�����������ַ���*/
    char *Codes;
}HuffmanCode;

/*���������ṹ��*/
typedef struct
{
    /*Ȩ��*/
   unsigned int Weight;
   unsigned int Parent,LChild,RChild;
}HTNode,HuffmanTree;


/*Functions *************/
short ParseText(char *Text_File_Path,HuffmanCode *Huffman_Codes,char *Text);
short CreateHuffmanTree(HuffmanCode *Huffman_Codes,HuffmanTree *Huffman_Tree,char *Save_File_Path);
unsigned int GetHuffmanCodeslength(HuffmanCode *Huffman_Codes);
void SelectHufftree(HuffmanTree *Huffman_Tree,int range,unsigned int *Min_Idx1,unsigned int *Min_Idx2);
short SaveHuffmanTree(HuffmanTree *Huffman_Tree,int Num_Tree_Nodes,char *Save_File_Path);
short loadHuffmanTree(HuffmanTree *Huffman_Tree,char *Save_File_Path);
short CreateHuffmanCode(HuffmanTree *Huffman_Tree,HuffmanCode *Huffman_Codes);
unsigned int HuffmanEnCode(HuffmanCode *Huffman_Codes,char *Text,char *Save_File_Path);
char* HuffmanDnCode(HuffmanTree *Huffman_Tree,HuffmanCode *Huffman_Codes,unsigned int Encode_Len,char *Save_File_Path);
#endif // HUFFMANCODE_H_INCLUDED
