#include <stdio.h>

void bubbleSort(int array[], int size) 
{
    for (int step = 0; step < size - 1; ++step) 
	{
        printf("\nIteration %d: \n\n", step + 1);
        for (int i = 0; i < size - step - 1; ++i) 
		{
            if (array[i] > array[i + 1]) 
			{
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
        for (int j = 0; j < size; ++j) 
		{
            printf("%d    ", array[j]);
        }
        printf("\n");
    }
}

void printArray(int array[], int size) 
{
    for (int i = 0; i < size; ++i) 
	{
        printf("%d    ", array[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    int data[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; ++i) 
	{
        scanf("%d", &data[i]);
    }  
    printf("\nOriginal array: \n\n");
    printArray(data, size);
    bubbleSort(data, size);
    printf("\nSorted array in ascending order: \n\n");
    printArray(data, size);
    return 0;
}

