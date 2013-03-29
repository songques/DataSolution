
// MFCDc01View.cpp : CMFCDc01View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCDc01.h"
#endif

#include "MFCDc01Doc.h"
#include "MFCDc01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDc01View

IMPLEMENT_DYNCREATE(CMFCDc01View, CView)

BEGIN_MESSAGE_MAP(CMFCDc01View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCDc01View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CMFCDc01View::On_MenuCDC)
	ON_COMMAND(ID_DC_CWINDOWSDC, &CMFCDc01View::On_MenuDcCwindowsdc)
	ON_COMMAND(ID_DC_CCLIENTDC, &CMFCDc01View::On_DcCclientdc)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFCDc01View 构造/析构

CMFCDc01View::CMFCDc01View()
{
	// TODO: 在此处添加构造代码

}

CMFCDc01View::~CMFCDc01View()
{
}

BOOL CMFCDc01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCDc01View 绘制

void CMFCDc01View::OnDraw(CDC* /*pDC*/)
{
	CMFCDc01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCDc01View 打印


void CMFCDc01View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCDc01View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCDc01View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCDc01View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCDc01View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCDc01View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCDc01View 诊断

#ifdef _DEBUG
void CMFCDc01View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDc01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDc01Doc* CMFCDc01View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDc01Doc)));
	return (CMFCDc01Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDc01View 消息处理程序


void CMFCDc01View::On_MenuCDC()
{
	// TODO: 在此添加命令处理程序代码
	//AfxMessageBox(L"CDC");
	CDC dc;
	dc.CreateDC(L"DISPLAY",NULL,NULL,NULL);

	dc.Rectangle(50,50,500,500);

	dc.DeleteDC();
}

void CMFCDc01View::On_MenuDcCwindowsdc()
{
	// TODO: 在此添加命令处理程序代码
	//AfxMessageBox(L"On_MenuDcCwindowsdc");

	CWindowDC dc(this);
	dc.Rectangle(50,50,500,500);
}


void CMFCDc01View::On_DcCclientdc()
{
	//CClientDC dc(this);
	//dc.Rectangle(50,50,500,500);

	CDC* dc1=GetDC();
	dc1->Rectangle(50,50,500,500);
	ReleaseDC(dc1);

}


void CMFCDc01View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CView::OnPaint()
	dc.FillSolidRect(50,50,100,100,RGB(0,255,0));
}
