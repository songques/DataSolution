#include <stdio.h>    
#include <stdlib.h>
#define pi 3.1415 
// дһ���Ӻ��� ��ӡ���������ÿһ��Ԫ�� 

void printArr(int* arr, int len){ // arr��������׵�ַ  len����ĳ���  
     int i=0;
     for(;i<len;i++){ // ��c99 ���﷨��ʽ��  forѭ���ĳ�ʼ������ ����д�� for ѭ������������  
        // printf("arr[%d]=%d\n",i,arr[i]);  // arr[i] ��  *(arr+i) ����ĺ�����ͬ 
        printf("arr[%d]=%d\n",i, *(arr+i));
     }
} 

 
main() 
{  
       // int arr[10]={1,2,3,4,5};
        
       // printArr(&arr[0],10);
        //1 .����һ������  ȱ�� ����ĳ��� ������������� 
        //int arr[1000];   //  ��һ�����һ��ִ�� ,�����̻����ڴ��������� 5���ڴ�ռ� ÿ���ڴ�ռ�Ĵ�С���Դ��һ��int���͵�����  
        // û�а취��̬��������һ��ռ�Ĵ�С, Ҳû�취��С��һ���ڴ�ռ�  
        //2. ѭ����ֵ
        //3. ��ӡ������������� 
        int* arr = (int* )malloc(sizeof(int)*10); 
        
        arr =  realloc(arr,sizeof(int)*8); //�ռ�ĳ���Ϊ12�� 
        int i =0;
        for(;i<5;i++){
           printf("������arr[%d]=��ֵ\n",i);
           scanf("%d",arr+i);                            
        }
        
        printArr(arr,5);
        
        system("pause");    // ����windows��ϵͳ������ �ó�����ִͣ��  ����۲�����ִ�н��  
          
     
     
         // ��ҵ: �Ӽ��̽���һ������ ����Ĵ�С 
       
         // ��̬�ĸ��� ����Ĵ�С����2 
            
}
