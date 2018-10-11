// m_page2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HuffmanProject.h"
#include "m_page2.h"
#include "afxdialogex.h"
#include"huffman.h"

// m_page2 �Ի���
Chuffman cf1;
CString cstr1;
IMPLEMENT_DYNAMIC(m_page2, CDialog)

m_page2::m_page2(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG2, pParent)
	, edit2(_T(""))
{

}

m_page2::~m_page2()
{
}

void m_page2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, edit2);
}


BEGIN_MESSAGE_MAP(m_page2, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &m_page2::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &m_page2::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &m_page2::OnBnClickedButton3)
END_MESSAGE_MAP()


// m_page2 ��Ϣ�������


void m_page2::OnBnClickedButton1()
{
	CString str;
	UpdateData();
	CFileDialog dlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "�ҵ�ѹ���ļ�|*.huf||");
	if (IDOK == dlg.DoModal())
	{
		edit2 = dlg.GetPathName();
		cstr1 = dlg.GetFileName();
	}
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void m_page2::OnBnClickedButton2()
{
	if (edit2 == L"")
	{
		MessageBox("δѡ���ļ�");
		return;
	}
	cf1.uncompress(edit2,edit2);
	MessageBox("��ѹ�ɹ�");
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void m_page2::OnBnClickedButton3()
{
	if (edit2 == L"")
	{
		MessageBox("δѡ���ļ�");
		return;
	}
	CString CStr;
	CString m_strFileOut = _T("");
	TCHAR szSelected[MAX_PATH];//��������ļ���·��  
	BROWSEINFO bi;
	LPITEMIDLIST pidl;
	bi.hwndOwner = this->m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szSelected;
	bi.lpszTitle = _T("ѡ������ļ�·��");
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	bi.lpfn = NULL;
	bi.lParam = NULL;
	bi.iImage = NULL;
	if ((pidl = SHBrowseForFolder(&bi)) != NULL)
	{
		if (SUCCEEDED(SHGetPathFromIDList(pidl, szSelected))) //�õ��ļ��е�ȫ·������Ҫ�Ļ���ֻ�ñ��ļ�����  
		{
			m_strFileOut = szSelected;
			CStr = m_strFileOut + "\\" + cstr1;
			cf1.uncompress(edit2, CStr);
			MessageBox("��ѹ�ɹ�");
		}
	}
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
