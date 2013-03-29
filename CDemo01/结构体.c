#include <stdio.h>    
#include <stdlib.h>

struct Student
{
	int age; //4
	float score; // 4/
	long id;  //4
	char sex ; //2   vc 6.0 14
};
 main() 
{ 
    struct Student st={80,55.6f,100010 ,'F'};   
    
    struct Student* pst;
    pst = &st;
      
    printf("age = %d\n",st.age);    
    printf("score = %f\n",st.score);     
    printf("id = %ld\n",st.id);    
     printf("sex = %c\n",st.sex);    
    // 结构体的长度 
    printf("长度 = %d\n",sizeof(st)); 
    
    //printf("age = %d\n", (*pst).age);   
    printf("age = %d\n", pst->age); 
    
    system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
          
          
}
