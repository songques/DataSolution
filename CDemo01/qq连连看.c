
#include <stdio.h>    
#include <stdlib.h>
 main() 
{       
        // 所有的变量都会分配一块内存空间
        
        // 指针就是用来表示一块内存空间的地址的  
        
        // 地址可以用过 &这个符号获取到某个变量的在内存中的地址 
        
        // 这个地址如果想把他存放起来 就需要有一个变量 去存放这个地址
        
        //  存放内存地址的变量 就是指针变量  
        
        
        // 指针和指针变量 
        // 指针是用来表示一块内存地址的,
        // 指针变量是用来存放一个内存地址的 .
        
        //  
        printf("ready go! 剩余时间60秒\n");
         
         int time = 60;
         printf("time变量对应的内存地址为%#X\n", &time); 
         
          for(;time>0;time--){
                        
                  
                      
                 printf("剩余时间%d\n",time); 
                
                
                 sleep(4000);     
      }                 
       printf("游戏结束");
     
        system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
}
