
// MFCClistCtrl01Dlg.h : ͷ�ļ�
//

#pragma once


// CMFCClistCtrl01Dlg �Ի���
class CMFCClistCtrl01Dlg : public CDialogEx
{
// ����
public:
	CMFCClistCtrl01Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCCLISTCTRL01_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;
	// ���ɵ���Ϣӳ�亯��
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
