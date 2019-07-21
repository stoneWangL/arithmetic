#include <stdio.h>
int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i; 
    for(i=0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++)
    printf("%d\n", arr[i]);
    return 0;
}
