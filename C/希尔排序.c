#include <stdio.h>
//ϣ������
void shellSort(int arr[], int n);
void printArray(int arr[], int n);

 
int main() {
	int arr[] = {1,3,5,7,9,0,11,22,3,0,33};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printArray(arr, n);
	shellSort(arr, n);
	printArray(arr, n);
	
	return 0;
} 

void shellSort(int arr[], int n) {
	int gap, i, temp, j;
	for(gap = n/2 ; gap > 0 ; gap/=2) { /*�����𽥼�С*/
		for(i = gap ; i < n ; i++) { /*��ͬһ������*/
			temp = arr[i]; //����Ԫ��
			for(j = i ; j >= gap && temp < arr[j-gap]; j-=gap)
				arr[j] = arr[j-gap]; //ԭ�����������ĺ���һλ
			arr[j] = temp;	
		}
	}
}

void printArray(int arr[], int n) {
	int i;
	for(i = 0 ; i < n ; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

