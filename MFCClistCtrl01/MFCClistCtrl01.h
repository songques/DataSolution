
// MFCClistCtrl01.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCClistCtrl01App:
// �йش����ʵ�֣������ MFCClistCtrl01.cpp
//

class CMFCClistCtrl01App : public CWinApp
{
public:
	CMFCClistCtrl01App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCClistCtrl01App theApp;