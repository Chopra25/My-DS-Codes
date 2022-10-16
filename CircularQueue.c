#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

int queue[MAXSIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    if(front == -1) {
        return 1;
    }
    return 0;
}

int isFull() {
    if(front == (rear + 1) % MAXSIZE) {
        return 1;
    }
    return 0;
}

void display() {
    if(!isEmpty()) {
        for(int i = front; i <= rear; i++) {
            printf("%d  ", queue[i]);
        }
        printf("\n");
    }
}

void insert(int value) {
    if(isFull()) {
        printf("Queue overflow!\n");
    }
    else if(isEmpty()) {
        queue[++rear] = value;
        front++;
    }
    else {
        rear = (rear + 1) % MAXSIZE;
        queue[rear] = value;
    }
}

int delete() {
    if(isEmpty()) {
        printf("Stack underflow!\n");
    }
    else if(front == rear) {
        int value = queue[front];
        front = rear = -1;
        return value;
    }
    else {
        int value = queue[front];
        front = (front + 1) % MAXSIZE;
        return value;
    }
}

int peek(int index) {
    if(index >=front && index <= rear && !isEmpty()) {
        index = (front + index) % MAXSIZE;
        return queue[index];
    }
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    insert(70);
    insert(80);
    insert(90);
    insert(100);

    display();

    insert(1000);

    printf("Element %d was deleted out\n", delete());
    printf("Element %d was deleted out\n", delete());
    printf("Element %d was deleted out\n", delete());

    display();

    int index = 4;
    printf("Element at index %d is %d\n", index, peek(index));

    return 0;
}
