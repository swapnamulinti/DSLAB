#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct node {
    int data;
    struct node *next;
};

// Queue structure holding front and rear pointers
struct queue {
    struct node *front, *rear;
};

// Initialize queue
void create_queue(struct queue *q) {
    q->front = q->rear = NULL;
}

// Enqueue operation - add element at rear
void enqueue(struct queue *q, int val) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;

    if (q->rear == NULL) { // Empty queue
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued to queue\n", val);
}

// Dequeue operation - remove element from front
void dequeue(struct queue *q) {
    if (q->front == NULL) {
        printf("Queue Underflow! The queue is empty.\n");
        return;
    }

    struct node *temp = q->front;
    printf("%d dequeued from queue\n", temp->data);
    q->front = q->front->next;

    // If front becomes NULL, then change rear also to NULL
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

// Peek operation - get front element without removing
int peek(struct queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

// Display all elements in the queue
void display(struct queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test queue operations
int main() {
    struct queue q;
    create_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    printf("Front element is: %d\n", peek(&q));

    dequeue(&q);
    display(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);  // Trying to dequeue from empty queue

    return 0;
}

