#include <stdio.h>
#include <limits.h>
int matrixChainMultiplication(int arr[], int n) 
{
    int dp[n][n]; 
    int i, j, k, L, cost;
    for (i = 1; i < n; i++)
        dp[i][i] = 0;
    for (L = 2; L < n; L++) 
	{
        for (i = 1; i < n - L + 1; i++) 
		{
            j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (k = i; k < j; k++) 
			{
                cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    return dp[1][n - 1]; 
}
int main() 
{
    int n, i;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int arr[n + 1];
    printf("Enter the dimensions of matrices (n+1 elements):\n");
    for (i = 0; i <= n; i++) 
	{
        scanf("%d", &arr[i]);
    }
    printf("Minimum number of multiplications: %d\n", matrixChainMultiplication(arr, n + 1));
    return 0;
}

