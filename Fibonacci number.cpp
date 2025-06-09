#include <stdio.h>

int fibonacci(int n) 
{
    int a = 0, b = 1, c;
    if (n <= 0) 
	{
        return 0;
    } 
	else if (n == 1) 
	{
        return 1;
    }
    printf("Iteration 1: %d\n", a);
    printf("Iteration 2: %d\n", b); 
    for (int i = 3; i <= n; i++) 
	{ 
        c = a + b;
        a = b;
        b = c;
        printf("Iteration %d: %d\n", i, b);
    }
    return b;
}

int main() 
{
    int n;
    printf("Enter the term number: ");
    scanf("%d", &n);
    printf("\nThe %dth term of the Fibonacci series is: %d\n", n, fibonacci(n));
    return 0;
}

