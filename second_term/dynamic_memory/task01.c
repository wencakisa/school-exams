#include <stdio.h>

#define SIZE 10

typedef struct array_t {
    int arr[SIZE];
    int count;
} array_t;

array_t init_from_1_to_n(int);
array_t prepend(array_t, int);
void print_array(int*, int);
void print_array_info(array_t);

int main() {
    array_t array = init_from_1_to_n(SIZE / 2);

    print_array_info(array);
    print_array_info(prepend(array, 4));

    return 0;
}

array_t init_from_1_to_n(int n) {
    array_t result = { .count = n };

    for (size_t i = 0; i < result.count; i++) {
        result.arr[i] = i + 1;
    }

    return result;
}


array_t prepend(array_t array, int element) {
    if (array.count > SIZE) {
        return array;
    }

    array_t result = { .count = array.count + 1 };

    result.arr[0] = element;
    for (size_t i = 1; i <= result.count; i++) {
        result.arr[i] = array.arr[i - 1];
    }

    return result;
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
