#include <stdio.h>
//������
void printArray(int arr[], int n); 
void mySwap(int *a, int *b);
void heapSort(int arr[], int count);
void shiftDown(int arr[], int count, int currentRoot);

int main() {
	int arr[] = {1,3,5,7,9,0,11,22,3,0,33};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printArray(arr, n);
	heapSort(arr, n);
	printArray(arr, n);
	
	return 0;
}

void heapSort(int arr[], int count) {
	int i, j;
	//�����󶥶�
	for(i = (count-2)/2 ; i >= 0 ; i--)
		shiftDown(arr, count, i);
	
	//���󶥶ѵ�һ��Ԫ�غ����һ��������count--���ٹ����󶥶�
	for(j = count-1 ; j > 0 ; j--) {
		mySwap(&arr[0], &arr[j]);
		shiftDown(arr, j, 0);
	} 
}

void shiftDown(int arr[], int count, int currentRoot) {
	int max;
	while(2*currentRoot+1 < count) {
		max = 2*currentRoot + 1; //��ʼmax��ָ��left����
		if(max+1 < count && arr[max+1] > arr[max]) 
			max += 1;
		if(arr[currentRoot] >= arr[max])
			break; //������ı���������󶥶ѣ��Ͳ�������̽���� 
		mySwap(&arr[currentRoot], &arr[max]);
		currentRoot = max; //max�ڵ㶯�ˣ�������Ҫ�������������Ƿ�����󶥶�		
	}
} 

void mySwap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void printArray(int arr[], int n) {
	int i;
	for(i = 0 ; i < n ; i++ )
		printf("%d ", arr[i]);
	printf("\n");
}
