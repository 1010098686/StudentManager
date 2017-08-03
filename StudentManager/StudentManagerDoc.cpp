
// StudentManagerDoc.cpp : CStudentManagerDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "StudentManager.h"
#endif

#include "StudentManagerDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CStudentManagerDoc

IMPLEMENT_DYNCREATE(CStudentManagerDoc, CDocument)

BEGIN_MESSAGE_MAP(CStudentManagerDoc, CDocument)
END_MESSAGE_MAP()


// CStudentManagerDoc 构造/析构

CStudentManagerDoc::CStudentManagerDoc()
{
	// TODO:  在此添加一次性构造代码
	student_list = vector<SC>();
	course_list = vector<Course>();

}

CStudentManagerDoc::~CStudentManagerDoc()
{
}

BOOL CStudentManagerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CStudentManagerDoc 序列化

void CStudentManagerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码	
		int num_stu = student_list.size();
		int num_course = course_list.size();
		ar << num_stu;
		//ar << " ";
		for_each(student_list.begin(), student_list.end(), [&ar](SC s){
			ar << s.getID();
			//ar << " ";
			ar << s.getName();
			//ar << " ";
			vector<CString> l = s.getCourse();
			int size = l.size();
			ar << size;
			//ar << " ";
			for_each(l.begin(), l.end(), [&ar](CString str){
				ar << str;
		//		ar << " ";
			});
		});

		ar << num_course;
		//ar << " ";
		for_each(course_list.begin(), course_list.end(), [&ar](Course c){
			ar << c.getName();
		//	ar << " ";
			ar << c.getCredit();
		//	ar << " ";
		});
		ar.Flush();
	}
	else
	{
		// TODO:  在此添加加载代码
		int num_stu;
		int num_course;
		ar >> num_stu;
		for (int i = 0; i < num_stu; ++i)
		{
			CString name;
			int ID;
			int size;
			ar >> ID;
			ar >> name;
			ar >> size;
			vector<CString> l = vector<CString>();
			for (int j = 0; j < size; ++j)
			{
				CString temp;
				ar >> temp;
				l.push_back(temp);
			}
			SC s = SC(name, ID, l);
			student_list.push_back(s);
		}

		ar >> num_course;
		for (int i = 0; i < num_course; ++i)
		{
			CString name;
			int credit;
			ar >> name;
			ar >> credit;
			Course c = Course(name, credit);
			course_list.push_back(c);
		}
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CStudentManagerDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CStudentManagerDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CStudentManagerDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CStudentManagerDoc 诊断

#ifdef _DEBUG
void CStudentManagerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStudentManagerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CStudentManagerDoc 命令
bool CStudentManagerDoc::addStudent(CString name ,int id)
{
	vector<SC>::iterator it = find_if(student_list.begin(), student_list.end(), [id](SC s)->bool{
		return s.getID() == id;
	});
	if (it != student_list.end()) return false;
	SC stu = SC(name, id);
	student_list.push_back(stu);
	return true;
}

void CStudentManagerDoc::delStudent(int id)
{
	vector<SC>::iterator it = find_if(student_list.begin(), student_list.end(), [id](SC s)->bool{
		return s.getID() == id;
	});
	if (it != student_list.end()) student_list.erase(it);
}

void CStudentManagerDoc::sortStudent(int mode)
{
	if (mode == 1) // sort by name
	{
		sort(student_list.begin(), student_list.end(), [](SC a, SC b)->bool{
			return a.getID() > b.getID();
		});
	}
	else if (mode == 2)
	{
		sort(student_list.begin(), student_list.end(), [](SC a, SC b)->bool{
			return a.getName() > b.getName();
		});
	}
}

bool CStudentManagerDoc::addCourse(CString name, int credit)
{
	
	vector<Course>::iterator it = find_if(course_list.begin(), course_list.end(), [name](Course c)->bool{
		return c.getName() == name;
	});
	if (it != course_list.end()) return false;
	Course c = Course(name, credit);
	course_list.push_back(c);
	return true;
}

void CStudentManagerDoc::delCourse(CString name)
{
	vector<Course>::iterator it = find_if(course_list.begin(), course_list.end(), [name](Course c)->bool{
		return c.getName() == name;
	});
	if (it != course_list.end()) course_list.erase(it);
}

bool CStudentManagerDoc::addCourseToStudent(int id, CString course)
{
	vector<SC>::iterator it = find_if(student_list.begin(), student_list.end(), [id](SC stu)->bool{
		return stu.getID() == id;
	});
	if (it != student_list.end())
	{
		return it->JoinCourse(course, course_list);
	}
	else return false;
}

bool CStudentManagerDoc::delCourseFromStudent(int id, CString course)
{
	vector<SC>::iterator it = find_if(student_list.begin(), student_list.end(), [id](SC stu)->bool{
		return stu.getID() == id;
	});
	if (it != student_list.end())
	{
		return it->QuitCourse(course);
	}
	else return false;
}

vector<CString> CStudentManagerDoc::CoursesOfStudent(int id)
{
	vector<SC>::iterator it = find_if(student_list.begin(), student_list.end(), [id](SC s)->bool{
		return s.getID() == id;
	});
	if (it != student_list.end())
	{
		return it->getCourse();
	}
	else
	{
		vector<CString> res = vector<CString>();
		return res;
	}
}

vector<CString> CStudentManagerDoc::StudentsOfCourse(CString course)
{
	vector<CString> res = vector<CString>();
	for_each(student_list.begin(), student_list.end(), [course, &res](SC stu){
		vector<CString> courses = stu.getCourse();
		vector<CString>::iterator it = find_if(courses.begin(), courses.end(), [course](CString str)->bool{
			return str == course;
		});
		if (it != courses.end()) res.push_back(stu.getName());
	});
	return res;
}