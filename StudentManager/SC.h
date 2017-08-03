#ifndef SC_H
#define SC_H


#include"stdafx.h"
#include"Student.h"
#include"Course.h"
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class SC :public Student
{
private:
	vector<CString> courses;
public:
	SC();
	SC(CString name, int id);
	SC(CString name, int id, vector<CString> l);
	bool JoinCourse(CString course,vector<Course> course_list);
	bool QuitCourse(CString course);
	vector<CString> getCourse();
};

#endif