#include <stdio.h>    
#include <stdlib.h>
f(int** q){
    int i = 3; 
    printf("子函数 i的地址 %#X\n",&i); 
    // *q   代表的就是p变量  
    *q = &i; 
} 
/**
   使用指针的时候 不可以访问已经被系统回收掉的数据  
   子函数执行完毕后 子函数里面所有的局部变量都会别系统回收  
*/

 main() 
{  
        
        
        
        // 希望在主函数里面去使用子函数里面的变量 i 
        
        // f(); 
        
        // 希望在主函数里面得到子函数 里面int i变量的地址 
        
        int* p ; //存放子函数f中 int i的地址的一个变量
        
         
        f(&p); 
         
       // printf("主函数 i的地址 %#X\n",p); 
        
       // printf("i的值为 %d\n",*p); 
        
       system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
          
          
}
