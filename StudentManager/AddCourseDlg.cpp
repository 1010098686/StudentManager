// AddCourseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentManager.h"
#include "AddCourseDlg.h"
#include "afxdialogex.h"


// AddCourseDlg �Ի���

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


// AddCourseDlg ��Ϣ�������


void AddCourseDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	UpdateData(TRUE);
}
