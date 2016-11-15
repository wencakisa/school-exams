#include <stdio.h>

int main() {
    char l;
    int n;

    scanf("%c", &l);
    scanf("%d", &n);

    while(l <= 'z') {
        printf("%c\n", l);
        l += n;
    }

    return 0;
}
