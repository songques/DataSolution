#include <stdio.h> 



main( )
 { 

struct date { int year, month, day; } today; 
 
 // ������ �Ƕ���һ����ͬ���ڴ�ռ� ������������  
union { long i; int k; char ii; } mix; 

// ����������þ���������ʾһ���������� ���ݵ���������Ϊ��һ���е�ĳһ���������� 
//ע�� :   ������������������ݻ��໥���� 

printf("date:%d\n",sizeof(struct date));  //12 

printf("mix:%d\n",sizeof(mix));  
mix.ii = 'A';
printf("k=%d\n",mix.k);
system("pause");
} 
