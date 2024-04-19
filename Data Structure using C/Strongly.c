#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a vertex in the graph
struct Vertex {
    int index;
    int visited;
    int finishingTime;
};

// Structure to represent an edge in the graph
struct Edge {
    int destination;
    struct Edge* next;
};

// Structure to represent a graph
struct Graph {
    struct Vertex vertices[MAX_VERTICES];
    struct Edge* adjacencyList[MAX_VERTICES];
};

// Stack structure for DFS
struct Stack {
    int top;
    int items[MAX_VERTICES];
};

// Function to initialize a graph
void initializeGraph(struct Graph* graph, int numVertices);

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest);

// Function to perform DFS on the graph
void DFS(struct Graph* graph, int vertex, struct Stack* stack);

// Function to perform DFS on the transpose of the graph
void DFSTranspose(struct Graph* graph, int vertex);

// Function to push an item to the stack
void push(struct Stack* stack, int item);

// Function to pop an item from the stack
int pop(struct Stack* stack);

int main() {
    int numVertices, numEdges, i,src, dest;

    // Input the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
   // printf("Enter the number of edges: ");
   // scanf("%d", &numEdges);

    struct Graph graph;
    initializeGraph(&graph, numVertices);

    // Input the edges
    printf("Enter the edges (src dest) and enter (0 0) to exit:\n");
   while(1) {
        
        printf("\nEnter starting vertex: ");
	scanf("%d",&src);
	printf("\nEnter destination vertex: ");
        scanf("%d",&dest);
       // addEdge(&graph, src, dest);
        if ( src==0 && dest==0)
		break;
	addEdge(&graph, src, dest);
    }

    // Step 1: Call DFS to compute finishing times
    struct Stack stack;
    stack.top = -1;

    for (i = 0; i < numVertices; i++) {
        if (!graph.vertices[i].visited) {
            DFS(&graph, i, &stack);
        }
    }

    // Step 2: Compute the transpose of the graph
    struct Graph transposedGraph;
    initializeGraph(&transposedGraph, numVertices);

    for (i = 0; i < numVertices; i++) {
        struct Edge* current = graph.adjacencyList[i];
        while (current != NULL) {
            addEdge(&transposedGraph, current->destination, i);
            current = current->next;
        }
    }

    // Step 3: Call DFS on the transpose in the order of decreasing finishing times
    while (stack.top != -1) {
        int vertex = pop(&stack);
        if (!transposedGraph.vertices[vertex].visited) {
            printf("Strongly Connected Component: ");
            DFSTranspose(&transposedGraph, vertex);
            printf("\n");
        }
    }

    return 0;
}

// Function to initialize a graph
void initializeGraph(struct Graph* graph, int numVertices) {
    int i;
    for (i = 0; i < numVertices; i++) {
        graph->vertices[i].index = i;
        graph->vertices[i].visited = 0;
        graph->vertices[i].finishingTime = 0;
        graph->adjacencyList[i] = NULL;
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->destination = dest;
    newEdge->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newEdge;
}

// Function to perform DFS on the graph
void DFS(struct Graph* graph, int vertex, struct Stack* stack) {
    graph->vertices[vertex].visited = 1;

    struct Edge* current = graph->adjacencyList[vertex];
    while (current != NULL) {
        if (!graph->vertices[current->destination].visited) {
            DFS(graph, current->destination, stack);
        }
        current = current->next;
    }

    // Push the current vertex to the stack when all its neighbors are visited
    push(stack, vertex);
}

// Function to perform DFS on the transpose of the graph
void DFSTranspose(struct Graph* graph, int vertex) {
    graph->vertices[vertex].visited = 1;

    printf("%d ", vertex);

    struct Edge* current = graph->adjacencyList[vertex];
    while (current != NULL) {
        if (!graph->vertices[current->destination].visited) {
            DFSTranspose(graph, current->destination);
        }
        current = current->next;
    }
}

// Function to push an item to the stack
void push(struct Stack* stack, int item) {
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
    return stack->items[stack->top--];
}

