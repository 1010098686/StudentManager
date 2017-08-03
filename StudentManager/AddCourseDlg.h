#pragma once


// AddCourseDlg 对话框

class AddCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddCourseDlg)

public:
	AddCourseDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddCourseDlg();

// 对话框数据
	enum { IDD = IDD_ADDCOURSE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	int credit;
	afx_msg void OnBnClickedOk();
};
