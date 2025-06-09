#include <stdio.h>
#include <stdbool.h>
#define MAX_N 20  
void printSolution(int board[MAX_N][MAX_N], int N) 
{
    for (int i = 0; i < N; i++) 
	{
        for (int j = 0; j < N; j++) 
		{
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}
bool isSafe(int board[MAX_N][MAX_N], int row, int col, int N) 
{
    for (int i = 0; i < row; i++) 
	{
        if (board[i][col] == 1) 
		{
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
	{
        if (board[i][j] == 1) 
		{
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) 
	{
        if (board[i][j] == 1) 
		{
            return false;
        }
    }
    return true;
}
int solveNQueen(int board[MAX_N][MAX_N], int row, int N) 
{
    int solutionCount = 0;
    if (row >= N) 
	{
        solutionCount = 1;
        printSolution(board, N); 
        printf("\n");
        return solutionCount;
    }
    for (int col = 0; col < N; col++) 
	{
        if (isSafe(board, row, col, N)) 
		{
            board[row][col] = 1;
            solutionCount += solveNQueen(board, row + 1, N);
            board[row][col] = 0;  
        }
    }
    return solutionCount;
}
int main() 
{
    int N;
    printf("Enter the value of N (size of the board): ");
    scanf("%d", &N);
    if (N <= 0 || N > MAX_N) 
	{
        printf("Please enter a valid value for N (1 <= N <= %d)\n", MAX_N);
        return 0;
    }
    int board[MAX_N][MAX_N] = {0};  
    int totalSolutions = solveNQueen(board, 0, N);
    printf("Total number of solutions for N = %d: %d\n", N, totalSolutions);
    return 0;
}

