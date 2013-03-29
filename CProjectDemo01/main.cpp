#include <iostream>
#include <Windows.h>
using namespace std;


char* StringValue(char *p,char *b);

void main()
{
	cout<<"endl"<<endl;

	char *s=StringValue("a","b");
	cout<<s<<endl;


	LPTSTR str1="南非人民共和国";
	LPTSTR str2="中华人民共和国";
	
	LPTSTR str3=new TCHAR[lstrlen(str1)+lstrlen(str2)+1];
	lstrcpy(str3,str1);
	lstrcat(str3,str2);;

	cout<<str3<<endl;


	system("pause");
}

char* StringValue(char *p,char *b)
{
	char *zz = (char*)malloc(strlen(p)+strlen(b)+1);
	strcpy(zz, p);
	strcat(zz,b);
	return zz;
}