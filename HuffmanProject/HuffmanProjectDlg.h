
// HuffmanProjectDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CHuffmanProjectDlg �Ի���
class CHuffmanProjectDlg : public CDialogEx
{
// ����
public:
	CHuffmanProjectDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HUFFMANPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabcontrol;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
