/*1.����int��(*pf)(int x,��int y);
2.��ֵ pf = add;
3.���� pf(3,5);
*/
#include <stdio.h>    
#include <stdlib.h>

int add(int x , int y)
{
    return x+y;
}

void add1(int x , int y)
{
	printf("x=%d  y=%d\n",x,y);
}

 main() 
{ 
      
       //int (*pf) (int x, int y); //����һ��������ָ������� ���ֽ�pf  ����ֵ int ���ܲ�������int  

	   void (*pf1) (int x1, int y1);
	   int (*pf) (int x, int y);

	   pf=add;
	   pf1 = add1;

	   pf1(6,7);
       printf("result=%d\n", pf(3,6)); 
      
       system("pause");    // ����windows��ϵͳ������ �ó�����ִͣ��  ����۲�����ִ�н��  
          
          
}
