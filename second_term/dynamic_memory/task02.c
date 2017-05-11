#include <stdio.h>

#define SIZE 10

typedef struct array_t {
    int arr[SIZE];
    int count;
} array_t;

array_t init_from_1_to_n(int);
void swap(int*, int*);
void reverse(array_t*);
void print_array(int*, int);
void print_array_info(array_t);

int main() {
    array_t array = init_from_1_to_n(SIZE);

    print_array_info(array);
    reverse(&array);
    print_array_info(array);

    return 0;
}

array_t init_from_1_to_n(int n) {
    array_t result = { .count = n };

    for (size_t i = 0; i < result.count; i++) {
        result.arr[i] = i + 1;
    }

    return result;
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void reverse(array_t *array) {
    int count = array->count - 1;

    for (size_t i = 0; i <= count; i++) {
        swap(&array->arr[i], &array->arr[count--]);
    }
}

void print_array(int *array, int count) {
    printf("[");
    for (size_t i = 0; i < count; i++) {
        printf((i < count - 1) ? "%d, " : "%d", array[i]);
    }
    printf("]\n");
}

void print_array_info(array_t array) {
    print_array(array.arr, array.count);
    printf("Current count: %d\n", array.count);
}
