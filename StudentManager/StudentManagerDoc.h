
// StudentManagerDoc.h : CStudentManagerDoc 类的接口
//


#pragma once

#include"SC.h"
#include"Course.h"
#include<fstream>
using namespace std;


class CStudentManagerDoc : public CDocument
{
protected: // 仅从序列化创建
	CStudentManagerDoc();
	DECLARE_DYNCREATE(CStudentManagerDoc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CStudentManagerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

public:
	vector<SC> student_list;
	vector<Course> course_list;
public:
	bool addStudent(CString name,int id);
	void sortStudent(int mode);
	void delStudent(int id);

	bool addCourse(CString name,int credit);
	void delCourse(CString name);

	bool addCourseToStudent(int id,CString course);
	bool delCourseFromStudent(int id, CString course);
	vector<CString> CoursesOfStudent(int id);
	vector<CString> StudentsOfCourse(CString course);
};
