#include "stdafx.h"


class CMyFrameWnd:public CFrameWnd
{
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void Button01_OnClick();
	afx_msg void Button_OnClick(UINT CmdID);
};

BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(10001,Button01_OnClick)
	ON_COMMAND_RANGE(10002,10006,Button_OnClick)
END_MESSAGE_MAP()

int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CreateWindow(
		L"BUTTON",
		L"Button01",
		WS_CHILD|WS_VISIBLE,
		0,
		0,
		100,
		30,
		GetSafeHwnd(),
		HMENU(10001),
		AfxGetApp()->m_hInstance,
		NULL);

	CreateWindow(
		L"BUTTON",
		L"Button02",
		WS_CHILD|WS_VISIBLE,
		105,
		0,
		100,
		30,
		GetSafeHwnd(),
		HMENU(10002),
		AfxGetApp()->m_hInstance,
		NULL);


	CreateWindow(
		L"BUTTON",
		L"Button03",
		WS_CHILD|WS_VISIBLE,
		210,
		0,
		100,
		30,
		GetSafeHwnd(),
		HMENU(10003),
		AfxGetApp()->m_hInstance,
		NULL);

	CreateWindow(
		L"BUTTON",
		L"Button04",
		WS_CHILD|WS_VISIBLE,
		315,
		0,
		100,
		30,
		GetSafeHwnd(),
		HMENU(10004),
		AfxGetApp()->m_hInstance,
		NULL);

	CreateWindow(
		L"BUTTON",
		L"Button05",
		WS_CHILD|WS_VISIBLE,
		420,
		0,
		100,
		30,
		GetSafeHwnd(),
		HMENU(10005),
		AfxGetApp()->m_hInstance,
		NULL);

	return 0;
}

void CMyFrameWnd::Button01_OnClick()
{
	AfxMessageBox(L"Button01_OnClick");
}

void CMyFrameWnd:: Button_OnClick(UINT CmdID)
{
	TCHAR tszText[260]={0};
	swprintf(tszText,L"%d",CmdID);
	AfxMessageBox(tszText);
}

class CMyApp:public CWinApp
{
public:
	virtual BOOL InitInstance( );
};


CMyApp cMyApp;

BOOL CMyApp::InitInstance( )
{
	//AfxMessageBox(L"abc");

	CMyFrameWnd* form01=new CMyFrameWnd();
	form01->Create(NULL,L"form01");
	form01->ShowWindow(SW_SHOW);
	form01->UpdateWindow();
	m_pMainWnd=form01;
	return TRUE;
}