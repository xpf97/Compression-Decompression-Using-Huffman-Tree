#pragma once
#define HUFFMAN_H_
#include<fstream>    
#include <afx.h>
#include"stdafx.h"
class Chuffman {
	struct tree
	{
		int weight;
		int left;
		int right;
		int data;
	};
	long P[600];				//保存每种字符的频率
	long HEAD;					//保存哈夫曼树节点个数
	long FILESIZE = 0;			//保存文件长度
	CString INPATH, OUTPATH;		//保存来源文件路径和输出文件路径
	char W[8] = { 0 };				//保存2的0次方,2的一次放,2的二次方.....2的7次方.
	char code[600][600];		//保存每个节点的哈夫曼编码
	tree T[600];			    //整个哈夫曼树节点

public:
	void cal();
	void getcode(int left, int now, char c, int deep);
	void creatHoffman();
	void compress(CString Cstr , CString Cstr1);
	void uncompress(CString Cstr , CString Cstr1);
};

