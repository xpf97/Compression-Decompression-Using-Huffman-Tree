#pragma once


// m_page1 �Ի���

class m_page1 : public CDialog
{
	DECLARE_DYNAMIC(m_page1)

public:
	m_page1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~m_page1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString edit1;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
