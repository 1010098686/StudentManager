#pragma once


// OpDialog 对话框

class OpDialog : public CDialogEx
{
	DECLARE_DYNAMIC(OpDialog)

public:
	OpDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~OpDialog();

// 对话框数据
	enum { IDD = IDD_OP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString text;
	CString content;
	afx_msg void OnBnClickedOk();
};
