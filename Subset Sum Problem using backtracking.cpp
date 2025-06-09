#include <stdio.h>
#include <stdbool.h>
bool isSubsetSum(int set[], int n, int sum) 
{
    if (sum == 0) 
	{
        return true;
    }
    if (n == 0 && sum != 0) 
	{
        return false;
    }
    if (set[n - 1] > sum) 
	{
        return isSubsetSum(set, n - 1, sum); 
    }
    return isSubsetSum(set, n - 1, sum) || 
           isSubsetSum(set, n - 1, sum - set[n - 1]); 
}

int main() 
{
    int n, sum;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    int set[n];
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &set[i]);
    }
    printf("Enter the sum to be checked: ");
    scanf("%d", &sum);
    if (isSubsetSum(set, n, sum)) 
	{
        printf("Yes, there exists a subset with sum %d.\n", sum);
    } else {
        printf("No, there doesn't exist a subset with sum %d.\n", sum);
    }
    return 0;
}

