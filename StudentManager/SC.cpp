#include"stdafx.h"
#include"SC.h"

SC::SC() :Student()
{

}

SC::SC(CString name, int id) : Student(name, id)
{
	courses = vector<CString>();
}

SC::SC(CString name, int id, vector<CString> l) : Student(name, id)
{
	courses = l;
}

bool SC::JoinCourse(CString course,vector<Course> course_list)
{
	vector<Course>::iterator it = find_if(course_list.begin(), course_list.end(), [course](Course c)->bool{
		return c.getName() == course;
	});
	if (it == course_list.end()) return false;
	vector<CString>::iterator cit = find_if(courses.begin(), courses.end(), [course](CString c)->bool{
		return c == course;
	});
	if (cit != courses.end()) return false;
	courses.push_back(course);
	return true;
}

bool SC::QuitCourse(CString course)
{
	vector<CString>::iterator it = find_if(courses.begin(), courses.end(), [course](CString str)->bool{
		return str == course;
	});
	if (it == courses.end()) return false;
	courses.erase(it);
	return true;
}

vector<CString> SC::getCourse()
{
	return courses;
}