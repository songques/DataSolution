// MFCDLL01.h : MFCDLL01 DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCDLL01App
// �йش���ʵ�ֵ���Ϣ������� MFCDLL01.cpp
//

class CMFCDLL01App : public CWinApp
{
public:
	CMFCDLL01App();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
