#include <stdio.h>
void merge(int arr[], int l, int m, int r) 
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
	{
        if (L[i] <= R[j]) 
		{
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
	{
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
	{
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortIterative(int arr[], int n) 
{
    int curr_size;
    int left_start;
    int iteration = 1;

    for (curr_size = 1; curr_size < n; curr_size = 2 * curr_size) 
	{
        printf("Iteration %d:\n", iteration++);
        
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) 
		{
            int mid = left_start + curr_size - 1;
            int right_end = (left_start + 2 * curr_size - 1 < n - 1) ? (left_start + 2 * curr_size - 1) : (n - 1);
            
            merge(arr, left_start, mid, right_end);
        }
        
        for (int i = 0; i < n; i++) 
		{
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() 
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &arr[i]);
    }
    mergeSortIterative(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
