#include <stdio.h>
#include <string.h>

int main() {
    char s[43];

    while(scanf("%s", s) && strcmp(s, "PanGalacticGargleBlaster")) {
        for(int i = 0; i < strlen(s); s[i] -= (s[i] >= 'a' && s[i] <= 'z') ? ' ' : '\0', i++);

        printf("%s\n", s);
    }

    return 0;
}
