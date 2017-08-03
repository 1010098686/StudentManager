#include"stdafx.h"
#include"Course.h"

Course::Course()
{
	name = CString();
	credit = 0;
}

Course::Course(CString name, int credit)
{
	this->name = name;
	this->credit = credit;
}

CString Course::getName()
{
	return name;
}

int Course::getCredit()
{
	return credit;
}

void Course::setName(CString v)
{
	name = v;
}

void Course::setCredit(int v)
{
	credit = v;
}