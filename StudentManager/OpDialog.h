#pragma once


// OpDialog �Ի���

class OpDialog : public CDialogEx
{
	DECLARE_DYNAMIC(OpDialog)

public:
	OpDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~OpDialog();

// �Ի�������
	enum { IDD = IDD_OP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString text;
	CString content;
	afx_msg void OnBnClickedOk();
};
