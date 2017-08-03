#pragma once
#include "afxwin.h"


// ShowDlg 对话框

class ShowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShowDlg)

public:
	ShowDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ShowDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString content;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
