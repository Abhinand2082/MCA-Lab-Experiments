#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100


// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int numVertices, numEdges;
    struct Edge edges[MAX_EDGES];
};

// Function prototypes
void initializeSubsets(struct Subset subsets[], int numVertices);
int findSet(struct Subset subsets[], int i);
void unionSets(struct Subset subsets[], int x, int y);
void kruskalMST(struct Graph* graph);

int main() {
    struct Graph graph;
	int i=0;
    // Input the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &graph.numVertices);
    //printf("Enter the number of edges: ");
    //scanf("%d", &graph.numEdges);

    // Input the edges (src, dest, weight)
    printf("Enter the edges (src dest weight),enter (0 0) to exit:\n");
    while(1) {
        printf("\nEnter starting vertex: ");
        scanf("%d", &graph.edges[i].src);
        printf("\nEnter destination vertex: ");
        scanf("%d",&graph.edges[i].dest);
        printf("\nEnter weight of edge: ");
        scanf("%d",&graph.edges[i].weight);
        if(graph.edges[i].src==0 && graph.edges[i].dest==0)
        	break;
        i++;
    }
	graph.numEdges=i;
    // Call Kruskal's algorithm to find MST
    kruskalMST(&graph);

    return 0;
}

// Function to initialize subsets for Union-Find
void initializeSubsets(struct Subset subsets[], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
}

// Function to find the set of an element using path compression
int findSet(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = findSet(subsets, subsets[i].parent); // Path compression
    }
    return subsets[i].parent;
}

// Function to perform union of two sets by rank
void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = findSet(subsets, x);
    int rootY = findSet(subsets, y);

    // Union by rank to keep the tree flat
    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootX].parent = rootY;
        subsets[rootY].rank++;
    }
}

// Function to implement Kruskal's algorithm to find MST
void kruskalMST(struct Graph* graph) {
int value=0;
    // Step 1: Initialize subsets for each vertex
    struct Subset subsets[MAX_VERTICES];
    initializeSubsets(subsets, graph->numVertices);

    // Step 2: Sort edges in non-decreasing order by weight
    for (int i = 0; i < graph->numEdges - 1; i++) {
        for (int j = 0; j < graph->numEdges - i - 1; j++) {
            if (graph->edges[j].weight > graph->edges[j + 1].weight) {
                // Swap edges if they are in the wrong order
                struct Edge temp = graph->edges[j];
                graph->edges[j] = graph->edges[j + 1];
                graph->edges[j + 1] = temp;
            }
        }
    }

    // Step 3: Process each edge in non-decreasing order
    printf("Minimum Spanning Tree Edges:\n");
    for (int i = 0; i < graph->numEdges; i++) {
        int src = graph->edges[i].src;
        int dest = graph->edges[i].dest;

        // Check if including this edge forms a cycle or not
        int rootSrc = findSet(subsets, src);
        int rootDest = findSet(subsets, dest);

        if (rootSrc != rootDest) {
            // If including the edge doesn't form a cycle, include it in MST
            printf("%d - %d (Weight: %d)\n", src, dest, graph->edges[i].weight);
            unionSets(subsets, rootSrc, rootDest);
            value += graph->edges[i].weight;
            
        }
    }
	printf("Total weight : %d",value);
}

