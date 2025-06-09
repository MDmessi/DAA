#include <stdio.h>

void printArray(int arr[], int size) 
{
    int i;
    for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *xp, int *yp) 
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) 
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
	{
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
        printf("\nArray after iteration %d: \n ", i + 1);
        printArray(arr, n);
    }
}

int main() 
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &arr[i]);
    }
    printf("Original array: \n");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("\nSorted array: \n");
    printArray(arr, n);

    return 0;
}

