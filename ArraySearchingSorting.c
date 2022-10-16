#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

int array[MAXSIZE];
int size;

int linearSearch(int value) {
    int index = -1;
    for(int i = 0; i < size; i++) {
        if(array[i] == value) {
            index = i;
            break;
        }
    }
    return index;
}

int binarySearch(int value, int low, int high) {
    int mid = (low + high) / 2;

    if(value == array[mid]) {
        return mid;
    }
    else if(value < array[mid]) {
        return binarySearch(value, low, mid-1);
    }
    else {
        return binarySearch(value, mid+1, high);
    }
    return -1;
}

int binarySearchIterative(int value) {
    int low = 0;
    int high = size-1;

    int mid = (low + high) / 2;

    if(value == array[mid]) {
        return mid;
    }
    else if(value < array[mid]) {
        high = mid - 1;
    }
    else {
        low = mid + 1;
    }
    return -1;
}


void  bubbleSort(int array[]) {
    int temp = 0;
    
    for(int i = size; i > 1; i--) {
        for(int j = 0; j <= i-2; i++) {
            if(array[j] >= array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

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
    insert(2, 15);
    insert(3, 30);
    insert(4, 25);

    display();

    insert(2, 100);
    display();

    delete(1);
    display();

    int index = linearSearch(15);
    if(index != -1) {
        printf("Element found at index %d\n", index);
    }

    bubbleSort(array);
    printf("After sorting\n");
    display();

    index = binarySearch(30, 0, size - 1);
    if(index != -1) {
        printf("Element found at index %d\n", index);
    }

    index = binarySearchIterative(25);
    if(index != -1) {
        printf("Element found at index %d\n", index);
    }
    
    return 0;
}
