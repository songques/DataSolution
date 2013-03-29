#include "stdafx.h"


class CMyFrameWnd:public CFrameWnd
{
public:
	CToolBar ctb;

public:
	afx_msg void Menu_Exit();
	afx_msg void Menu_About();
	afx_msg void Bar_Exit();
	afx_msg void Bar_About();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_COMMAND(ID_40001,Menu_Exit)
	ON_COMMAND(ID_40002,Menu_About)

	ON_COMMAND(ID_BUTTON40003,Bar_Exit)
	ON_COMMAND(ID_BUTTON40007,Bar_About)
	ON_WM_CREATE()

END_MESSAGE_MAP()


void CMyFrameWnd::Menu_Exit()
{
	//AfxMessageBox(L"Menu_Exit");
	PostQuitMessage(0);
}
void CMyFrameWnd::Menu_About()
{
	AfxMessageBox(L"Menu_About");
}

void CMyFrameWnd::Bar_Exit()
{
	//AfxMessageBox(L"Menu_Exit");
	PostQuitMessage(0);
}
void CMyFrameWnd::Bar_About()
{
	AfxMessageBox(L"Bar_About");
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	//AfxMessageBox(L"OnCreate");
	ctb.Create(this);
	ctb.LoadToolBar(MAKEINTRESOURCE(IDR_TOOLBAR1));
	return 0;
}


class CMyApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};

CMyApp cMyApp;

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