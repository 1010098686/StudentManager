#pragma once


// AddStudentDlg �Ի���

class AddStudentDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddStudentDlg)

public:
	AddStudentDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddStudentDlg();

// �Ի�������
	enum { IDD = IDD_ADDSTUDENT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	int ID;
	afx_msg void OnBnClickedButton1();
};
