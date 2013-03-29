#include <stdio.h>    
#include <stdlib.h>
#include <malloc.h>
f(int** address){ //address 存放的是q的地址 
 // 动态的在堆内存里面申请一块空间 



   int* p ;
    p = (int*)malloc(sizeof(int)*3); 
   *p = 3;
   *(p+1) = 4;
   *(p+2) = 5 ; 
   printf("子函数里面 地址%#X\n",p); 
   *address  = p; 
   
   // 在子函数里面把p释放掉了  
   free(p);
} 


 main() 
{  
        
       int* q ; 
        
       f(&q); 


       printf("主函数里面 地址%#X\n",q); 
       printf("*q = %d\n",*(q+0)); 
       printf("*q = %d\n",*(q+1)); // 残留的内存映像  
       printf("*q = %d\n",*(q+2)); 
        
       
       //动态内存分配 程序员可以自己手工的决定一个变量的生命周期  
       
       //手工的释放调用内存空间  
       
       //不要使用已经回收掉的内存空间里面的数据  

        system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
          
          
}
