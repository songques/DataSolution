#include <windows.h>
#include <stdio.h>
#include <tchar.h>

HINSTANCE hMain_HInstance;
HANDLE hStdOut;

BOOL RegisterWnd(const TCHAR lpszClassName[],WNDPROC WndProcWnd);
HWND CreateWnd(const TCHAR szClassName[],const TCHAR textName[]);
VOID DisplayWnd(HWND hWnd);
VOID MessageWnd();
VOID OnCreate (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
VOID OnCommand (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
VOID OnInitMenuPopup (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

void TcharToChar (const TCHAR * tchar, char * _char)   
{   
	int iLength ;   
	//获取字节长度    
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);   
	//将tchar值赋给_char     
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);    
}  

void CharToTchar (const char * _char, TCHAR * tchar)   
{   
	int iLength ;   

	iLength = MultiByteToWideChar (CP_ACP, 0, _char, strlen (_char) + 1, NULL, 0) ;   
	MultiByteToWideChar (CP_ACP, 0, _char, strlen (_char) + 1, tchar, iLength) ;   
}

VOID NewConsole()
{
	AllocConsole();
	hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
}

VOID PrintLog(TCHAR msg[])
{
	WriteConsole(hStdOut,msg,_tcslen(msg),NULL,NULL);
}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	hMain_HInstance=hInstance;

	const TCHAR hClassName[]=TEXT("MainWnd");
	const TCHAR hTextName[]=TEXT("form01");
	NewConsole();
	RegisterWnd(hClassName,WndProc);
	HWND hWnd=CreateWnd(hClassName,hTextName);
	DisplayWnd(hWnd);
	MessageWnd();
	
	return 0;
}

BOOL RegisterWnd(const TCHAR lpszClassName[],WNDPROC WndProcWnd)
{
	WNDCLASSEX   wndclassex = {0};
	wndclassex.cbSize        = sizeof(wndclassex);
	wndclassex.style         = CS_HREDRAW | CS_VREDRAW;
	wndclassex.lpfnWndProc   = WndProcWnd;
	wndclassex.cbClsExtra    = 0;
	wndclassex.cbWndExtra    = 0;
	wndclassex.hInstance     = hMain_HInstance;
	wndclassex.hIcon         = LoadIcon (NULL, IDI_APPLICATION);
	wndclassex.hCursor       = LoadCursor (NULL, IDC_ARROW);
	wndclassex.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH);
	wndclassex.lpszMenuName  = NULL;
	wndclassex.lpszClassName = lpszClassName;
	wndclassex.hIconSm       = wndclassex.hIcon;

	if (!RegisterClassEx(&wndclassex))
	{
		MessageBox(NULL,TEXT("注册窗体类错误！"),TEXT("提示"),MB_OK);
		return FALSE;
	}
	return TRUE;
}

HWND CreateWnd(const TCHAR szClassName[],const TCHAR textName[])
{
	HWND hwnd = CreateWindowEx (
		0, 
		szClassName, 
		textName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		NULL, 
		NULL, 
		hMain_HInstance,
		NULL); 
	return hwnd;
}

VOID DisplayWnd(HWND hWnd)
{
	ShowWindow(hWnd,SW_SHOW);
	UpdateWindow(hWnd);
}

VOID MessageWnd()
{
	MSG msg={0};
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CREATE:
		OnCreate(hwnd,message,wParam,lParam);
	case WM_COMMAND:
		OnCommand(hwnd,message,wParam,lParam);
		break;
	case  WM_INITMENUPOPUP:
		OnInitMenuPopup(hwnd,message,wParam,lParam);
		break;
	}
	return DefWindowProc (hwnd, message, wParam, lParam);
}

VOID OnCreate (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HMENU hMainMenu=CreateMenu();

	HMENU hFilePopoMenu=CreatePopupMenu();
	AppendMenu(hFilePopoMenu,MF_STRING,10001,TEXT("新建(&N)"));
	AppendMenu(hFilePopoMenu,MF_SEPARATOR,NULL,NULL);
	AppendMenu(hFilePopoMenu,MF_STRING,10002,TEXT("退出(&Q)"));

	AppendMenu(hMainMenu,MF_STRING|MF_POPUP,UINT(hFilePopoMenu),TEXT("文件(&F)"));


	HMENU hEditPopoMenu=CreatePopupMenu();
	AppendMenu(hEditPopoMenu,MF_STRING,20001,TEXT("剪切(&T)"));
	AppendMenu(hEditPopoMenu,MF_STRING,20002,TEXT("复制(&C)"));
	AppendMenu(hMainMenu,MF_STRING|MF_POPUP,UINT(hEditPopoMenu),TEXT("编辑(&E)"));

	HMENU hHelpPopoMenu=CreatePopupMenu();
	AppendMenu(hHelpPopoMenu,MF_CHECKED,30001,TEXT("关于(&H)"));
	AppendMenu(hMainMenu,MF_STRING|MF_POPUP,UINT(hHelpPopoMenu),TEXT("帮助(&H)"));

	SetMenu(hwnd,hMainMenu);
}

VOID OnCommand (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int mID=LOWORD(wParam);
	TCHAR mText[260]={0};
	wsprintf(mText,TEXT("%d\n"),LOWORD(wParam));
	PrintLog(mText);
	switch(mID)
	{
	case 10001:
		{
			HMENU hMenu=GetMenu(hwnd);
			CheckMenuItem(hMenu,30001,MF_UNCHECKED|MF_BYCOMMAND);
		}
		break;
	case 10002:
		PostQuitMessage(0);
		break;

	}
}

VOID OnInitMenuPopup (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	TCHAR msg[260]={0};
	wsprintf(msg,TEXT("hwnd:%d message:%d wParam:%08X lParam:%08X\n"),hwnd,message,wParam,lParam);
	PrintLog(msg);

	//HMENU hMenu=HMENU(wParam);
	//CheckMenuItem(hMenu,30001,MF_DEFAULT|MF_BYCOMMAND);
}