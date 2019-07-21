#include <stdio.h>
//快速排序 
void printArray(int arr[], int n);
void quickSort(int arr[], int left, int right);
void mySwap(int *a, int *b);

int main() {
	int arr[] = {1, 2, 3, 4, 7, 98, 0, 12, 35, 99, 14}; 
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printArray(arr, n);
	quickSort(arr, 0, n-1);
	printArray(arr, n);
	
	return 0;
} 

void quickSort(int arr[], int left, int right) {
	int i, j, key;
	
	if(left >= right) return ;
	
	key = arr[left];
	i = left;
	j = right;
	
	while(i < j) {
		//j向左移，直到遇到比key小的值
		while(arr[j] >= key && i < j) j--;
		//i向右移，直到遇到比key大的值
		while(arr[i] <= key && i < j) i++;
		if(i < j) mySwap(&arr[i], &arr[j]);
	}
	arr[left] = arr[i];
	arr[i] = key;
	
	quickSort(arr, left, i-1);
	quickSort(arr, i+1, right);
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
