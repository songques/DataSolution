#include <stdio.h>    
#include <stdlib.h>
 main() 
{  
        int i =3;
        double d = 3.141692;
        float f = 3.1423;
        char c ='B';
        
        int*  ip = &i;
        double* dp = &d;
        float* fp = &f;
        char* cp = &c;
         
        
        printf("int ����ָ������ĳ���Ϊ %d\n",sizeof(ip)); 
        printf("double ����ָ������ĳ���Ϊ %d\n",sizeof(dp)); 
        printf("float ����ָ������ĳ���Ϊ %d\n",sizeof(fp));        
        printf("char ����ָ������ĳ���Ϊ %d\n",sizeof(cp));        
        
        
        
        // ��32λ�Ĳ���ϵͳ�� ��Ϊ���� �����ʹ�õ��ڴ�ռ�ĵ�ַ ����2��32�η�
        // ָ��ֻ��Ҫ4λ �Ϳ��Ա�ʾ�������е��ڴ�ռ� 
        
        // 64 ���ұ���֧��64λ 8λ 
        
         system("pause");    // ����windows��ϵͳ������ �ó�����ִͣ��  ����۲�����ִ�н��  
    
}
