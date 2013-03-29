#include <stdio.h>    
#include <stdlib.h>
// 问 java 中有值传递和引用传递 吗? 他们的区别是什么? 

// 其实在java中只有值传递 , 没有引用传递  

// Person p = new Person();  p里面存放的内容 就是person对象的地址 
 



void swap2(int* p , int* q){ // 传递的形参为 i 和j 变量的地址  
     // *p  代表 i   *q 代表就是 j
     int temp;
     temp = *p;
     *p = *q; 
     *q = temp;
} 


void swap1(int i ,int j){ //  形参 i 和j 跟主函数里面的i和j是两个不同的变量 
           printf("子函数 i 地址%#X\n",&i);
           printf("子函数 j 地址%#X\n",&j);
           int temp;
           temp  = i;
           i = j;
           j = temp;

}
 main() 
{   
           //利用指针 可以在子函数里面修改主函数里面的数据  
    
           int i = 3;
           int j = 5; 
           printf("i=%d\n",i);
           printf("j=%d\n",j);
           printf("主函数 i 地址%#X\n",&i);
           printf("主函数 j 地址%#X\n",&j);
            
           
           /*/交换两个数字
           int temp;
           temp  = i;
           i = j;
           j = temp;
           */
           // swap1(i,j);
           
           swap2(&i,&j); 
           printf("交换后\n"); 
           printf("i=%d\n",i);
           printf("j=%d\n",j);
    
    
            system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
}
