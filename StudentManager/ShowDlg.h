#pragma once
#include "afxwin.h"


// ShowDlg �Ի���

class ShowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShowDlg)

public:
	ShowDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ShowDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString content;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
