#include <stdio.h>

int main() {
	int arr[] = {1,3,5,7,9,0,11,22,3,0,33};
	int n = sizeof(arr)/sizeof(arr[0]);
	int result = binarySearch(arr, 111);
	
	if(result == -1)
		printf("û���ҵ�\n");
	else
		printf("��Ԫ���±�Ϊ%d", result);	
	return 0;
}
//�ҵ������±꣬û�ҵ�����-1 
int binarySearch(int arr[], int target) {
	int left = 0, right = target, mid; 
	while(left <= right) {
		mid = (left + right) / 2;
		if(arr[mid] == target)
			return mid;
		if(target < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;		
	}
	return -1;
} 
