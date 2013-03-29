#include <stdio.h>    
#include <stdlib.h>

 main() 
{ 
        
    int i = 5; 
    int*  p = &i;  
    int** q = &p;
    int*** r = &q;
    
    
  printf("i=%d\n",***r); 
        
        
        
 system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
          
          
}
