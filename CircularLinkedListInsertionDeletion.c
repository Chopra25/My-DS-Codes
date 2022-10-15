#include<stdio.h>
#include<stdlib.h>

struct linkedList {
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
    while(p->next != head) {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("%d  ", p->data);
    printf("\n");
}

// Changes to O(n)
void insertAtHead(int value) {
    node *ptr = createNode(ptr, value);
    
    if(isEmpty()) {
        head = ptr;
        ptr->next = head;
    }
    else {
        node *p = head;

        while(p->next != head) {
            p = p->next;
        }

        ptr->next = head;
        p->next = ptr;
        head = ptr;
    }
}

void insertAtEnd(int value) {
    node *ptr = createNode(ptr, value);
    
    if(isEmpty()) {
        head = ptr;
        ptr->next = head;
    }
    else {
        node *p = head;
        while(p->next != head) {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = head;
    }
}

void insertAtIndex(int index, int value) {
    node *ptr = createNode(ptr, value);
    
    if(isEmpty()) {
        head = ptr;
        ptr->next = head;
    }
    else {
        node *p = head;

        int i = 0;
        while(i < index-1) {
            p = p->next;
            i++;
        }

        ptr->next = p->next;
        p->next = ptr;
    }
}

// Changes to O(n)
int deleteAtHead() {
    if(isEmpty()) {
        return -999;
    }
    else if(head->next == head) {
        int value = head->data;
        head = NULL;  
        free(head);  
        return value;
    }
    else {
        node *p = head;

        while(p->next != head) {
            p = p->next;
        }

        p->next = head->next;

        int value = head->data;
        free(head);

        head = p->next;

        return value;
    }
}

int deleteAtEnd() {
    if(isEmpty()) {
        return -999;
    }
    else if(head->next == head) {
        int value = head->data;
        head = NULL;  
        free(head);  
        return value;
    }
    else {
        node *p = head;
        node *q = head->next;
        
        while(q->next != head) {
            p = p->next;
            q = q->next;
        }
        p->next = head;
        
        int value = q->data;
        free(q);
        return value;
    }
}

int deleteAtIndex(int index) {
    if(isEmpty()) {
        return -999;
    }
    else if(head->next == head) {
        int value = head->data;
        head = NULL;  
        free(head);  
        return value;
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
        
        int value = q->data;
        p->next = q->next;
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
