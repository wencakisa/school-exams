#include <stdio.h>
#include <string.h>

#include "strfind.h"

#define MAX_DECK_LEN 401
#define DEFAULT_DECK "23456789TJQKA"
#define DEFAULT_SUITS "CDHS"

int main() {
    char deck[MAX_DECK_LEN];
    fgets(deck, MAX_DECK_LEN, stdin);

    for(int i = 0; i < strlen(deck); i += 2) {
        if(find(deck[i], DEFAULT_DECK) && find(deck[i + 1], DEFAULT_SUITS)) {
            char current_card = deck[i];
            char current_suit = deck[i + 1];
            int current_count = 1;

            for(int j = i + 2; j < strlen(deck); j += 2) {
                if(deck[j] == current_card && deck[j + 1] == current_suit) {
                    deck[j] = ' ';
                    deck[j + 1] = ' ';
                    current_count++;
                }
            }

            printf("%c%c - %d\n", current_card, current_suit, current_count);
        }

    }

    return 0;
}
