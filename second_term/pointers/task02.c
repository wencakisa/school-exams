#include <stdio.h>

#define SIZE 8

int is_between(int*, int*, int*);
void rotate_right(int*, int*);
int* rotate(int*, int*, int*);
void print_array(int*, int);

int main() {
    int arr[SIZE];

    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }

    print_array(arr, SIZE);
    printf("%d\n", *rotate(&arr[0], &arr[4], &arr[SIZE - 1]));
    print_array(arr, SIZE);

    return 0;
}

int is_between(int *first, int *middle, int *last) {
    return (first <= middle) && (middle <= last);
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void rotate_right(int *start, int *end) {
    for (; start < end; start++) {
        swap(start, end - 1);
    }
}

int* rotate(int *first, int *middle, int *last) {
    if (is_between(first, middle, last)) {
        for (; first < middle; first++) {
            rotate_right(first, middle);
        }

        return first;
    }

    return NULL;
}

void print_array(int *arr, int size) {
    printf("{ ");
    for (size_t i = 0; i < size; i++) {
        printf((i < size - 1) ? "%d, " : "%d }\n", arr[i]);
    }
}
