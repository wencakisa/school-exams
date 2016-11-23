#include <stdio.h>
#include <string.h>

int main() {
    char s[43];

    while(scanf("%s", s) && strcmp(s, "PanGalacticGargleBlaster")) {
        for(int i = 0; i < strlen(s); i++) s[i] -= (s[i] >= 'a' && s[i] <= 'z') ? ' ' : '\0';

        printf("%s\n", s);
    }

    return 0;
}
