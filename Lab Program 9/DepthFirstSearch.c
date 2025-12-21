#include <stdio.h>

#define MAX 20

int adj[MAX][MAX], visited[MAX], n;


void DFS(int v) {
    visited[v] = 1;
    
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    DFS(0);

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            count++;
        }
    }

    if (count == n) {
        printf("Graph is Connected\n");
    } else {
        printf("Graph is NOT Connected\n");
    }

    return 0;
}