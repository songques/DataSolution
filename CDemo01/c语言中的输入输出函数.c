/*%d  -  int
%ld �C long int
%c  - char
%f -  float
%lf �C double
%x �C ʮ��������� int ����long int ����short int
%o -  �˽������
%s �C �ַ���

Int len;
Scanf(��%d��,&len);*/
#include <stdio.h>    // java  import xxx.xx.pack    ���ú���������  
#include <stdlib.h>
 main() // �������ں���  
{    int i = 3;
     float f = 3.1415;
     double d = 6.2815;
     char c = 'A';   //ͨ�������Ŷ����ַ� 
     short s = 2;   
       
     printf("int i=%d\n",i);
     printf("float f=%f\n",f);
     printf("char c=%c\n",c);
     printf("double d=%lf\n",d);
     printf("short s=%d\n",s);
     
     /*char arr[20] ; //����һ������Ϊ20������
     scanf("%s",arr);  // �Ӽ��̽���һ���ַ���,����c�������� 
     
     printf("s =%s\n",arr); 
       */
       
     int j ;
     scanf("%d", &j);//&�������ȡ��ַ  
     printf("j=%d\n",j); 
        
     system("pause");    // ����windows��ϵͳ������ �ó�����ִͣ��  ����۲�����ִ�н��  
}
