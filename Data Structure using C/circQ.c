#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size for the circular queue

int front = -1, rear = -1;
int *queue; // Dynamic array to store the circular queue

void initializeQueue(int maxSize) {
    queue = (int *)malloc(maxSize * sizeof(int));
}

int isEmpty() {
    return (front == -1);
}

int isFull(int maxSize) {
    return ((rear + 1) % maxSize == front);
}

void enqueue(int maxSize, int value) {
    if (isFull(maxSize)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % maxSize;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(int maxSize) {
    int value;
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    value = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % maxSize;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

int search(int maxSize, int key) {
    int i, index = -1;
    if (isEmpty()) {
        printf("Queue is empty. Cannot search.\n");
        return -1;
    }
    for (i = front; i != (rear + 1) % maxSize; i = (i + 1) % maxSize) {
        if (queue[i] == key) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        printf("Element %d found at position %d.\n", key, index);
    } else {
        printf("Element %d not found in the queue.\n", key);
    }
    return index;
}

void display(int maxSize) {
    int i;
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (i = front; i != (rear + 1) % maxSize; i = (i + 1) % maxSize) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void freeQueue() {
    free(queue);
    front = rear = -1;
}

int main() {
    int maxSize, choice, element, searchKey;

    printf("Enter the size of the circular queue: ");
    scanf("%d", &maxSize);

    initializeQueue(maxSize);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(maxSize, element);
                break;
            case 2:
                dequeue(maxSize);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &searchKey);
                search(maxSize, searchKey);
                break;
            case 4:
                display(maxSize);
                break;
            case 5:
                freeQueue();
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}