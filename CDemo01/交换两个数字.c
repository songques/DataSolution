#include <stdio.h>    
#include <stdlib.h>
// �� java ����ֵ���ݺ����ô��� ��? ���ǵ�������ʲô? 

// ��ʵ��java��ֻ��ֵ���� , û�����ô���  

// Person p = new Person();  p�����ŵ����� ����person����ĵ�ַ 
 



void swap2(int* p , int* q){ // ���ݵ��β�Ϊ i ��j �����ĵ�ַ  
     // *p  ���� i   *q ������� j
     int temp;
     temp = *p;
     *p = *q; 
     *q = temp;
} 


void swap1(int i ,int j){ //  �β� i ��j �������������i��j��������ͬ�ı��� 
           printf("�Ӻ��� i ��ַ%#X\n",&i);
           printf("�Ӻ��� j ��ַ%#X\n",&j);
           int temp;
           temp  = i;
           i = j;
           j = temp;

}
 main() 
{   
           //����ָ�� �������Ӻ��������޸����������������  
    
           int i = 3;
           int j = 5; 
           printf("i=%d\n",i);
           printf("j=%d\n",j);
           printf("������ i ��ַ%#X\n",&i);
           printf("������ j ��ַ%#X\n",&j);
            
           
           /*/������������
           int temp;
           temp  = i;
           i = j;
           j = temp;
           */
           // swap1(i,j);
           
           swap2(&i,&j); 
           printf("������\n"); 
           printf("i=%d\n",i);
           printf("j=%d\n",j);
    
    
            system("pause");    // ����windows��ϵͳ������ �ó�����ִͣ��  ����۲�����ִ�н��  
}
