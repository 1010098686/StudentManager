// ShowDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentManager.h"
#include "ShowDlg.h"
#include "afxdialogex.h"


// ShowDlg �Ի���

IMPLEMENT_DYNAMIC(ShowDlg, CDialogEx)

ShowDlg::ShowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ShowDlg::IDD, pParent)
	, content(_T(""))
{
	
}

ShowDlg::~ShowDlg()
{
}

void ShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, content);
}


BEGIN_MESSAGE_MAP(ShowDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ShowDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// ShowDlg ��Ϣ�������


BOOL ShowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void ShowDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
