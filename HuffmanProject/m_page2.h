#pragma once


// m_page2 �Ի���

class m_page2 : public CDialog
{
	DECLARE_DYNAMIC(m_page2)

public:
	m_page2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~m_page2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString edit2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
