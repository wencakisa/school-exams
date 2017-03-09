#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 33

char *strconcat(char *dest, const char *src);

int main() {
    char seq1[MAX_LEN], seq2[MAX_LEN];

    printf("Enter first string: ");
    fgets(seq1, MAX_LEN, stdin);
    printf("Enter second string: ");
    fgets(seq2, MAX_LEN, stdin);

    printf("%s", strconcat(seq1, seq2));

    return 0;
}

char *strconcat(char *dest, const char *src) {
    int i, j;
    for (i = 0; dest[i] != '\n'; i++);

    for (j = 0; src[j] != '\0'; j++) {
        dest[i+j] = src[j];
    }

    dest[i+j] = '\0';

    return dest;
}
