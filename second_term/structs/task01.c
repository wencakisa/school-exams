#include <stdio.h>

#define DEFAULT_SIZE 5

int is_with_two_digits(int);
int how_many_under_two_digits(int*);

int main() {
    int arr[DEFAULT_SIZE];

    for(size_t i = 0; i < DEFAULT_SIZE; i++) {
        arr[i] = (i % 2) ? i : i + 10;
    }

    printf("%d\n", how_many_under_two_digits(arr));

    return 0;
}

int is_with_two_digits(int num) {
    int result = 0;

    for(; num > 0; result++, num /= 10);

    return (result == 2);
}

int how_many_under_two_digits(int *arr) {
    int result = 0;

    for(size_t i = 0; i < DEFAULT_SIZE; i++) {
        if(is_with_two_digits(arr[i])) {
            result++;
        }
    }

    return result;
}
