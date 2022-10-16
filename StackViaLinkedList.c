#include<stdio.h>
#include<stdlib.h>

struct stack {
    int data;
    struct stack *next;
};
typedef struct stack node;

node *top = NULL;

int isEmpty() {
    if(top == NULL) {
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
        node *p = top;
        while(p != NULL) {
            printf("%d  ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void push(int value) {
    node *ptr = createNode(ptr, value);
    ptr->next = top;
    top = ptr;
}

int pop() {
    if(isEmpty()) {
        printf("Stack underflow!\n");
    }
    else {
        int value = top->data;
        top = top->next;
        return value;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();

    printf("Element %d was popped out!\n", pop());
    printf("Element %d was popped out!\n", pop());
    display();

    pop();
    pop();
    pop();

    pop();

    return 0;
}
