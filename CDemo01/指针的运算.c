#include <stdio.h>    
#include <stdlib.h>
 main() 
{  
        int i =3;  //天津的某个路上 盖了一个房子 3 
        int j =5;  // 北京的某个路上 盖了一个方法 5 
        int* p = &i; // p 天津的门牌号 
        int* q = &j; // q 北京的门牌号 
        
       
        // 指针的运算和数组都是紧密关联的 
        char arr[5]={'a','b','c','d','e'};  //一块连续的内存空间 
        
        char* p1 = &arr[2];
        printf("char = %c\n", *(p1-1));
        
        // char 内存中占用 1个字节 
        // int 内存 中占用 4个字节  
        
         int intarr[5]={1,2,3,4,5};  //一块连续的内存空间 
        
        int* q1 = &intarr[2];
        printf("char = %d\n", *(q1-1));
        
        
        
        // 指针的运算 按照 约定好的数据类型   偏移相对应的内存空间的大小  
        
        system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
    
}
