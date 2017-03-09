#include <string.h>

#include "strfind.h"

int find(char needle, char *haystack) {
    for(int i = 0; i < strlen(haystack); i++) {
        if(haystack[i] == needle) {
            return 1;
        }
    }

    return 0;
}
