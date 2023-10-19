#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a queue
struct Queue {
    int front, rear, size;
    int arr[MAX_SIZE];
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == MAX_SIZE);
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->arr[queue->rear] = item;
    queue->size++;
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int item = queue->arr[queue->front];
    queue->front++;
    queue->size--;
    return item;
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();
    int choice, item;

    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;

            case 2:
                item = dequeue(queue);
                if (item != -1) {
                    printf("Dequeued element: %d\n", item);
                }
                break;

            case 3:
                display(queue);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
