
// MFCClistCtrl01Dlg.h : 头文件
//

#pragma once


// CMFCClistCtrl01Dlg 对话框
class CMFCClistCtrl01Dlg : public CDialogEx
{
// 构造
public:
	CMFCClistCtrl01Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCCLISTCTRL01_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

public:
	CComboBox m_ComboBox;
	CListCtrl m_ClistCtrl;
	CImageList m_imgNormal;
	CImageList m_imgSmall;

public:
	void InitListCtrl();
	void ShowList();

	DECLARE_MESSAGE_MAP()
	afx_msg void OnCbnSelchangeCombo();
};
