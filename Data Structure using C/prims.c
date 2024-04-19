#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INFINITY 9999

struct Graph {
    int V;
    int **adjMatrix;
};

struct MinHeapNode {
    int vertex;
    int key;
};

struct MinHeap {
    int size;
    int capacity;
    int *pos;
    struct MinHeapNode **array;
};

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adjMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++)
            graph->adjMatrix[i][j] = 0;
    }

    return graph;
}

struct MinHeapNode* newMinHeapNode(int v, int key) {
    struct MinHeapNode* newNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    newNode->vertex = v;
    newNode->key = key;
    return newNode;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key)
        smallest = right;

    if (smallest != idx) {
        struct MinHeapNode* smallestNode = minHeap->array[smallest];
        struct MinHeapNode* idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->vertex] = idx;
        minHeap->pos[idxNode->vertex] = smallest;

        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

bool isEmpty(struct MinHeap* minHeap) {
    return minHeap->size == 0;
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    if (isEmpty(minHeap))
        return NULL;

    struct MinHeapNode* root = minHeap->array[0];

    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->vertex] = minHeap->size - 1;
    minHeap->pos[lastNode->vertex] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(struct MinHeap* minHeap, int v, int key) {
    int i = minHeap->pos[v];
    minHeap->array[i]->key = key;

    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key) {
        minHeap->pos[minHeap->array[i]->vertex] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->vertex] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

bool isInMinHeap(struct MinHeap* minHeap, int v) {
    return minHeap->pos[v] < minHeap->size;
}

void printMST(int parent[], struct Graph* graph) {
    printf("Constructed Minimum Spanning Tree:\n");
    for (int i = 1; i < graph->V; i++)
        printf("Edge: %d - %d    Weight: %d\n", parent[i], i, graph->adjMatrix[i][parent[i]]);
}

void primMST(struct Graph* graph) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];

    struct MinHeap* minHeap = createMinHeap(graph->V);

    for (int v = 0; v < graph->V; v++) {
        parent[v] = -1;
        key[v] = INFINITY;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }

    key[0] = 0;
    decreaseKey(minHeap, 0, key[0]);

    minHeap->size = graph->V;

    while (!isEmpty(minHeap)) {
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->vertex;

        for (int v = 0; v < graph->V; v++) {
            if (graph->adjMatrix[u][v] && isInMinHeap(minHeap, v) && graph->adjMatrix[u][v] < key[v]) {
                key[v] = graph->adjMatrix[u][v];
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    int V, E, i, u, v, w;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v w) where u and v are vertices and w is weight:\n");
    //for (i = 0; i < E; i++) 
    while(1){
     printf("\nEnter starting vertex: ");
        scanf("%d",&u);
         printf("\nEnter destination vertex: ");
        scanf("%d",&v);
         printf("\nEnter weight of edge: ");
        scanf("%d", &w);
        if(u==0 && v==0)
         break;
        graph->adjMatrix[u][v] = w;
        graph->adjMatrix[v][u] = w; // Assuming an undirected graph
        
    }

    primMST(graph);

    return 0;
}

