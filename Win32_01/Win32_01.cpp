#include <windows.h>
#include <stdio.h>

HINSTANCE hMain_HInstance;

BOOL RegisterWnd(const TCHAR lpszClassName[],WNDPROC WndProcWnd);
HWND CreateWnd(const TCHAR szClassName[],const TCHAR textName[]);
VOID DisplayWnd(HWND hWnd);
VOID MessageWnd();
VOID OnCreate (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	hMain_HInstance=hInstance;

	const TCHAR hClassName[]=TEXT("MainWnd");
	const TCHAR hTextName[]=TEXT("form01");

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
		WS_EX_OVERLAPPEDWINDOW, 
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
		break;
	}
    return DefWindowProc (hwnd, message, wParam, lParam);
}

VOID OnCreate (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HMENU hMainMenu=CreateMenu();
	AppendMenu(hMainMenu,MF_STRING,10001,TEXT("文件"));
}