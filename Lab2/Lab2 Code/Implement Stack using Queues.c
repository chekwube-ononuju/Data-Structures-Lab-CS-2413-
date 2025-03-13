#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define  queue 
typedef struct {
    int* data;
    int front, rear, size, capacity;
} Queue;

//  initializing queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; // Circular queue logic
    queue->data = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// check if the queue is empty
bool isQueueEmpty(Queue* queue) {
    return (queue->size == 0);
}

// enqueue an element to the queue
void enqueue(Queue* queue, int item) {
    if (queue->size == queue->capacity)
        return; // queue is full
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size++;
}

// dequeue an element from the queue
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue))
        return -1;
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// get the front element of the queue
int queueFront(Queue* queue) {
    if (isQueueEmpty(queue))
        return -1;
    return queue->data[queue->front];
}

// define the MyStack struct using two queues
typedef struct {
    Queue* q1; // our main queue maintaining stack order
    Queue* q2; // temporary queue for reordering 
} MyStack;

// create a new stack
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue(100);  // Assuming a max size of 100
    stack->q2 = createQueue(100);
    return stack;
}

// push operation: Move all elements to q2, add new element, then move everything back
void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q2, x); // Insert new element into q2

    // move all elements from q1 to q2
    while (!isQueueEmpty(obj->q1)) {
        enqueue(obj->q2, dequeue(obj->q1));
    }

    // swap q1 and q2, so q1 always holds the correct stack order
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

// remove and return the front element of q1
int myStackPop(MyStack* obj) {
    if (isQueueEmpty(obj->q1)) return -1;
    return dequeue(obj->q1);
}

// return the front element of q1 without removing it
int myStackTop(MyStack* obj) {
    if (isQueueEmpty(obj->q1)) return -1;
    return queueFront(obj->q1);
}

// we check if the stack is empty
bool myStackEmpty(MyStack* obj) {
    return isQueueEmpty(obj->q1);
}

// Free allocated memory
void myStackFree(MyStack* obj) {
    free(obj->q1->data);
    free(obj->q2->data);
    free(obj->q1);
    free(obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
*/