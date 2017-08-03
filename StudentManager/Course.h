#ifndef COURSE_H
#define COURSE_H


#include"stdafx.h"

class Course
{
private:
	CString name;
	int credit;
public:
	Course();
	Course(CString name, int credit);
	int getCredit();
	CString getName();
	void setName(CString v);
	void setCredit(int v);
};

#endif