#include <iostream>
using namespace std;

char* StringValue(char *p,char *b);

int main()
{
	char *name="�л����񹲺͹�";

	char cname;

	cin>>cname;

	cout<<cname<<endl;

	char* s=StringValue("","");
	cout<<s<<endl;
	system("pause");
} 

char* StringValue(char *p,char *b)
{
	char* s=strcat(p,b);
	return s;

}