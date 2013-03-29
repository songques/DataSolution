#include "stdafx.h"


class CMyFrameWnd:public CFrameWnd
{
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void Menu_Exit();
};

BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_40001,Menu_Exit)
END_MESSAGE_MAP()

int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	AfxMessageBox(L"OnCreate");
	return 0;
}

 void CMyFrameWnd::Menu_Exit()
 {
	 AfxMessageBox(L"Menu_Exit");
	 ::PostQuitMessage(WM_DESTROY);
 }

class CMyApp:public CWinApp
{
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL InitInstance();
	afx_msg void Menu_About();
};
CMyApp cMyApp;

BEGIN_MESSAGE_MAP(CMyApp,CWinApp)
	ON_COMMAND(ID_40002,Menu_About)
END_MESSAGE_MAP()

BOOL CMyApp::InitInstance()
{
	CMyFrameWnd* form01=new CMyFrameWnd();
	form01->Create(
		NULL,
		L"form01",
		WS_OVERLAPPEDWINDOW,
		CFrameWnd::rectDefault,
		NULL,
		MAKEINTRESOURCE(IDR_MENU1));
	form01->ShowWindow(SW_SHOW);
	form01->UpdateWindow();
	m_pMainWnd=form01;

	return TRUE;
}

void CMyApp::Menu_About()
{
	AfxMessageBox(L"abc");
}