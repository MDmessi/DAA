#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10

// Function to find the vertex with the minimum distance
int min_distance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int source) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    
    // Initialize all distances to infinity and visited[] to false
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[source] = 0;
    
    // Find the shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int u = min_distance(dist, visited, n);
        visited[u] = 1;
        
        // Update dist[] for all adjacent vertices of the selected vertex
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    // Print the shortest distance from source to all vertices
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

int main() {
    int n, source;
    
    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    int graph[MAX_VERTICES][MAX_VERTICES];
    
    // Input the adjacency matrix (graph)
    printf("Enter the adjacency matrix (use 0 for no edge and positive values for weights):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    // Input the source vertex
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    
    // Call Dijkstra's algorithm
    dijkstra(graph, n, source);
    
    return 0;
}
