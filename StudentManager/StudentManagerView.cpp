// StudentManagerView.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentManager.h"
#include "StudentManagerView.h"


// StudentManagerView

IMPLEMENT_DYNCREATE(StudentManagerView, CFormView)

StudentManagerView::StudentManagerView()
	: CFormView(StudentManagerView::IDD)
{

}

StudentManagerView::~StudentManagerView()
{
}

void StudentManagerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, stu_ctrl);
	DDX_Control(pDX, IDC_LIST2, course_ctrl);
}

BEGIN_MESSAGE_MAP(StudentManagerView, CFormView)
	ON_WM_SIZE()
	ON_COMMAND(ID_32772, &StudentManagerView::OnAddStudent)
	ON_COMMAND(ID_32773, &StudentManagerView::OnAddCourse)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, &StudentManagerView::OnNMRClickStuList)
	ON_COMMAND(ID_32774, &StudentManagerView::OnDelStudent)
	ON_COMMAND(ID_32775, &StudentManagerView::OnJoinCourse)
	ON_COMMAND(ID_32776, &StudentManagerView::OnDelCourse)
	ON_NOTIFY(NM_RCLICK, IDC_LIST2, &StudentManagerView::OnNMRClickCourseList)
	ON_COMMAND(ID_32777, &StudentManagerView::OnDelCourseFromCourseList)
	ON_COMMAND(ID_32778, &StudentManagerView::OnEditStudent)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &StudentManagerView::OnNMDblclkStudentList)
	ON_COMMAND(ID_32779, &StudentManagerView::OnEditCourse)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &StudentManagerView::OnNMDblclkCourseList)
	ON_COMMAND(ID_32781, &StudentManagerView::OnSortID)
	ON_COMMAND(ID_32782, &StudentManagerView::OnSortName)
	ON_COMMAND(ID_32784, &StudentManagerView::OnQueryCoursesOfStudent)
	ON_COMMAND(ID_32785, &StudentManagerView::OnQueryStudentsOfCourse)
END_MESSAGE_MAP()


// StudentManagerView 诊断

#ifdef _DEBUG
void StudentManagerView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void StudentManagerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// StudentManagerView 消息处理程序


void StudentManagerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	// TODO:  在此添加专用代码和/或调用基类
	stu_ctrl.ModifyStyle(0, LVS_REPORT);
	stu_ctrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	stu_ctrl.InsertColumn(0, CString("ID"), LVCFMT_LEFT, 100);
	stu_ctrl.InsertColumn(1, CString("name"), LVCFMT_LEFT, 100);
	stu_ctrl.InsertColumn(2, CString("major courses"), LVCFMT_LEFT, 400);


	course_ctrl.ModifyStyle(0, LVS_REPORT);
	course_ctrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	course_ctrl.InsertColumn(0, CString("name"), LVCFMT_LEFT, 200);
	course_ctrl.InsertColumn(1, CString("credit"), LVCFMT_LEFT, 200);

	CStudentManagerDoc* doc = (CStudentManagerDoc*)GetDocument();
	
	vector<SC> stu = doc->student_list;
	vector<Course> course = doc->course_list;

	vector<SC>::iterator sc_it;
	vector<CString>::iterator str_it;
	for (sc_it = stu.begin(); sc_it != stu.end(); ++sc_it)
	{
		CString name = sc_it->getName();
		int id = sc_it->getID();
		CString ID;
		ID.Format(_T("%d"), id);
		CString courses;
		vector<CString> cou = sc_it->getCourse();
		for (str_it = cou.begin(); str_it != cou.end(); ++str_it)
		{
			courses.Append(*str_it);
			courses.Append(_T(" "));
		}
		int row = stu_ctrl.InsertItem(stu_ctrl.GetItemCount(), ID);
		stu_ctrl.SetItemText(row, 1, name);
		stu_ctrl.SetItemText(row, 2, courses);
	}

	vector<Course>::iterator cou_it;
	for (cou_it = course.begin(); cou_it != course.end(); ++cou_it)
	{
		CString name = cou_it->getName();
		int num = cou_it->getCredit();
		CString credit;
		credit.Format(_T("%d"), num);
		int row = course_ctrl.InsertItem(course_ctrl.GetItemCount(), name);
		course_ctrl.SetItemText(row,1, credit);
	}
}


void StudentManagerView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	//ResizeParentToFit();
}


