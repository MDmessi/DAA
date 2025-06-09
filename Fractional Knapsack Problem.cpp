#include <stdio.h>
struct Item {
    int weight;
    int value;
    double ratio; 
};

void swap(struct Item *a, struct Item *b) 
{
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(struct Item items[], int n) 
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (items[j].ratio < items[j + 1].ratio) 
			{
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

double fractionalKnapsack(struct Item items[], int n, int capacity) 
{
    sortItems(items, n); 
    double totalValue = 0.0; 
    for (int i = 0; i < n; i++) 
	{
        if (capacity >= items[i].weight) 
		{ 
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].ratio * capacity;
            break;
        }
    }
    return totalValue;
}

int main() 
{
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    for (int i = 0; i < n; i++) 
	{
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight; 
    }
    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);
    return 0;
}
