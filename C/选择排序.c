#include <stdio.h>
//—°‘Ò≈≈–Ú 
void printArray(int arr[], int n);
void mySwap(int *a, int *b);
void selectSort(int arr[], int n);

int main() {
	int arr[] = {1, 2, 3, 4, 7, 98, 0, 12, 35, 99, 14}; 
	int n = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, n);
	selectSort(arr, n);
	printArray(arr, n);
	return 0;
} 

void selectSort(int arr[], int n) {
	int i, j, index;
	for( i = 0 ; i < n ; i++ ) {
		index = i;
		for( j = i+1 ; j < n ; j++ ) {
			if(arr[index] > arr[j])
				index = j;
		}
		if(index != i)
			mySwap(&arr[i], &arr[index]);
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


