#pragma once


// AddCourseDlg �Ի���

class AddCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddCourseDlg)

public:
	AddCourseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddCourseDlg();

// �Ի�������
	enum { IDD = IDD_ADDCOURSE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	int credit;
	afx_msg void OnBnClickedOk();
};
