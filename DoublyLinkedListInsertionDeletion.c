#include<stdio.h>
#include<stdlib.h>

struct linkedList {
    struct linkedList *prev;
    int data;
    struct linkedList *next;
};
typedef struct linkedList node;

node *head = NULL;

node *createNode(node *ptr, int  value) {
    ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    return ptr;
}

int isEmpty() {
    if(head == NULL) {
        return 1;
    }
    return 0;
}

void display() {
    if(isEmpty()) {
        return; 
    }
    
    node *p = head;
    while(p != NULL) {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}

void insertAtHead(int value) {
    node *ptr = createNode(ptr, value);
    
    if(isEmpty()) {
        ptr->next = NULL;
        head = ptr;
    }
    else {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
}

void insertAtEnd(int value) {
    node *ptr = createNode(ptr, value);
    
    if(isEmpty()) {
        ptr->next = NULL;
        head = ptr;
    }
    else {
        node *p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = ptr;
        ptr->prev = p;
        ptr->next = NULL;
    }
}

void insertAtIndex(int index, int value) {
    node *ptr = createNode(ptr, value);
    
    if(isEmpty()) {
        ptr->next = NULL;
        head = ptr;
    }
    else {
        node *p = head;
        node *q = head->next;

        int i = 0;
        while(i < index-1) {
            p = p->next;
            q = q->next;
            i++;
        }

        p->next = ptr;
        ptr->next = q;
        ptr->prev = p;
        q->prev = ptr;
    }
}

int deleteAtHead() {
    if(isEmpty()) {
        return -999;
    }
    else {
        node *temp = head;

        head = head->next;
        
        int value = temp->data;
        free(temp);
        return value;
    }
}

int deleteAtEnd() {
    if(isEmpty()) {
        return -999;
    }
    else {
        node *p = head;
        node *q = head->next;
        
        while(q->next != NULL) {
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        
        int value = q->data;
        free(q);
        return value;
    }
}

int deleteAtIndex(int index) {
    if(isEmpty()) {
        return -999;
    }
    else {
        node *p = head;
        node *q = head->next;
        node *r = q->next;
        
        int i = 0;
        while(i < index-1) {
            p = p->next;
            q = q->next;
            r = r->next;
            i++;
        }
        
        int value = q->data;
        p->next = r;
        r->prev = p;
        free(q);
        return value;
    }
}

int main() {
    insertAtHead(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);

    display();

    insertAtIndex(2, 100);
    display();

    deleteAtHead();
    display();

    deleteAtEnd();
    display();

    deleteAtIndex(1);
    display();

    return 0;
}
