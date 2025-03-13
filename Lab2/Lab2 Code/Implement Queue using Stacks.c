
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a stack structure
typedef struct {
    int* data;    
    int top;      
    int capacity; 
} Stack;


Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1; 
    stack->data = (int*)malloc(capacity * sizeof(int));
    return stack;
}

bool isStackEmpty(Stack* stack) {
    return (stack->top == -1);
}

// pushing an element on the stack
void push(Stack* stack, int x) {
    if (stack->top == stack->capacity - 1) return; 
    stack->data[++stack->top] = x;
}

// pop an element 
int pop(Stack* stack) {
    if (isStackEmpty(stack)) return -1; 
    return stack->data[stack->top--];
}

// peek the top element 
int peek(Stack* stack) {
    if (isStackEmpty(stack)) return -1; // if stack is empty, return -1
    return stack->data[stack->top];
}

// Define the MyQueue structure
typedef struct {
    Stack* s1; // stack for pushing new elements
    Stack* s2; // stack for reversing order
} MyQueue;

// create a new queue
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->s1 = createStack(100); // create stack with max size 100
    queue->s2 = createStack(100);
    return queue;
}

// push an element to the back of the queue
void myQueuePush(MyQueue* obj, int x) {
    push(obj->s1, x); // push onto s1
}

// pop an element from the front of the queue
int myQueuePop(MyQueue* obj) {
    // move all elements from s1 to s2
    if (isStackEmpty(obj->s2)) {
        while (!isStackEmpty(obj->s1)) {
            push(obj->s2, pop(obj->s1));
        }
    }
    // pop from s2
    return pop(obj->s2);
}

// get the front element 
int myQueuePeek(MyQueue* obj) {
    //  move elements from s1 to s2
    if (isStackEmpty(obj->s2)) {
        while (!isStackEmpty(obj->s1)) {
            push(obj->s2, pop(obj->s1));
        }
    }
    // returning the front 
    return peek(obj->s2);
}

// check for  empty queue 
bool myQueueEmpty(MyQueue* obj) {
    return isStackEmpty(obj->s1) && isStackEmpty(obj->s2);
}

// Free memory 
void myQueueFree(MyQueue* obj) {
    free(obj->s1->data);
    free(obj->s2->data);
    free(obj->s1);
    free(obj->s2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */