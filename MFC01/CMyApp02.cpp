#include "stdafx.h"


class CMyFrameWnd:public CFrameWnd
{
	DECLARE_MESSAGE_MAP();
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void Button_OnClick(UINT CmdID);
	afx_msg void Edit01_OnChange();
};

BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND_RANGE(10001,10005,Button_OnClick)
	ON_EN_CHANGE(10006,Edit01_OnChange)
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

	CreateWindow(
		L"EDIT",
		L"",
		WS_CHILD|WS_VISIBLE|WS_BORDER,
		525,
		0,
		100,
		30,
		GetSafeHwnd(),
		HMENU(10006),
		AfxGetApp()->m_hInstance,
		NULL);

	return 0;
}

void CMyFrameWnd::Button_OnClick(UINT CmdID)
{
	CString str;
	str.Format(L"%d",CmdID);
	AfxMessageBox(str);
}

void CMyFrameWnd::Edit01_OnChange()
{
	//AfxMessageBox(L"Edit01_OnChange");
	CWnd* pWnd=GetDlgItem(10006);
	CString str;
	pWnd->GetWindowTextW(str);
	AfxMessageBox(str);
	pWnd->SetFocus();
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