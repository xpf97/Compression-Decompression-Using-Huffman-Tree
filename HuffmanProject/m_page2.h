#pragma once


// m_page2 对话框

class m_page2 : public CDialog
{
	DECLARE_DYNAMIC(m_page2)

public:
	m_page2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~m_page2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString edit2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
