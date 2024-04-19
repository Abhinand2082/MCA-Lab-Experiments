#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;           // Data of the node
    struct Node* next;  // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertBegin(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at a specified position in the linked list
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; ++i) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position to insert.\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to insert a new node at the end of the linked list
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the beginning of the linked list
void deleteBegin(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from the beginning.\n");
    } else {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Function to delete a node from a specified position in the linked list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from specified position.\n");
    } else {
        struct Node* temp = *head;

        if (position == 1) {
            *head = (*head)->next;
            free(temp);
            return;
        }

        for (int i = 1; i < position - 1 && temp != NULL; ++i) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position to delete.\n");
        } else {
            struct Node* deletedNode = temp->next;
            temp->next = temp->next->next;
            free(deletedNode);
        }
    }
}

// Function to delete a node from the end of the linked list
void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from the end.\n");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

// Function to search for a value in the linked list
/*void searchValue(struct Node* head, int value) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Value %d not found in the list.\n", value);
}*/

// Function to display the elements of the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with menu
int main() {
    struct Node* head = NULL;
    int choice, value, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at specified position\n");
        printf("3. Insert at end\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from specified position\n");
        printf("6. Delete from end\n");
        //printf("7. Search for a value\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                insertBegin(&head, value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;
            case 3:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 4:
                deleteBegin(&head);
                break;
            case 5:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 6:
                deleteEnd(&head);
                break;
            /*case 7:
                printf("Enter the value to search for: ");
                scanf("%d", &value);
                searchValue(head, value);
                break;*/
            case 7:
                printf("Linked List: ");
                displayList(head);
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 9);

    return 0;
}
