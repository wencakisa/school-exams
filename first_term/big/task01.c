#include <stdio.h>
#include <string.h>

#include "strfind.h"

#define DECK_LEN 14
#define DEFAULT_DECK "23456789TJQKA"

int main() {
    char deck[DECK_LEN];
    fgets(deck, DECK_LEN, stdin);

    for(int i = 0; i < strlen(deck); i++) {
        if(find(deck[i], DEFAULT_DECK)) {
            char current_card = deck[i];
            int current_count = 1;

            for(int j = i + 1; j < strlen(deck); j++) {
                if(current_card == deck[j]) {
                    deck[j] = ' ';
                    current_count++;
                }
            }

            printf("%c - %d\n", current_card, current_count);
        }
    }

    return 0;
}
