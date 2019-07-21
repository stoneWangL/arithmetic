#include <stdio.h>

void main()
{
	int price = 0;
	const int AMOUNT = 100;
	printf("请输入金额(元)：");
	scanf("%d", &price);
	
	AMOUNT = 50;
	
	int change = AMOUNT - price;
	
	printf("找您%d元。\n", change); 
}
