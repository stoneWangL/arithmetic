#include <stdio.h>
//void* memmove(void* str1,const void* str2,size_t n);
//void* memcpy(void* str1,const void* str2,size_t n);
int main(){
	//���ȶ���һ���ַ�������str
	int i; 
	char str[11] = "0123456789";
	
	for (i = 0; i < 10; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
	/*
	* ����ֱ�ʹ��memmove��memcpy�����������в���
	* �� �������һ��src�Ǹߵ�ַ��dest�ǵ͵�ַ���ɸߵ�ַ��͵�ַ�����ڴ濽����
	*/
	//memmove((void *)&str[0], (void *)&str[3], 5);
	//memcpy((void *)&str[0], (void *)&str[3], 5);
	/*
	���������Ľ������ͬ�ģ��õ��Ľ����Ϊ��3456756789��
	��ʵ���˽���34567����������ֿ����������ǰ���λ����
	*/
	
	/*
	�� �����������src�ǵ͵�ַ��dest�Ǹߵ�ַ���ɵ͵�ַ��ߵ�ַ�����ڴ濽����
	*/
//	memmove((void *)&str[3], (void *)&str[0], 5);
	memcpy((void *)&str[3], (void *)&str[0], 5);
	/*
	��Σ����������Ľ����ȫ��ͬ��
	ʹ��memmove()�õ������0120123489��������������õ��ģ�
	��memcpy()�õ��Ľ��ȴ����������Ԥ�ڵģ�����ǡ�0120120189��
	*/
	
	for (i = 0; i < 10; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    
	return 0;
}

void* memcpy(void* str1,const void* str2,size_t n)
{
	size_t 	i;
    char	*pStr1 = (char *)str1;
    char	*pStr2 = (char *)str2;
    
    for(i = 0;i != n; i++)
    {
    	*(pStr1++) = *(pStr2++);
    }

    return str1;
} 

void* memmove(void* str1,const void* str2,size_t n)
{
	size_t 	i;
    char	*pStr1 = (char *)str1;
    char	*pStr2 = (char *)str2;
    if  (pStr1 < pStr2) 
    {
        for(i = 0;i != n; i++)
        {
            *(pStr1++) = *(pStr2++);
        }
    }
    else
    {
        pStr1 += n-1;
        pStr2 += n-1;
        for(i = 0;i != n; i++)
        {
            *(pStr1--) = *(pStr2--);
        }
    }
    return str1;
}


