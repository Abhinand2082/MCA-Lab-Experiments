#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GREY 1
#define BLACK 2

struct Vertex {
    int color;
    int d;
    int f;
    struct Vertex* p;
};

struct Graph {
    int vertices;
    int** adjacencyMatrix;
    struct Vertex* verticesInfo;
};

void DFS(struct Graph* G);
void DFSVisit(struct Graph* G, int u);
void DFSTranspose(struct Graph* G, int u);
void printStronglyConnectedComponents(struct Graph* G);

int time = 0;

int main() {
    int i, j, vertices;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    struct Graph G;
    G.vertices = vertices;

    // Allocate memory for adjacency matrix
    G.adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    for (i = 0; i < vertices; i++) {
        G.adjacencyMatrix[i] = (int*)malloc(vertices * sizeof(int));
    }

    // Accept adjacency matrix from the user
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &G.adjacencyMatrix[i][j]);
        }
    }

    // Allocate memory for vertices information
    G.verticesInfo = (struct Vertex*)malloc(vertices * sizeof(struct Vertex));

    // Initialize vertices information
    for (i = 0; i < vertices; i++) {
        G.verticesInfo[i].color = WHITE;
        G.verticesInfo[i].d = 0;
        G.verticesInfo[i].f = 0;
        G.verticesInfo[i].p = NULL;
    }

    // Perform DFS to get finishing times
    DFS(&G);

    // Transpose the graph
    int temp;
    for (i = 0; i < G.vertices; i++) {
        for (j = i + 1; j < G.vertices; j++) {
            temp = G.adjacencyMatrix[i][j];
            G.adjacencyMatrix[i][j] = G.adjacencyMatrix[j][i];
            G.adjacencyMatrix[j][i] = temp;
        }
    }

    // Reset vertices information for the second DFS
    for (i = 0; i < G.vertices; i++) {
        G.verticesInfo[i].color = WHITE;
        G.verticesInfo[i].d = 0;
        G.verticesInfo[i].f = 0;
        G.verticesInfo[i].p = NULL;
    }

    // Perform DFS on the transposed graph to find strongly connected components
    printStronglyConnectedComponents(&G);

    // Free allocated memory
    for (i = 0; i < vertices; i++) {
        free(G.adjacencyMatrix[i]);
    }
    free(G.adjacencyMatrix);
    free(G.verticesInfo);

    return 0;
}

void DFS(struct Graph* G) {
    int i;

    for (i = 0; i < G->vertices; i++) {
        if (G->verticesInfo[i].color == WHITE) {
            DFSVisit(G, i);
        }
    }
}

void DFSVisit(struct Graph* G, int u) {
    int v;

    time = time + 1;
    G->verticesInfo[u].d = time;
    G->verticesInfo[u].color = GREY;

    for (v = 0; v < G->vertices; v++) {
        if (G->adjacencyMatrix[u][v] == 1 && G->verticesInfo[v].color == WHITE) {
            G->verticesInfo[v].p = &G->verticesInfo[u];
            DFSVisit(G, v);
        }
    }

    G->verticesInfo[u].color = BLACK;
    time = time + 1;
    G->verticesInfo[u].f = time;
}

void DFSTranspose(struct Graph* G, int u) {
    // Similar to DFSVisit but without updating finishing times
    int v;
    G->verticesInfo[u].color = GREY;

    for (v = 0; v < G->vertices; v++) {
        if (G->adjacencyMatrix[u][v] == 1 && G->verticesInfo[v].color == WHITE) {
            G->verticesInfo[v].p = &G->verticesInfo[u];
            DFSTranspose(G, v);
        }
    }

    G->verticesInfo[u].color = BLACK;
}

void printStronglyConnectedComponents(struct Graph* G) {
    int i;

    for (i = 0; i < G->vertices; i++) {
        if (G->verticesInfo[i].color == WHITE) {
            printf("Strongly Connected Component %d: ", i + 1);
            DFSTranspose(G, i);
            for (int j = 0; j < G->vertices; j++) {
                if (G->verticesInfo[j].color == BLACK) {
                    printf("%d ", j + 1);
                }
            }
            printf("\n");
        }
    }
}