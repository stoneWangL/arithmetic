#include <stdio.h>
int main() 
{ 
    // �����������i,j�Լ����result
    int i, j, result;
    /*
     * ʹ��forѭ�����������Լ�Ŷ~
     * С��͵͵�Ľ�Դ��������񡰲�������ô�족����Ŷ~
     * С��ϣ��ͯЬ�Ƕ������Ŷ~
     */
    for(i = 9 ; i >= 1 ; i--) {
        for(j = 1 ; j <= i ; j++) {
            printf("%d*%d=%d\t", i, j, i*j);
        }
        printf("\n");
    }
    
    
    
    
    return 0;
}
