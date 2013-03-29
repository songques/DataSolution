
// MFC02View.cpp : CMFC02View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC02.h"
#endif

#include "MFC02Doc.h"
#include "MFC02View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC02View

IMPLEMENT_DYNCREATE(CMFC02View, CView)

BEGIN_MESSAGE_MAP(CMFC02View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC02View ����/����

CMFC02View::CMFC02View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC02View::~CMFC02View()
{
}

BOOL CMFC02View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC02View ����

void CMFC02View::OnDraw(CDC* /*pDC*/)
{
	CMFC02Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC02View ��ӡ

BOOL CMFC02View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC02View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC02View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC02View ���

#ifdef _DEBUG
void CMFC02View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC02View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC02Doc* CMFC02View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC02Doc)));
	return (CMFC02Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC02View ��Ϣ�������
