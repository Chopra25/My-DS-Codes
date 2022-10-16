#include<stdio.h>
#include<stdlib.h>

struct queue {
    int data;
    struct queue *next;
};
typedef struct queue node;

node *front = NULL;
node *rear = NULL;

int isEmpty() {
    if(front == NULL) {
        return 1;
    }
    return 0;
}

node *createNode(node *ptr, int value) {
    ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    return ptr;
}

void display() {
    if(!isEmpty()) {
        node *p = front;
        while(p != rear) {
            printf("%d  ", p->data);
            p = p->next;
        }
        printf("%d\n", p->data);
    }
}

void insert(int value) {
    node *ptr = createNode(ptr, value);

    if(isEmpty()) {
        ptr->next = rear;
        front = rear = ptr;
    }
    else {
        rear->next = ptr;
        rear = ptr;
    }
}

int delete() {
    if(isEmpty()) {
        printf("Queue underflow!\n");
    }
    else if(front == rear) {
        int value = front->data;
        front = rear = NULL;
        return value;
    }
    else {
        int value = front->data;
        front = front->next;
        return value;
    }
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    display();

    printf("Element %d was deleted out!\n", delete());
    printf("Element %d was deleted out!\n", delete());
    display();

    delete();
    delete();
    delete();

    delete();

    return 0;
}