void StudentManagerView::OnAddStudent()
{
	// TODO:  在此添加命令处理程序代码
	CStudentManagerDoc* doc = (CStudentManagerDoc*)GetDocument();
	AddStudentDlg dlg = AddStudentDlg(this);
	if (dlg.DoModal() == IDOK)
	{
		CString name = dlg.name;
		int num = dlg.ID;
		bool flag = doc->addStudent(name, num);
		if (!flag)
		{
			MessageBox(_T("the student has existed"));
			return;
		}

		CString ID;
		ID.Format(_T("%d"), num);
		int row = stu_ctrl.InsertItem(stu_ctrl.GetItemCount(), ID);
		stu_ctrl.SetItemText(row, 1, name);

		doc->SetModifiedFlag(TRUE);
		doc->UpdateAllViews(NULL);
	}
}


void StudentManagerView::OnAddCourse()
{
	// TODO:  在此添加命令处理程序代码
	CStudentManagerDoc* doc = (CStudentManagerDoc*)GetDocument();
	AddCourseDlg dlg = AddCourseDlg(this);
	if (dlg.DoModal() == IDOK)
	{
		CString name = dlg.name;
		int num = dlg.credit;
		bool flag = doc->addCourse(name, num);
		if (!flag)
		{
			MessageBox(_T("the course has existed"));
			return;
		}

		CString credit;
		credit.Format(_T("%d"), num);
		int row = course_ctrl.InsertItem(course_ctrl.GetItemCount(), name);
		course_ctrl.SetItemText(row, 1, credit);

		doc->SetModifiedFlag(TRUE);
		doc->UpdateAllViews(NULL);
	}
}


void StudentManagerView::OnNMRClickStuList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
	if (stu_ctrl.GetSelectedCount() < 0) return;
	CMenu menu, *popMenu;
	menu.LoadMenu(IDR_STU_POPMENU);
	popMenu = menu.GetSubMenu(0);
	CPoint point;
	ClientToScreen(&point);
	GetCursorPos(&point);
	popMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}


void StudentManagerView::OnDelStudent()
{
	// TODO:  在此添加命令处理程序代码
	CStudentManagerDoc* doc = (CStudentManagerDoc*)GetDocument();
	POSITION p = stu_ctrl.GetFirstSelectedItemPosition();
	bool flag = false;
	while (p)
	{
		int row = stu_ctrl.GetNextSelectedItem(p);
		CString ID = stu_ctrl.GetItemText(row, 0);
		stu_ctrl.DeleteItem(row);

		int id = _ttoi(ID);
		doc->delStudent(id);
		flag = true;
		
	}
	if (flag)
	{
		doc->SetModifiedFlag(true);
		doc->UpdateAllViews(NULL);
	}
}


void StudentManagerView::OnJoinCourse()
{
	// TODO:  在此添加命令处理程序代码
	CStudentManagerDoc* doc = (CStudentManagerDoc*)GetDocument();

	POSITION p = stu_ctrl.GetFirstSelectedItemPosition();
	bool flag = false;
	OpDialog dlg = OpDialog(this);
	dlg.text = CString("course name:");
	while (p)
	{
		int row = stu_ctrl.GetNextSelectedItem(p);
		CString ID = stu_ctrl.GetItemText(row, 0);
		if (dlg.DoModal() == IDOK)
		{
			CString course = dlg.content;
			int id = _ttoi(ID);
			bool res = doc->addCourseToStudent(id,course);
			if (!res)
			{
				MessageBox(_T("no such course or the student has choosed the course"));
				return;
			}
			flag = true;
			CString str = stu_ctrl.GetItemText(row, 2);
			str.Append(_T(" "));
			str.Append(course);
			stu_ctrl.SetItemText(row, 2, str);
		}
	}
	if (flag)
	{
		doc->SetModifiedFlag(true);
		doc->UpdateAllViews(NULL);
	}
}


