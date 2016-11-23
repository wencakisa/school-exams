#include <stdio.h>
#include <string.h>

#define MAX_LEN 42
#define MAGIC_WORD "PanGalacticGargleBlaster"

int is_lowercase(char);
char to_uppercase(char);
void convert_to_uppercase(char*);
int is_magical(char*);

int main() {
    char str[MAX_LEN];

    while(scanf("%s", str) && !is_magical(str)) {
        convert_to_uppercase(str);
        printf("%s\n", str);
    }

    return 0;
}

int is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

char to_uppercase(char c) {
    if(is_lowercase(c)) {
        c -= ' ';
    }

    return c;
}

void convert_to_uppercase(char* str) {
    for(int i = 0; i < strlen(str); i++) {
        str[i] = to_uppercase(str[i]);
    }
}

int is_magical(char* str) {
    return !strcmp(str, MAGIC_WORD);
}
