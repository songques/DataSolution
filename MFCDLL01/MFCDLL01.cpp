// MFCDLL01.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "MFCDLL01.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CMFCDLL01App

BEGIN_MESSAGE_MAP(CMFCDLL01App, CWinApp)
END_MESSAGE_MAP()


// CMFCDLL01App ����

CMFCDLL01App::CMFCDLL01App()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMFCDLL01App ����

CMFCDLL01App theApp;


// CMFCDLL01App ��ʼ��

BOOL CMFCDLL01App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
