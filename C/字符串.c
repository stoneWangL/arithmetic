#include <stdio.h>
#include <string.h>
int main()
{
    char s1[100]="";
    char s2[]="�Ұ�,";
    char s3[]="Ľ����";
    /*�����²�ȫ����*/
    strcat(s2, s3);
    
    printf("%s\n",s2);
    return 0;    
}
