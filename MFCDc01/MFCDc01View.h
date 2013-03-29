
// MFCDc01View.h : CMFCDc01View 类的接口
//

#pragma once


class CMFCDc01View : public CView
{
protected: // 仅从序列化创建
	CMFCDc01View();
	DECLARE_DYNCREATE(CMFCDc01View)

// 特性
public:
	CMFCDc01Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCDc01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // MFCDc01View.cpp 中的调试版本
inline CMFCDc01Doc* CMFCDc01View::GetDocument() const
   { return reinterpret_cast<CMFCDc01Doc*>(m_pDocument); }
#endif

