#include <stdio.h>    
#include <stdlib.h>
#include <malloc.h> 
// malloc memory allocate �ڴ����� 
 main() 
{  
   // ����һ������ ������(byte)���ڴ�ռ�  
  int* p = (int*)malloc(sizeof(int)); // �ڶ��ڴ���������һ����Դ��һ��int�������ݵ��ڴ�ռ�  
    
  *p = 4;  // ������ p �����ŵĵ�ַ ��ʾ���ǿ��ڴ�ռ�������һ��int���͵����� 4 
  
  
  
  printf("*p=%d\n",*p);  
        
        
	system("pause");    // ����windows��ϵͳ������ �ó�����ִͣ��  ����۲�����ִ�н��  
    
}
