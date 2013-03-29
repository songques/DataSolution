
// MFCClistCtrl01Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCClistCtrl01.h"
#include "MFCClistCtrl01Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCClistCtrl01Dlg 对话框





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


// CMFCClistCtrl01Dlg 消息处理程序

BOOL CMFCClistCtrl01Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	InitListCtrl();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCClistCtrl01Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
	m_ClistCtrl.InsertColumn(0,L"名称",LVCFMT_LEFT,250);
	m_ClistCtrl.InsertColumn(1,L"长度",LVCFMT_LEFT,100);
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
