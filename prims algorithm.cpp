#include <stdio.h>
#include <stdbool.h>
#define INF 99999
#define MAX 10
int minKey(int key[], bool mstSet[], int n) 
{
    int min = INF, minIndex;
    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}
void primsMST(int graph[MAX][MAX], int n) 
{
    int parent[MAX]; 
    int key[MAX];    
    bool mstSet[MAX]; 
    for (int i = 0; i < n; i++) 
	{
        key[i] = INF;
        mstSet[i] = false;
    }
    key[0] = 0; 
    parent[0] = -1; 
    for (int count = 0; count < n - 1; count++) 
	{
        int u = minKey(key, mstSet, n); 
        mstSet[u] = true; 
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() 
{
    int graph[MAX][MAX], n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (enter 0 if no edge between vertices):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    primsMST(graph, n);
    return 0;
}
