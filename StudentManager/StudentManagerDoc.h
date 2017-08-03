
// StudentManagerDoc.h : CStudentManagerDoc ��Ľӿ�
//


#pragma once

#include"SC.h"
#include"Course.h"
#include<fstream>
using namespace std;


class CStudentManagerDoc : public CDocument
{
protected: // �������л�����
	CStudentManagerDoc();
	DECLARE_DYNCREATE(CStudentManagerDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CStudentManagerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
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
