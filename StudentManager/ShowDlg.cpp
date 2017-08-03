// ShowDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentManager.h"
#include "ShowDlg.h"
#include "afxdialogex.h"


// ShowDlg 对话框

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


// ShowDlg 消息处理程序


BOOL ShowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void ShowDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
