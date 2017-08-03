#pragma once
#include "afxcmn.h"

#include"StudentManagerDoc.h"
#include"AddStudentDlg.h"
#include"AddCourseDlg.h"
#include"OpDialog.h"
#include"ShowDlg.h"

// StudentManagerView 窗体视图

class StudentManagerView : public CFormView
{
	DECLARE_DYNCREATE(StudentManagerView)

protected:
	StudentManagerView();           // 动态创建所使用的受保护的构造函数
	virtual ~StudentManagerView();

public:
	enum { IDD = IDD_STUDENTMANAGERVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl stu_ctrl;
	CListCtrl course_ctrl;
private:
	void editStudent(int row);
	void editCourse(int row);
public:
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnAddStudent();
	afx_msg void OnAddCourse();
	afx_msg void OnNMRClickStuList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDelStudent();
	afx_msg void OnJoinCourse();
	afx_msg void OnDelCourse();
	afx_msg void OnNMRClickCourseList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDelCourseFromCourseList();
	afx_msg void OnEditStudent();
	afx_msg void OnNMDblclkStudentList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEditCourse();
	afx_msg void OnNMDblclkCourseList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSortID();
	afx_msg void OnSortName();
	afx_msg void OnQueryCoursesOfStudent();
	afx_msg void OnQueryStudentsOfCourse();
};