void StudentManagerView::OnDelCourse()
{
	// TODO:  在此添加命令处理程序代码
	CStudentManagerDoc* doc = (CStudentManagerDoc*)GetDocument();

	POSITION p = stu_ctrl.GetFirstSelectedItemPosition();
	bool flag = false;
	OpDialog dlg = OpDialog(this);
	dlg.text = CString("course name:");
	while (p)
	{
		int row = stu_ctrl.GetNextSelectedItem(p);
		CString ID = stu_ctrl.GetItemText(row, 0);
		if (dlg.DoModal() == IDOK)
		{
			CString course = dlg.content;
			int id = _ttoi(ID);
			bool res = doc->delCourseFromStudent(id, course);
			if (!res)
			{
				MessageBox(_T("the student does not major the course"));
				return;
			}
			flag = true;
			vector<CString> l =  doc->CoursesOfStudent(id);
			CString str;
			int size = l.size();
			for (int i = 0; i < size; ++i)
			{
				str.Append(l[i]);
				str.Append(_T(" "));
			}
			stu_ctrl.SetItemText(row, 2, str);
		}
	}
	if (flag)
	{
		doc->SetModifiedFlag(true);
		doc->UpdateAllViews(NULL);
	}
}


void StudentManagerView::OnNMRClickCourseList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
	if (course_ctrl.GetSelectedCount() < 0) return;
	CMenu menu, *popMenu;
	menu.LoadMenu(IDR_STU_POPMENU);
	popMenu = menu.GetSubMenu(1);
	CPoint point;
	ClientToScreen(&point);
	GetCursorPos(&point);
	popMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}


void StudentManagerView::OnDelCourseFromCourseList()
{
	// TODO:  在此添加命令处理程序代码
	CStudentManagerDoc* doc = (CStudentManagerDoc*)GetDocument();

	POSITION p = course_ctrl.GetFirstSelectedItemPosition();
	bool flag = false;

	while (p)
	{
		int row = course_ctrl.GetNextSelectedItem(p);
		CString name = course_ctrl.GetItemText(row, 0);
		course_ctrl.DeleteItem(row);
		doc->delCourse(name);
		flag = true;
	}
	if (flag)
	{
		doc->SetModifiedFlag(true);
		doc->UpdateAllViews(NULL);
	}
}

void StudentManagerView::editStudent(int row)
{
	CStudentManagerDoc* doc = (CStudentManagerDoc*)GetDocument();
	vector<SC>& students = doc->student_list;
	AddStudentDlg dlg = AddStudentDlg(this);
	CString name = stu_ctrl.GetItemText(row, 1);
	CString ID = stu_ctrl.GetItemText(row, 0);
	int id = _ttoi(ID);

	vector<SC>::iterator it = find_if(students.begin(), students.end(), [id](SC s)->bool{
		return s.getID() == id;
	});
	dlg.ID = id;
	dlg.name = name;
	if (dlg.DoModal() == IDOK)
	{
		id = dlg.ID;
		name = dlg.name;
		it->setID(id);
		it->setName(name);
		ID.Format(_T("%d"), id);
		stu_ctrl.SetItemText(row, 0, ID);
		stu_ctrl.SetItemText(row, 1, name);
		doc->SetModifiedFlag(true);
		doc->UpdateAllViews(NULL);
	}
}

void StudentManagerView::editCourse(int row)
{
	CStudentManagerDoc* doc = (CStudentManagerDoc*)GetDocument();
	vector<Course>& courses = doc->course_list;
	AddCourseDlg dlg = AddCourseDlg(this);
	CString name = course_ctrl.GetItemText(row, 0);
	CString Credit = course_ctrl.GetItemText(row, 1);
	int credit = _ttoi(Credit);

	vector<Course>::iterator it = find_if(courses.begin(), courses.end(), [name](Course c)->bool{
		return c.getName() == name;
	});
	dlg.credit = credit;
	dlg.name = name;
	if (dlg.DoModal() == IDOK)
	{
		credit = dlg.credit;
		name = dlg.name;
		it->setCredit(credit);
		it->setName(name);
		Credit.Format(_T("%d"), credit);
		course_ctrl.SetItemText(row, 0, name);
		course_ctrl.SetItemText(row, 1, Credit);
		doc->SetModifiedFlag(true);
		doc->UpdateAllViews(NULL);
	}
}

void StudentManagerView::OnEditStudent()
{
	// TODO:  在此添加命令处理程序代码
	POSITION p = stu_ctrl.GetFirstSelectedItemPosition();
	while (p)
	{
		int row = stu_ctrl.GetNextSelectedItem(p);
		editStudent(row);
	}
}


void StudentManagerView::OnNMDblclkStudentList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
	POSITION p = stu_ctrl.GetFirstSelectedItemPosition();
	while (p)
	{
		int row = stu_ctrl.GetNextSelectedItem(p);
		editStudent(row);
	}
}


