/*=====================
Author      :谭铭瑞
Name        :HuffmanCode.c
哈弗曼编码函数声明
=====================*/
#ifndef HUFFMANCODE_H_INCLUDED
#define HUFFMANCODE_H_INCLUDED

/*Basic Settings ************/
/*文档包括总字符种类个数 */
#define MAX_NUM_CHAR    1000
/*文档路径*/
#define TEXT_FILE_PATH   "./text1.txt"
/*文档最大字节数*/
#define MAX_TEXT_LEN      500000
#define INF               999999
/*哈弗曼树的保存*/
#define HUFFMANTREE_SAVE_PATH   "./huffmantree.bin"
/*指定文本的哈夫曼编码的存储路径*/
#define ENCODE_SAVE_PATH        "./encode.bin"
/*Structures ***************/

/*统计字符出现次数映射的结构体*/
typedef struct
{
    /*值*/
    char value;
    /*次数*/
    unsigned int Times;
}CharMap;

/*哈夫曼编码结构体*/
typedef struct
{
    /*该字符信息*/
    CharMap Char_Info;
    /*该字符对应哈弗曼编码字符串*/
    char *Codes;
}HuffmanCode;

/*哈弗曼树结构体*/
typedef struct
{
    /*权重*/
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
