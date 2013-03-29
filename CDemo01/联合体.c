#include <stdio.h> 



main( )
 { 

struct date { int year, month, day; } today; 
 
 // 联合体 是定义一块相同的内存空间 存放里面的数据  
union { long i; int k; char ii; } mix; 

// 联合体的作用就是用来表示一组数据类型 数据的数据类型为这一组中的某一种数据类型 
//注意 :   联合体里面的数据内容会相互覆盖 

printf("date:%d\n",sizeof(struct date));  //12 

printf("mix:%d\n",sizeof(mix));  
mix.ii = 'A';
printf("k=%d\n",mix.k);
system("pause");
} 
