#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

int array[MAXSIZE];
int size;

void insert(int index, int value) {
    if(size == MAXSIZE) {
        printf("Array is full!\n");
        return;
    }
    for(int i = size; i >= index; i--) {
        array[i+1] = array[i];
    }
    array[index] = value;
    size++;
    printf("%d was inserted at index %d\n", value, index);
}

void delete(int index) {
    if(size == 0) {
        printf("Array is empty!\n");
        return;
    }
    int value = array[index];
    for(int i = index; i <= size-2; i++) {
        array[i] = array[i+1];
    }
    size--;
    printf("%d was deleted from index %d\n", value, index);
}

void display() {
    for(int i = 0;i < size; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

int main() {
    insert(0, 10);
    insert(1, 20);
    insert(2, 30);
    insert(3, 40);
    insert(4, 50);

    display();

    insert(2, 100);

    display();

    delete(1);

    display();
    
    return 0;
}
