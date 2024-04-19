#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adjacencyList;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; ++i)
        graph->adjacencyList[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void dfsTraversal(int vertex, int visited[], struct Graph* graph) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* adjList = graph->adjacencyList[vertex];
    while (adjList != NULL) {
        int connectedVertex = adjList->data;
        if (!visited[connectedVertex])
            dfsTraversal(connectedVertex, visited, graph);

        adjList = adjList->next;
    }
}

void bfsTraversal(int startVertex, struct Graph* graph) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        struct Node* adjList = graph->adjacencyList[currentVertex];
        while (adjList != NULL) {
            int connectedVertex = adjList->data;
            if (!visited[connectedVertex]) {
                visited[connectedVertex] = 1;
                queue[++rear] = connectedVertex;
            }

            adjList = adjList->next;
        }
    }
}

void topologicalSortUtil(int vertex, int visited[], struct Graph* graph, int stack[], int* stackIndex) {
    visited[vertex] = 1;

    struct Node* adjList = graph->adjacencyList[vertex];
    while (adjList != NULL) {
        int connectedVertex = adjList->data;
        if (!visited[connectedVertex])
            topologicalSortUtil(connectedVertex, visited, graph, stack, stackIndex);

        adjList = adjList->next;
    }

    stack[--(*stackIndex)] = vertex;
}

void topologicalSort(struct Graph* graph) {
    int visited[MAX] = {0};
    int stack[MAX];
    int stackIndex = graph->vertices;

    for (int i = 0; i < graph->vertices; ++i) {
        if (!visited[i])
            topologicalSortUtil(i, visited, graph, stack, &stackIndex);
    }

    printf("Topological Sort: ");
    for (int i = 0; i < graph->vertices; ++i)
        printf("%d ", stack[i]);
}

int main() {
    int vertices, edges, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; ++i) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("\nEnter the starting vertex for DFS: ");
    scanf("%d", &src);
    printf("DFS Traversal: ");
    int visitedDFS[MAX] = {0};
    dfsTraversal(src, visitedDFS, graph);

    printf("\nEnter the starting vertex for BFS: ");
    scanf("%d", &src);
    printf("BFS Traversal: ");
    bfsTraversal(src, graph);

    topologicalSort(graph);

    return 0;
}