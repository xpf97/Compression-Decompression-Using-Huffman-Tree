// m_page1.cpp : 实现文件
//

#include "stdafx.h"
#include "HuffmanProject.h"
#include "m_page1.h"
#include "afxdialogex.h"
#include "huffman.h"


// m_page1 对话框
Chuffman cf;
CString cstr;
IMPLEMENT_DYNAMIC(m_page1, CDialog)

m_page1::m_page1(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
	, edit1(_T(""))
{

}

m_page1::~m_page1()
{
}

void m_page1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, edit1);
}


BEGIN_MESSAGE_MAP(m_page1, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &m_page1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &m_page1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &m_page1::OnBnClickedButton3)
END_MESSAGE_MAP()


// m_page1 消息处理程序


void m_page1::OnBnClickedButton1()
{
	UpdateData();
	CFileDialog dlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "全部文件|*.*||");
	if (IDOK == dlg.DoModal())
	{
		edit1 = dlg.GetPathName();
		cstr = dlg.GetFileName();
	}
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void m_page1::OnBnClickedButton2()
{
	if (edit1 == L"")
	{
		MessageBox("未选择文件");
		return;
	}
	cf.compress(edit1,edit1);
	MessageBox("压缩成功");
	// TODO: 在此添加控件通知处理程序代码
}



void m_page1::OnBnClickedButton3()
{
	if (edit1 == L"")
	{
		MessageBox("未选择文件");
		return;
	}
	CString CStr;
	CString m_strFileOut = _T("");
	TCHAR szSelected[MAX_PATH];//用来存放文件夹路径  
	BROWSEINFO bi;
	LPITEMIDLIST pidl;
	bi.hwndOwner = this->m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szSelected;
	bi.lpszTitle = _T("选择输出文件路径");
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	bi.lpfn = NULL;
	bi.lParam = NULL;
	bi.iImage = NULL;
	if ((pidl = SHBrowseForFolder(&bi)) != NULL)
	{
		if (SUCCEEDED(SHGetPathFromIDList(pidl, szSelected))) //得到文件夹的全路径，不要的话，只得本文件夹名  
		{
			m_strFileOut = szSelected;
			CStr = m_strFileOut + "\\" + cstr;
			cf.compress(edit1, CStr);
			MessageBox("压缩成功");
		}
	}
    // TODO: 在此添加控件通知处理程序代码
}
