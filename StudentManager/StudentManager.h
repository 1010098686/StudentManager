
// StudentManager.h : StudentManager Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CStudentManagerApp:
// �йش����ʵ�֣������ StudentManager.cpp
//

class CStudentManagerApp : public CWinApp
{
public:
	CStudentManagerApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CStudentManagerApp theApp;
