#include <stdio.h>
int knapsack(int W, int wt[], int val[], int n) 
{
    int dp[n + 1][W + 1]; 
    for (int i = 0; i <= n; i++) 
	{
        for (int w = 0; w <= W; w++) 
		{
            if (i == 0 || w == 0) 
			{
                dp[i][w] = 0; 
            } else if (wt[i - 1] <= w) 
			{
                dp[i][w] = (val[i - 1] + dp[i - 1][w - wt[i - 1]]) > dp[i - 1][w] ? 
                            (val[i - 1] + dp[i - 1][w - wt[i - 1]]) : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W]; 
}

int main() 
{
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    int wt[n], val[n];
    printf("Enter the weights of the items: \n");
    for (int i = 0; i < n; i++) 
	{
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &wt[i]);
    }
    printf("Enter the values of the items: \n");
    for (int i = 0; i < n; i++) 
	{
        printf("Value of item %d: ", i + 1);
        scanf("%d", &val[i]);
    }
    int maxValue = knapsack(W, wt, val, n);
    printf("The maximum value that can be obtained is: %d\n", maxValue);
    return 0;
}

