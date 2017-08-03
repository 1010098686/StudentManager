#pragma once


// AddStudentDlg 对话框

class AddStudentDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddStudentDlg)

public:
	AddStudentDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddStudentDlg();

// 对话框数据
	enum { IDD = IDD_ADDSTUDENT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	int ID;
	afx_msg void OnBnClickedButton1();
};