void StudentManagerView::OnEditCourse()
{
	// TODO:  在此添加命令处理程序代码
	POSITION p = course_ctrl.GetFirstSelectedItemPosition();
	while (p)
	{
		int row = course_ctrl.GetNextSelectedItem(p);
		editCourse(row);
	}
}


void StudentManagerView::OnNMDblclkCourseList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
	POSITION p = course_ctrl.GetFirstSelectedItemPosition();
	while (p)
	{
		int row = course_ctrl.GetNextSelectedItem(p);
		editCourse(row);
	}
}





void StudentManagerView::OnSortID()
{
	// TODO:  在此添加命令处理程序代码
	CStudentManagerDoc* doc = (CStudentManagerDoc*)GetDocument();
	vector<SC>& students = doc->student_list;
	doc->sortStudent(2);
	stu_ctrl.DeleteAllItems();
	int size = students.size();
	for (int i = 0; i < size; ++i)
	{
		SC s = students[i];
		CString ID, name, courses;
		ID.Format(_T("%d"), s.getID());
		name = s.getName();
		vector<CString> cou = s.getCourse();
		int num = cou.size();
		for (int j = 0; j < num; ++j)
		{
			courses.Append(cou[j]);
			courses.Append(_T(" "));
		}
		int row = stu_ctrl.InsertItem(i, ID);
		stu_ctrl.SetItemText(row, 1, name);
		stu_ctrl.SetItemText(row, 2, courses);
	}
	doc->SetModifiedFlag(true);
	doc->UpdateAllViews(NULL);
}


void StudentManagerView::OnSortName()
{
	// TODO:  在此添加命令处理程序代码
	CStudentManagerDoc* doc = (CStudentManagerDoc*)GetDocument();
	vector<SC>& students = doc->student_list;
	doc->sortStudent(1);
	stu_ctrl.DeleteAllItems();
	int size = students.size();
	for (int i = 0; i < size; ++i)
	{
		SC s = students[i];
		CString ID, name, courses;
		ID.Format(_T("%d"), s.getID());
		name = s.getName();
		vector<CString> cou = s.getCourse();
		int num = cou.size();
		for (int j = 0; j < num; ++j)
		{
			courses.Append(cou[j]);
			courses.Append(_T(" "));
		}
		int row = stu_ctrl.InsertItem(i, ID);
		stu_ctrl.SetItemText(row, 1, name);
		stu_ctrl.SetItemText(row, 2, courses);
	}
	doc->SetModifiedFlag(true);
	doc->UpdateAllViews(NULL);
}


void StudentManagerView::OnQueryCoursesOfStudent()
{
	// TODO:  在此添加命令处理程序代码
	OpDialog dlg = OpDialog(this);
	dlg.text = _T("student ID:");
	if (dlg.DoModal()==IDOK)
	{
		CStudentManagerDoc* doc = (CStudentManagerDoc*)GetDocument();
		CString ID = dlg.content;
		int id = _ttoi(ID);
		vector<CString> l = doc->CoursesOfStudent(id);
		ShowDlg show = ShowDlg(this);
		int size = l.size();
		if (size == 0)
		{
			MessageBox(_T("the student has not majored any courses"));
			return;
		}
		CString content;
		for (int i = 0; i < size; ++i)
		{
			content.Append(l[i]);
			content.Append(_T("\r\n"));
		}
		show.content = content;
		show.DoModal();
	}
}


void StudentManagerView::OnQueryStudentsOfCourse()
{
	// TODO:  在此添加命令处理程序代码
	OpDialog dlg = OpDialog(this);
	dlg.text = _T("Course name:");
	if (dlg.DoModal() == IDOK)
	{
		CStudentManagerDoc* doc = (CStudentManagerDoc*)GetDocument();
		CString name = dlg.content;
		vector<CString> l = doc->StudentsOfCourse(name);
		ShowDlg show = ShowDlg(this);
		int size = l.size();
		if (size == 0)
		{
			MessageBox(_T("no student mojors the course"));
			return;
		}
		CString content;
		for (int i = 0; i < size; ++i)
		{
			content.Append(l[i]);
			content.Append(_T("\r\n"));
		}
		show.content = content;
		show.DoModal();
	}
}
