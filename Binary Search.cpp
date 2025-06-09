#include <stdio.h>

// Function to perform binary search with iteration display
int binarySearch(int arr[], int left, int right, int target) {
    int iteration = 1;  // Initialize iteration counter

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Display current iteration details
        printf("\nIteration %d: ", iteration);
        printf("Left = %d, Mid = %d, Right = %d\n", left, mid, right);

        // Display current subarray
        printf("Current Array: ");
        for (int i = left; i <= right; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Check if the target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            printf("Target is greater than %d, searching in the right half.\n", arr[mid]);
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            printf("Target is less than %d, searching in the left half.\n", arr[mid]);
            right = mid - 1;
        }

        iteration++; // Increment iteration counter
    }

    // Target is not present in the array
    return -1;
}

int main() {
    int n, target, result;
    
    // Input array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input array elements
    printf("Enter %d elements in sorted order: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input target element to search
    printf("Enter the element to search: ");
    scanf("%d", &target);
    
    // Perform binary search
    result = binarySearch(arr, 0, n - 1, target);
    
    // Output result
    if (result != -1)
        printf("\nElement %d found at index %d.\n", target, result);
    else
        printf("\nElement %d not found in the array.\n", target);
    
    return 0;
}

