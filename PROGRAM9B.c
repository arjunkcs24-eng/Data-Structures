#include <stdio.h>

int adj[10][10], visited[10];
int n;

void DFS(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    DFS(0);   // start DFS from vertex 0

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            printf("Graph is NOT connected");
            return 0;
        }
    }

    printf("Graph is connected");
    return 0;
}
