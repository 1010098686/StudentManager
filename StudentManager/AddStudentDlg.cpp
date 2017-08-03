// AddStudentDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentManager.h"
#include "AddStudentDlg.h"
#include "afxdialogex.h"


// AddStudentDlg 对话框

IMPLEMENT_DYNAMIC(AddStudentDlg, CDialogEx)

AddStudentDlg::AddStudentDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddStudentDlg::IDD, pParent)
	, name(_T(""))
	, ID(0)
{

}

AddStudentDlg::~AddStudentDlg()
{
}

void AddStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT2, ID);
}


BEGIN_MESSAGE_MAP(AddStudentDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &AddStudentDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// AddStudentDlg 消息处理程序


void AddStudentDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	
	CDialogEx::OnOK();
	UpdateData(TRUE);
}
