//
// Created by paulm on 05/04/2024.
//
#include <iostream>

void create_array(int **A, int size) {
    *A = new int[size];
}

int main() {
    int *myArray = nullptr;
    int size = 5;
    create_array(&myArray, size);

    for(int i = 0; i < size; i++) {
        myArray[i] = i * 2;
        std::cout << myArray[i] << " ";
    }

    delete[] myArray;

    return 0;
}
