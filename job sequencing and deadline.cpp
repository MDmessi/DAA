#include <stdio.h>
#include <stdlib.h>

struct Job {
    int id;        
    int deadline;  
    int profit;    
};
int compare(const void *a, const void *b) 
{
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}
void jobSequencing(struct Job jobs[], int n) 
{
    
    qsort(jobs, n, sizeof(struct Job), compare);
    int result[n]; 
    int slot[n];   
    for (int i = 0; i < n; i++) 
	{
        slot[i] = -1;
    }
    for (int i = 0; i < n; i++) 
	{
        for (int j = jobs[i].deadline - 1; j >= 0; j--) 
		{
            if (slot[j] == -1) 
			{
                slot[j] = i;  
                break;
            }
        }
    }
    printf("Job Sequence with maximum profit:\n");
    for (int i = 0; i < n; i++) 
	{
        if (slot[i] != -1) 
		{
            printf("Job %d (Profit: %d) is scheduled at time slot %d\n",
                   jobs[slot[i]].id, jobs[slot[i]].profit, i + 1);
        }
    }
}

int main() 
{
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    struct Job jobs[n];
    for (int i = 0; i < n; i++) 
	{
        printf("Enter details for Job %d:\n", i + 1);
        printf("Job ID: ");
        scanf("%d", &jobs[i].id);
        printf("Deadline: ");
        scanf("%d", &jobs[i].deadline);
        printf("Profit: ");
        scanf("%d", &jobs[i].profit);
    }
    jobSequencing(jobs, n);
    return 0;
}
