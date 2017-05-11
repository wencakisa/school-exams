#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct dyn_array_t {
    int *arr;
    int current_count;
    int size;
} dyn_array_t;

dyn_array_t init();
void fill_array_from_n_to_size(dyn_array_t*, int);
void concat_arrays(dyn_array_t*, dyn_array_t*, dyn_array_t*);
dyn_array_t concat(dyn_array_t, dyn_array_t);
void print_array(int*, int);
void print_dyn_array_info(dyn_array_t);
void destroy(dyn_array_t*);

int main() {
    dyn_array_t first = init();
    fill_array_from_n_to_size(&first, 0);
    print_dyn_array_info(first);

    dyn_array_t second = init();
    fill_array_from_n_to_size(&second, SIZE);
    print_dyn_array_info(second);

    dyn_array_t result = concat(first, second);
    print_dyn_array_info(result);

    destroy(&first);
    destroy(&second);
    destroy(&result);

    return 0;
}

dyn_array_t init() {
    dyn_array_t result = {
        .arr = calloc(SIZE, sizeof(int)),
        .current_count = 0,
        .size = SIZE
    };

    return result;
}

void fill_array_from_n_to_size(dyn_array_t *array, int n) {
    for (size_t i = 0; i < array->size; i++) {
        array->arr[i] = n++;
        array->current_count++;
    }
}

void concat_arrays(dyn_array_t *src1, dyn_array_t *src2, dyn_array_t *result) {
    size_t i;
    for (i = 0; i < src1->current_count; i++) {
        result->arr[i] = src1->arr[i];
    }

    for (size_t j = 0; j < src2->current_count; j++, i++) {
        result->arr[i] = src2->arr[j];
    }
}

dyn_array_t concat(dyn_array_t first, dyn_array_t second) {
    dyn_array_t result = {
        .current_count = first.current_count + second.current_count,
        .size = first.size + second.size
    };
    result.arr = calloc(result.size, sizeof(int));

    concat_arrays(&first, &second, &result);

    return result;
}

void print_array(int *array, int size) {
    printf("[");
    for (size_t i = 0; i < size; i++) {
        printf((i < size - 1) ? "%d, " : "%d", array[i]);
    }
    printf("]\n");
}

void print_dyn_array_info(dyn_array_t array) {
    print_array(array.arr, array.size);
    printf("Current count: %d\n", array.current_count);
    printf("Size: %d\n", array.size);
}

void destroy(dyn_array_t *array) {
    array->current_count = 0;
    array->size = 0;
    free(array->arr);
    array->arr = NULL;
}
