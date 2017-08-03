#include"stdafx.h"
#include"Student.h"

Student::Student()
{
	name = CString();
	id = 0;
}

Student::Student(CString name, int id)
{
	this->name = name;
	this->id = id;
}

int Student::getID()
{
	return id;
}

CString Student::getName()
{
	return name;
}

void Student::setID(int v)
{
	id = v;
}

void Student::setName(CString v)
{
	name = v;
}
