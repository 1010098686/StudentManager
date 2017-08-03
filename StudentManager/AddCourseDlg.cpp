// AddCourseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentManager.h"
#include "AddCourseDlg.h"
#include "afxdialogex.h"


// AddCourseDlg 对话框

IMPLEMENT_DYNAMIC(AddCourseDlg, CDialogEx)

AddCourseDlg::AddCourseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddCourseDlg::IDD, pParent)
	, name(_T(""))
	, credit(0)
{

}

AddCourseDlg::~AddCourseDlg()
{
}

void AddCourseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_COURSE_NAME, name);
	DDX_Text(pDX, IDC_COURSE_CREDIT, credit);
}


BEGIN_MESSAGE_MAP(AddCourseDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddCourseDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// AddCourseDlg 消息处理程序


void AddCourseDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	UpdateData(TRUE);
}
