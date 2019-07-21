#include <stdio.h>
//ц╟ещеепР 
void printArray(int arr[], int n) {
	int i;
	for( i = 0 ; i < n ; i++ )
		printf("%d ", arr[i]);
	printf("\n");
}

void bubbleSort(int arr[], int n) {
	int i, j;
	for( i = 0; i < n ; i++ ) {
		for( j = 0 ; j < n-1-i ; j++ ){
			if(arr[j] > arr[j+1])
				mySwap(&arr[j], &arr[j+1]);
		}
	}
}

void mySwap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int arr[] = {2,4,6,8,0,1,3,4,67};
	int n = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, n);
	bubbleSort(arr, n);
	printArray(arr, n);
	return 0;
} 


