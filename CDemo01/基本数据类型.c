// java�������� �ͳ���int  4���ֽ� double  8���ֽ�  float 4���ֽ� long 8���ֽ� 
// short 2���ֽ� boolean  1���ֽ� char 2���ֽ� byte   1���ֽ� 
// char, int, float, double, signed, unsigned, long, short and void
// c������ �������ͱ�java��һЩ ��c������û�� boolean���͵�����  int 1 ������ 0 �����
// c ������û��String���͵�����   java�б�ʾһ���ַ��� String  , c�����б�ʾ�ַ��� ͨ��char���͵���������ʾ�ַ���
// c ����û��byte����   ������char�����ͱ�ʾbyte���� 

#include <stdio.h>    
#include <stdlib.h>
// sizeof(); c���Ե�һ������ ���԰� ĳ���������͵ĳ��Ȼ�ȡ���� int 
 main() 
{          // %d ����sql����? ռλ��  
            printf("char�ĳ���Ϊ%d\n", sizeof(char));
            printf("int�ĳ���Ϊ%d\n", sizeof(int));
            printf("float�ĳ���Ϊ%d\n", sizeof(float));
            printf("double�ĳ���Ϊ%d\n", sizeof(double));
            printf("long�ĳ���Ϊ%d\n", sizeof(long));
            printf("short�ĳ���Ϊ%d\n", sizeof(short));
            
            //signed, unsigned, �������͵����η�
           // signed int ; ��������з��ŵ�int������ 
           // unsigned int ;  �޷��ŵ�int���� 
              printf("signed int�ĳ���Ϊ%d\n", sizeof( signed int));
              printf("unsigned int�ĳ���Ϊ%d\n", sizeof( unsigned int));
        
           // ���ŵ����η� ֻ������ �������͵����� long int 
           // �������� �����͵����� float double  
           // printf("signed float�ĳ���Ϊ%d\n", sizeof( signed float));
        
              system("pause");    // ����windows��ϵͳ������ �ó�����ִͣ��  ����۲�����ִ�н��  
}

 
