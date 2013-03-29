
// MFC02View.h : CMFC02View 类的接口
//

#pragma once


class CMFC02View : public CView
{
protected: // 仅从序列化创建
	CMFC02View();
	DECLARE_DYNCREATE(CMFC02View)

// 特性
public:
	CMFC02Doc* GetDocument() const;

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
	virtual ~CMFC02View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC02View.cpp 中的调试版本
inline CMFC02Doc* CMFC02View::GetDocument() const
   { return reinterpret_cast<CMFC02Doc*>(m_pDocument); }
#endif

