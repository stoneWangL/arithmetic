#include<stdio.h>
//Ã°ÅİÅÅĞò 
//´òÓ¡Êı×é 
void printArray(int arr[], int n) {
	int i;
	for( i = 0; i < n ; i++) {
		printf("%d ", arr[i]); 
	}
	printf("\n");
}

void insertSort(int arr[], int n) {
	int i, temp, j;
	for(i = 1 ; i < n ; i++){
		
		temp = arr[i];
		for(j = i ; j >0 && arr[j-1] > temp ; j--){
			arr[j] = arr[j-1];
		}
		arr[j] = temp;
	}
} 

int main() {
	int arr[] = {1, 2, 3, 4, 7, 98, 0, 12, 35, 99, 14}; 
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printArray(arr, n);
	insertSort(arr, n);
	printArray(arr, n);

	return 0;
}
