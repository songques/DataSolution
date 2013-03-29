
// MFCClistCtrl01Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCClistCtrl01.h"
#include "MFCClistCtrl01Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCClistCtrl01Dlg �Ի���





CMFCClistCtrl01Dlg::CMFCClistCtrl01Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCClistCtrl01Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCClistCtrl01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_COMBO1,m_ComboBox);
	DDX_Control(pDX,IDC_LIST1,m_ClistCtrl);
	
}

BEGIN_MESSAGE_MAP(CMFCClistCtrl01Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCClistCtrl01Dlg::OnCbnSelchangeCombo)
END_MESSAGE_MAP()


// CMFCClistCtrl01Dlg ��Ϣ�������

BOOL CMFCClistCtrl01Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	InitListCtrl();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCClistCtrl01Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCClistCtrl01Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCClistCtrl01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCClistCtrl01Dlg::InitListCtrl()
{
	int i_Icon=m_ComboBox.AddString(L"Icon");
	int i_SmallIcon=m_ComboBox.AddString(L"Small Icon");
	int i_List=m_ComboBox.AddString(L"List");
	int i_Report=m_ComboBox.AddString(L"Report");

	LPCTSTR s_Icon=L"Value:Icon";
	m_ComboBox.SetItemData(i_Icon,(DWORD)s_Icon);
	LPCTSTR s_SmallIcon=L"Value:Small Icon";
	m_ComboBox.SetItemData(i_SmallIcon,(DWORD)s_SmallIcon);
	LPCTSTR s_List=L"Value:List";
	m_ComboBox.SetItemData(i_List,(DWORD)s_List);
	LPCTSTR s_Report=L"Value:Report";
	m_ComboBox.SetItemData(i_Report,(DWORD)s_Report);

	m_ComboBox.SetCurSel(0);

	m_imgNormal.Create(MAKEINTRESOURCE(IDB_NORMAL),32,32,RGB(0,0,0));
	m_imgSmall.Create(MAKEINTRESOURCE(IDB_SMALL),16,16,RGB(0,0,0));
	m_ClistCtrl.SetImageList(&m_imgNormal,LVSIL_NORMAL);
	m_ClistCtrl.SetImageList(&m_imgSmall,LVSIL_SMALL);
	ShowList();
}

void CMFCClistCtrl01Dlg::ShowList()
{
	m_ClistCtrl.InsertColumn(0,L"����",LVCFMT_LEFT,250);
	m_ClistCtrl.InsertColumn(1,L"����",LVCFMT_LEFT,100);
	int n_item=m_ClistCtrl.InsertItem(0,L"A",0);
	m_ClistCtrl.SetItemText(n_item,1,L"100k");
	n_item=m_ClistCtrl.InsertItem(1,L"B",1);
	m_ClistCtrl.SetItemText(n_item,1,L"200k");
}

void CMFCClistCtrl01Dlg::OnCbnSelchangeCombo()
{
	int index=m_ComboBox.GetCurSel();
	DWORD p_object=m_ComboBox.GetItemData(index);

	LPCTSTR szText=(LPCTSTR)p_object;

	//LVS_REPORT,LVS_ICON ,LVS_LIST,LVS_SMALLICON 
	if(StrCmpCW(szText,L"Value:Icon")==0)
	{
		m_ClistCtrl.ModifyStyle(LVS_REPORT|LVS_LIST|LVS_SMALLICON,LVS_ICON);
	}
	else if(StrCmpCW(szText,L"Value:Small Icon")==0)
	{
		m_ClistCtrl.ModifyStyle(LVS_REPORT|LVS_LIST|LVS_ICON,LVS_SMALLICON);
	}
	else if(StrCmpCW(szText,L"Value:List")==0)
	{
		m_ClistCtrl.ModifyStyle(LVS_REPORT|LVS_ICON|LVS_SMALLICON,LVS_LIST);
	}
	else if(StrCmpCW(szText,L"Value:Report")==0)
	{
		m_ClistCtrl.ModifyStyle(LVS_ICON|LVS_LIST|LVS_SMALLICON,LVS_REPORT);
	}

	//AfxMessageBox(szText);
}
