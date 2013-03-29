#include <stdio.h>    
#include <stdlib.h>
// 数组是一块连续的内存空间  数组名 就是内存空间的首地址 
// 数组名[i]  ==  *(数组名+i); 
 main() 
{  
            /* char[] arr = new char[20]; 
             char arr[] ; 
             */
             // 创建一个长度为5的int类型的数组  
            int arr[5] ={1,2,3,4,5};
            
            printf("a[0]=%d\n",arr[0]);
             
        
            printf("a[4]=%d\n",arr[4]);
        
             // 逻辑上是错误的代码  数组下标越界  
            // printf("a[5]=%d\n",arr[5]);
            // windows xp   缓冲区越界补丁  
            
            
            // arr是一个什么东西呢?
            printf("arr = %#X\n",arr); 
            
            // 打印 数组的第一个元素的地址 
            printf("arr[0]地址 = %#X\n",&arr[0]); 
            
            // 打印数组中的第二个元素 
            printf("arr[1]=%d\n",arr[1]); 
            printf("arr[1]=%d\n", *(arr+1));
            //问题: arr[i]  *(arr+i)  代表的是同一个变量么? 
            // 代表的是同一块内存空间 指向的是同一个变量  
            
            
            //通过实验 : 数组名表示的 就是这个数组第一个元素 的首地址 
        
               system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
          
          
}
