#include <stdio.h>    
#include <stdlib.h>

 main() 
{ 
        
    int i = 5; 
    int*  p = &i;  
    int** q = &p;
    int*** r = &q;
    
    
  printf("i=%d\n",***r); 
        
        
        
 system("pause");    // ����windows��ϵͳ������ �ó�����ִͣ��  ����۲�����ִ�н��  
          
          
}
