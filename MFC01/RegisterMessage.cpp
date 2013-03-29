#include "stdafx.h"

UINT g_nRgeMsg=RegisterWindowMessage(L"MYREGEMSG");

class CMyFrameWnd:public CFrameWnd
{
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void Button01_OnClick();
	afx_msg LRESULT OnRegMsg(WPARAM wParam, LPARAM lParam);
};

BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(10001,Button01_OnClick)
	ON_REGISTERED_MESSAGE(g_nRgeMsg,OnRegMsg)
END_MESSAGE_MAP()

int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	/*if(!CFrameWnd::OnCreate(lpCreateStruct))
	{
		return 0;
	}*/

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

	return 1;
	
}

void CMyFrameWnd::Button01_OnClick()
{
	//AfxMessageBox(L"Button01_OnClick");
	//SendMessage(g_nRgeMsg,0,0);
	::SendMessage(GetSafeHwnd(),g_nRgeMsg,0,0);
}

LRESULT CMyFrameWnd::OnRegMsg(WPARAM wParam, LPARAM lParam)
{
	AfxMessageBox(L"OnRegMsg");
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
	form01->Create(NULL,L"form01");
	form01->ShowWindow(SW_SHOW);
	form01->UpdateWindow();
	m_pMainWnd=form01;
	return TRUE;
}