
// MFC02View.h : CMFC02View ��Ľӿ�
//

#pragma once


class CMFC02View : public CView
{
protected: // �������л�����
	CMFC02View();
	DECLARE_DYNCREATE(CMFC02View)

// ����
public:
	CMFC02Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFC02View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC02View.cpp �еĵ��԰汾
inline CMFC02Doc* CMFC02View::GetDocument() const
   { return reinterpret_cast<CMFC02Doc*>(m_pDocument); }
#endif

