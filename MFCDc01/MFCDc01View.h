
// MFCDc01View.h : CMFCDc01View ��Ľӿ�
//

#pragma once


class CMFCDc01View : public CView
{
protected: // �������л�����
	CMFCDc01View();
	DECLARE_DYNCREATE(CMFCDc01View)

// ����
public:
	CMFCDc01Doc* GetDocument() const;

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
	virtual ~CMFCDc01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On_MenuCDC();
	afx_msg void On_MenuDcCwindowsdc();
	afx_msg void On_DcCclientdc();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFCDc01View.cpp �еĵ��԰汾
inline CMFCDc01Doc* CMFCDc01View::GetDocument() const
   { return reinterpret_cast<CMFCDc01Doc*>(m_pDocument); }
#endif

