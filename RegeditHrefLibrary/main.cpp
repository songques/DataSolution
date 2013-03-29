#include "windows.h"
#include "stdio.h"

const int error_value = -1;

BOOL WINAPI DllMain( HINSTANCE hinstDLL,
	DWORD fdwReason, LPVOID lpvReserved )
{
	printf( "DLL=%p, Reason=", hinstDLL );
	switch( fdwReason )
	{
	case DLL_PROCESS_ATTACH:
		printf( "DLL_PROCESS_ATTACH\n" );
		break;
	case DLL_THREAD_ATTACH:
		printf( "DLL_THREAD_ATTACH\n" );
		break;
	case DLL_THREAD_DETACH:
		printf( "DLL_THREAD_DETACH\n" );
		break;
	case DLL_PROCESS_DETACH:
		printf( "DLL_PROCESS_DETACH\n" );
		break;
	}
	return TRUE;
}

//C++导出方式
__declspec(dllexport) int Dll_Add( int nAdd1, int nAdd2 )
{
	return ( nAdd1 + nAdd2 );
}
//C的导出方式
extern "C" __declspec(dllexport) int Dll_Sub( int nSub1, int nSub2 )
{
	return ( nSub1 - nSub2 );
}
//DEF的导出方式
int Dll_Mul( int nMul1, int nMul2 )
{
	return ( nMul1 * nMul2 );
}

int RegeditHrefValue(LPCSTR str1,LPCSTR str2,_Out_  LPSTR lpString)
{
	lpString=new TCHAR[lstrlen(str1)+lstrlen(str2)+1];
	lstrcpy(lpString,str1);
	lstrcat(lpString,str2);
	printf("lpString：%s",lpString);
	return 0;
}

int Regsvr32Href(LPCSTR pPath)
{
	int reslut=-1;

	if(!pPath)
		return error_value;

		
	HKEY hKey;
	DWORD dwDisp=REG_CREATED_NEW_KEY;
	//(LPDWORD)REG_CREATED_NEW_KEY);

	LONG nRet=RegCreateKeyEx(
		HKEY_CLASSES_ROOT, 
		pPath,
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS,
		NULL,
		&hKey,
		&dwDisp);

	if(nRet!=ERROR_SUCCESS)
	{
		int xx=GetLastError();
		printf( "创建注册表失败:%d\n",xx );
		return error_value;
	}

	RegCloseKey(hKey);
	return 0;

}