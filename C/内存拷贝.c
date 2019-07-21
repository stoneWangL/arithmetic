#include <stdio.h>
//void* memmove(void* str1,const void* str2,size_t n);
//void* memcpy(void* str1,const void* str2,size_t n);
int main(){
	//首先定义一个字符串数组str
	int i; 
	char str[11] = "0123456789";
	
	for (i = 0; i < 10; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
	/*
	* 下面分别使用memmove和memcpy对这个数组进行操作
	* ① 覆盖情况一（src是高地址，dest是低地址，由高地址向低地址进行内存拷贝）
	*/
	//memmove((void *)&str[0], (void *)&str[3], 5);
	//memcpy((void *)&str[0], (void *)&str[3], 5);
	/*
	两个函数的结果是相同的，得到的结果均为“3456756789”
	即实现了将“34567”这五个数字拷贝到数组的前五个位置上
	*/
	
	/*
	② 覆盖情况二（src是低地址，dest是高地址，由低地址向高地址进行内存拷贝）
	*/
//	memmove((void *)&str[3], (void *)&str[0], 5);
	memcpy((void *)&str[3], (void *)&str[0], 5);
	/*
	这次，两个函数的结果完全不同，
	使用memmove()得到结果“0120123489”是我们事先想得到的，
	而memcpy()得到的结果却不是我们所预期的，结果是“0120120189”
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


