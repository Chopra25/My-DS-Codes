#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

int stack[MAXSIZE];
int top = -1;

int isEmpty() {
    if(top == -1) {
        return 1;
    }
    return 0;
}

int isFull() {
    if(top == MAXSIZE-1) {
        return 1;
    }
    return 0;
}

void display() {
    if(!isEmpty()) {
        for(int i = top; i >= 0; i--) {
            printf("%d  ", stack[i]);
        }
        printf("\n");
    }
}

void push(int value) {
    if(isFull()) {
        printf("Stack overflow!\n");
    }
    else {
        stack[++top] = value;
    }
}

int pop() {
    if(isEmpty()) {
        printf("Stack underflow!\n");
    }
    else {
        return stack[top--];
    }
}

int peek(int index) {
    if(index >=0 && index <= top) {
        return stack[top - index];
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90);
    push(100);

    display();

    push(1000);

    printf("Element %d was popped out\n", pop());
    printf("Element %d was popped out\n", pop());
    printf("Element %d was popped out\n", pop());

    display();

    int index = 4;
    printf("Element at index %d is %d\n", index, peek(index));

    return 0;
}
