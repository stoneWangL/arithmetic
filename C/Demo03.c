#include <stdio.h>
int main()
{
    int i, j, k;
    for(i=1; i<5; i++)
    {
        /* �۲�ÿ�еĿո���������ȫѭ������ */
        for(k=1 ; k<5-i; k++)  
        {
            printf(" ");    //����ո�
        }
        /* �۲�ÿ��*�ŵ���������ȫѭ������ */
        for(j=1 ; j<2*i; j++) 
        {
            printf("*");   //ÿ�������*��
        }
        printf("\n");     //ÿ��ѭ������
    }
    return 0;
}
