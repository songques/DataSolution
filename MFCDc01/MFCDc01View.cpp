
// MFCDc01View.cpp : CMFCDc01View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CMFCDc01View ����/����

CMFCDc01View::CMFCDc01View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCDc01View::~CMFCDc01View()
{
}

BOOL CMFCDc01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCDc01View ����

void CMFCDc01View::OnDraw(CDC* /*pDC*/)
{
	CMFCDc01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCDc01View ��ӡ


void CMFCDc01View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCDc01View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCDc01View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCDc01View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CMFCDc01View ���

#ifdef _DEBUG
void CMFCDc01View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDc01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDc01Doc* CMFCDc01View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDc01Doc)));
	return (CMFCDc01Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDc01View ��Ϣ�������


void CMFCDc01View::On_MenuCDC()
{
	// TODO: �ڴ���������������
	//AfxMessageBox(L"CDC");
	CDC dc;
	dc.CreateDC(L"DISPLAY",NULL,NULL,NULL);

	dc.Rectangle(50,50,500,500);

	dc.DeleteDC();
}

void CMFCDc01View::On_MenuDcCwindowsdc()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CView::OnPaint()
	dc.FillSolidRect(50,50,100,100,RGB(0,255,0));
}
