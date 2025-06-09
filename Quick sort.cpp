#include <stdio.h>
#define MAX 100
typedef struct 
{
    int left;
    int right;
} Stack;

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) 
	{
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSortIterative(int arr[], int n) 
{
    Stack stack[MAX];
    int top = -1;

    stack[++top] = (Stack){0, n - 1};
    int iteration = 1;

    while (top >= 0) 
	{
        int low = stack[top].left;
        int high = stack[top].right;
        top--;

        int pivot = partition(arr, low, high);
        
        printf("Iteration %d: ", iteration++);
        for (int i = 0; i < n; i++) 
		{
            printf("%d ", arr[i]);
        }
        printf("\n");
        if (pivot - 1 > low) 
		{
            stack[++top] = (Stack)
			{low, pivot - 1};
        }
        if (pivot + 1 < high) 
		{
            stack[++top] = (Stack)
			{pivot + 1, high};
        }
    }
}

int main() {
    int arr[MAX], n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &arr[i]);
    }

    printf("\nSorting process:\n");
    quickSortIterative(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

