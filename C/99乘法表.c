#include <stdio.h>
int main() 
{ 
    // 定义相乘数字i,j以及结果result
    int i, j, result;
    /*
     * 使用for循环解决本题相对简单哦~
     * 小编偷偷的将源码放在任务“不会了怎么办”中了哦~
     * 小编希望童鞋们独立完成哦~
     */
    for(i = 9 ; i >= 1 ; i--) {
        for(j = 1 ; j <= i ; j++) {
            printf("%d*%d=%d\t", i, j, i*j);
        }
        printf("\n");
    }
    
    
    
    
    return 0;
}
