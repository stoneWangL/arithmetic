#include <stdio.h>

void main()
{
	int price = 0;
	const int AMOUNT = 100;
	printf("��������(Ԫ)��");
	scanf("%d", &price);
	
	AMOUNT = 50;
	
	int change = AMOUNT - price;
	
	printf("����%dԪ��\n", change); 
}
