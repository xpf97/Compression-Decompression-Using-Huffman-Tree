
// HuffmanProject.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CHuffmanProjectApp: 
// �йش����ʵ�֣������ HuffmanProject.cpp
//

class CHuffmanProjectApp : public CWinApp
{
public:
	CHuffmanProjectApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CHuffmanProjectApp theApp;