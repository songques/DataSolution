#include <stdio.h>    
#include <stdlib.h>
#include <malloc.h>
f(int** address){ //address ��ŵ���q�ĵ�ַ 
 // ��̬���ڶ��ڴ���������һ��ռ� 



   int* p ;
    p = (int*)malloc(sizeof(int)*3); 
   *p = 3;
   *(p+1) = 4;
   *(p+2) = 5 ; 
   printf("�Ӻ������� ��ַ%#X\n",p); 
   *address  = p; 
   
   // ���Ӻ��������p�ͷŵ���  
   free(p);
} 


 main() 
{  
        
       int* q ; 
        
       f(&q); 


       printf("���������� ��ַ%#X\n",q); 
       printf("*q = %d\n",*(q+0)); 
       printf("*q = %d\n",*(q+1)); // �������ڴ�ӳ��  
       printf("*q = %d\n",*(q+2)); 
        
       
       //��̬�ڴ���� ����Ա�����Լ��ֹ��ľ���һ����������������  
       
       //�ֹ����ͷŵ����ڴ�ռ�  
       
       //��Ҫʹ���Ѿ����յ����ڴ�ռ����������  

        system("pause");    // ����windows��ϵͳ������ �ó�����ִͣ��  ����۲�����ִ�н��  
          
          
}
