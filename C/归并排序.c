#include <stdio.h>
//归并排序 
void mySwap(int *a, int *b);
void printArray(int arr[], int n);
void mergeSort(int arr[], int left, int right);

int main() {
	int arr[] = {1,3,5,7,9,0,11,22,3,0,33};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printArray(arr, n);
	mergeSort(arr, 0, n-1);
	printArray(arr, n);
	return 0;
}

void mergeSort(int arr[], int left, int right) {
	int mid;
	if(left >= right)
		return ;
	mid  = (left + right) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	merge(arr, left, mid, right);
}

void merge(int arr[], int left, int mid, int right) {
	int aux[right-left+1]; //临时辅助数组
	int i, j, k;
	for(i = left ; i <= right ; i++)
		aux[i-left] = arr[i];
	
	i = left;
	j = mid + 1;
	for(k = left ; k <= right ; k++) {
		if(i > mid) { //检查左下标是否越界
			arr[k] = aux[j-left];
			j++;
		} else if(j > right) { //检查右下标是否越界
			arr[k] = aux[i - left];
			i++;
		} else if(aux[i - left] <= aux[j - left]) {
			arr[k] = aux[i - left];
			i++;
		} else {
			arr[k] = aux[j - left];
			j++;
		}
	}	
	 
}

void printArray(int arr[], int n) {
	int i;
	for(i = 0 ; i < n ; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void mySwap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}
