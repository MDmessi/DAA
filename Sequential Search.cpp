#include <stdio.h>

int sequentialSearch(int arr[], int size, int key) 
{
    for (int i = 0; i < size; i++) 
	{
        printf("Iteration %d: Checking index %d, value = %d\n", i + 1, i, arr[i]);
        if (arr[i] == key) 
		{
            return i; 
        }
    }
    return -1; 
}
int main() 
{
    int size, key, result;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) 
	{
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);
    result = sequentialSearch(arr, size, key);
    if (result != -1) 
	{
        printf("\nKey %d found at index %d.\n", key, result);
    } 
	else {
        printf("\nKey %d not found in the array.\n", key);
    }

    return 0;
}

