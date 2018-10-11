#pragma once
#include<fstream>    
#include <afx.h>
#include"stdafx.h"
#include "huffman.h"
using namespace std;

//统计字符出现频率
void Chuffman::cal()
{
	FILE *in = fopen(INPATH, "rb");   //打开文件流
	memset(P, 0, sizeof(P));   //把P初始化成0
	char a = fgetc(in);
	while (!feof(in))
	{
		P[a + 300]++;
		FILESIZE++;
		a = fgetc(in);
	}
	fclose(in);
}

//获得哈夫曼编码
void Chuffman::getcode(int left, int now, char c, int deep)
{
	if (deep>0)
	{
		strcpy(code[T[now].data + 300], code[T[left].data + 300]);
		code[T[now].data + 300][deep - 1] = c;    code[T[now].data + 300][deep] = '\0';
	}

	if (T[now].left != -1)
		getcode(now, T[now].left, '0', deep + 1);
	if (T[now].right != -1)
		getcode(now, T[now].right, '1', deep + 1);
}

//创建哈弗曼树
void Chuffman::creatHoffman()
{
	int i, j, n = 0, k, s;

	for (i = 0; i<600; i++)
		if (P[i]>0)
		{
			T[n].data = char(i - 300);
			T[n].weight = P[i];
			T[n].left = T[n].right = -1;
			n++;
		}
	char lock[600];
	memset(lock, 0, sizeof(lock));
	for (k = 0, s = n; k<s - 1; k++)           //开始生成哈弗曼树
	{
		int min1, min2 = -1;
		for (i = 0; i<n; i++)
			if (!lock[i]) { min1 = i; break; }

		for (j = i; j<n; j++)     //找到权值第一小的节点
			if (!lock[j] && T[j].weight<T[min1].weight)
				min1 = j;
		for (j = i; j<n; j++)     //找到权值第一小的节点
			if (!lock[j] && j != min1 && ((min2 == -1 || T[j].weight<T[min2].weight)))
				min2 = j;
		//找到两个节点后开始合并

		T[n].weight = T[min1].weight + T[min2].weight;
		T[n].data = -300; T[n].right = min1;    T[n].left = min2;

		code[T[n].data + 300][0] = '\0';
		lock[min1] = lock[min2] = 1;

		n++;
	}
	HEAD = n - 1;
	getcode(-1, n - 1, '0', 0);
}

//压缩
void Chuffman::compress(CString Cstr, CString CStr1)
{
	FILESIZE = 0;
	for (int i = 0; i<8; i++)
		W[i] = (char)pow(2, 7 - i);
	INPATH = Cstr;
	OUTPATH = CStr1 + ".huf";
	cal();
	creatHoffman();
	//保存密码本
	ofstream out1(OUTPATH, ios::binary);
	out1.write((char *)&FILESIZE, sizeof(long));
	out1.write((char *)&HEAD, sizeof(int));
	for (int i = 0; i <= HEAD; i++)
		out1.write((char *)&T[i], sizeof(tree));
	out1.close();
	//保存文件
	ifstream in(INPATH, ios::binary);
	ofstream out(OUTPATH, ios::binary | ios::app);
	char a;
	in.read((char *)&a, sizeof(char));
	char temp = 0; int th = 0;
	while (!in.eof())
	{
		for (int i = 0; i<strlen(code[a + 300]); i++)
		{
			if (code[a + 300][i] - 48)   //48是0 49是1
			{
				temp = temp | W[th];
			}
			th++;
			if (th>7)
			{
				th = 0;
				out.write((char *)&temp, sizeof(char));
				temp = 0;
			}
		}
		in.read((char *)&a, sizeof(char));
	}
	if (th>0)
		out.write((char *)&temp, sizeof(char));
	in.close();
	out.close();
}

//解压
void Chuffman::uncompress(CString Cstr , CString Cstr1)
{
	FILESIZE = 0;
	for (int i = 0; i<8; i++)
		W[i] = (char)pow(2, 7 - i);

	INPATH = Cstr;
	OUTPATH = Cstr1;
	//阅读密码本
	ifstream in1(INPATH, ios::binary);
	in1.read((char *)&FILESIZE, sizeof(long));
	in1.read((char *)&HEAD, sizeof(int));
	for (int i = 0; i <= HEAD; i++)
		in1.read((char *)&T[i], sizeof(tree));
	in1.close();
	//
	getcode(-1, HEAD, '0', 0);
	OUTPATH.TrimRight(".huf");
	//还原文件
	ifstream in(INPATH, ios::binary);
	ofstream out(OUTPATH, ios::binary);

	in.read((char *)&FILESIZE, sizeof(long));
	in.read((char *)&HEAD, sizeof(int));
	for (int i = 0; i <= HEAD; i++)
		in.read((char *)&T[i], sizeof(tree));

	char a;
	in.read((char *)&a, sizeof(char));
	int p = HEAD;
	while (!in.eof() && FILESIZE)
	{
		for (int i = 0; i<8 && FILESIZE; i++)
		{
			if (a&W[i])
			{
				if (T[p].right != -1)
					p = T[p].right;
				else
				{
					out.write((char *)&T[p].data, sizeof(char));
					p = HEAD;
					FILESIZE--;
					i--;
				}
			}
			else
			{
				if (T[p].left != -1)
					p = T[p].left;
				else
				{
					out.write((char *)&T[p].data, sizeof(char));
					p = HEAD;
					FILESIZE--;
					i--;
				}
			}
		}
		in.read((char *)&a, sizeof(char));
	}
	while (FILESIZE--)
		out.write((char *)&T[p].data, sizeof(char));
	in.close();
	out.close();
}
