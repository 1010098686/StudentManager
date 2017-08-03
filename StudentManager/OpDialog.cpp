// OpDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentManager.h"
#include "OpDialog.h"
#include "afxdialogex.h"


// OpDialog 对话框

IMPLEMENT_DYNAMIC(OpDialog, CDialogEx)

OpDialog::OpDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(OpDialog::IDD, pParent)
	, text(_T(""))
	, content(_T(""))
{

}

OpDialog::~OpDialog()
{
}

void OpDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_OP_TEXT, text);
	DDX_Text(pDX, IDC_OP_CONTENT, content);
}


BEGIN_MESSAGE_MAP(OpDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &OpDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// OpDialog 消息处理程序


void OpDialog::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	UpdateData(TRUE);
}
