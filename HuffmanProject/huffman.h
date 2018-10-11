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
	long P[600];				//����ÿ���ַ���Ƶ��
	long HEAD;					//������������ڵ����
	long FILESIZE = 0;			//�����ļ�����
	CString INPATH, OUTPATH;		//������Դ�ļ�·��������ļ�·��
	char W[8] = { 0 };				//����2��0�η�,2��һ�η�,2�Ķ��η�.....2��7�η�.
	char code[600][600];		//����ÿ���ڵ�Ĺ���������
	tree T[600];			    //�������������ڵ�

public:
	void cal();
	void getcode(int left, int now, char c, int deep);
	void creatHoffman();
	void compress(CString Cstr , CString Cstr1);
	void uncompress(CString Cstr , CString Cstr1);
};

