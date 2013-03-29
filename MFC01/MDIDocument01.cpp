#include "stdafx.h"


class CMyMDIChildWnd:public CMDIChildWnd
{
public:
	DECLARE_DYNCREATE(CMyMDIChildWnd)
};
IMPLEMENT_DYNCREATE(CMyMDIChildWnd,CMDIChildWnd)

class CMyDocument:public CDocument
{
public:
	CString m_strText;
public:
	DECLARE_DYNCREATE(CMyDocument)
};
IMPLEMENT_DYNCREATE(CMyDocument,CDocument)


class CMyEditView:public CEditView
{
public:
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);

public:
	afx_msg BOOL OnEnChange();

DECLARE_DYNCREATE(CMyEditView)
DECLARE_MESSAGE_MAP()

};
IMPLEMENT_DYNCREATE(CMyEditView,CEditView)
BEGIN_MESSAGE_MAP(CMyEditView,CEditView)
	ON_CONTROL_REFLECT_EX(EN_CHANGE,OnEnChange)
END_MESSAGE_MAP()

BOOL CMyEditView::OnEnChange()
{

	CMyDocument* pDoc=dynamic_cast<CMyDocument*>(GetDocument());
	GetWindowText(pDoc->m_strText);
	pDoc->UpdateAllViews(this);
	return TRUE;
}

void CMyEditView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	CMyDocument* pDoc=dynamic_cast<CMyDocument*>(GetDocument());
	SetWindowText(pDoc->m_strText);
}

class CMyMDIFrameWnd:public CMDIFrameWnd
{
public:
	afx_msg void Menu_Create_Window();
DECLARE_MESSAGE_MAP()
//ID_40013
};

BEGIN_MESSAGE_MAP(CMyMDIFrameWnd,CMDIFrameWnd)
	ON_COMMAND(ID_40013,Menu_Create_Window)
END_MESSAGE_MAP()
void CMyMDIFrameWnd::Menu_Create_Window()
{
	CFrameWnd* p_cWnd=dynamic_cast<CFrameWnd*>(GetActiveFrame());
	
	if (FALSE==p_cWnd->IsKindOf(RUNTIME_CLASS(CMDIChildWnd)))
	{
		AfxMessageBox(L"CMDIFrameWnd");
		return;
	}

	CMyMDIChildWnd* p_chileWnd=dynamic_cast<CMyMDIChildWnd* >(p_cWnd);
	
	CMyEditView* p_cView=dynamic_cast<CMyEditView*>(p_chileWnd->GetActiveView());

	CMyDocument* p_cDoc=dynamic_cast<CMyDocument* >(p_chileWnd->GetActiveDocument());

	CWinApp* pWndApp=AfxGetApp();
	POSITION pos=pWndApp->m_pDocManager->GetFirstDocTemplatePosition();

	CDocTemplate* pDocTemplate=pWndApp->m_pDocManager->GetNextDocTemplate(pos);

	CMyMDIChildWnd* c_pCWnd=(CMyMDIChildWnd*)pDocTemplate->CreateNewFrame(p_cDoc,NULL);
	//c_pCWnd->ShowWindow(SW_SHOW);
	pDocTemplate->InitialUpdateFrame(c_pCWnd,p_cDoc);

}

class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();

public:
	afx_msg void Menu_Create();

DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CMyWinApp,CWinApp)
	ON_COMMAND(ID_40008,Menu_Create)
END_MESSAGE_MAP()

void CMyWinApp::Menu_Create()
{
	OnFileNew();
}


CMyWinApp cMyWinApp;


BOOL CMyWinApp::InitInstance()
{

	CMultiDocTemplate* cmt=new CMultiDocTemplate(
		IDR_MDIDocument01_Menu01,
		RUNTIME_CLASS(CMyDocument),
		RUNTIME_CLASS(CMyMDIChildWnd),
		RUNTIME_CLASS(CMyEditView));
	AddDocTemplate(cmt);
	
	CMyMDIFrameWnd* form01=new CMyMDIFrameWnd();
	form01->LoadFrame(IDR_MDIDocument01_Menu01);
	form01->ModifyStyleEx(WS_EX_CLIENTEDGE,0);
	m_pMainWnd=form01;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}
