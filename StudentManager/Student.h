#ifndef STUDENT_H
#define STUDENT_H

#include"stdafx.h"

class Student
{
protected:
	CString name;
	int id;
public:
	Student();
	Student(CString name, int id);
	int getID();
	CString getName();
	void setID(int v);
	void setName(CString v);
};

#endif