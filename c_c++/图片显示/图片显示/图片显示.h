
// ͼƬ��ʾ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CͼƬ��ʾApp:
// �йش����ʵ�֣������ ͼƬ��ʾ.cpp
//

class CͼƬ��ʾApp : public CWinApp
{
public:
	CͼƬ��ʾApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CͼƬ��ʾApp theApp;