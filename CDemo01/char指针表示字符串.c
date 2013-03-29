#include <stdio.h>    
#include <stdlib.h>
 main() 
{  
    char arr[20] ={'h','e','l','l','o','\0'};    
    
    // 利用char类型指针 方便的表示一个字符串  
    char* arr1= "hello world";
        
    printf("%s",arr1);    
        
    system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
          
          
}
