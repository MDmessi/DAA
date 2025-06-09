#include <stdio.h>
#include <stdlib.h>
#define MAX 20
struct Edge {
    int u, v, weight;
};
struct Subset {
    int parent;
    int rank;
};
int compare(const void *a, const void *b) 
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}
int find(struct Subset subsets[], int i) 
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void unionSets(struct Subset subsets[], int x, int y) 
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
void kruskal(struct Edge edges[], int V, int E) 
{
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));
    struct Edge result[MAX];
    int e = 0, i = 0, j = 0;
    qsort(edges, E, sizeof(edges[0]), compare);
    for (i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    while (e < V - 1 && j < E) {
        struct Edge nextEdge = edges[j++];
        int x = find(subsets, nextEdge.u);
        int y = find(subsets, nextEdge.v);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }
    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        printf("%d -- %d = %d\n", result[i].u, result[i].v, result[i].weight);
    }
    free(subsets);
}

int main() 
{
    int V, E, i;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    struct Edge edges[E];
    printf("Enter the edges (u v weight):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    kruskal(edges, V, E);
    return 0;
}
