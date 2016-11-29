#include <stdio.h>
#include <string.h>

#define DECK_LEN 13
#define DEFAULT_DECK "23456789TJQKA"

int is_valid_card(char);

int main() {
    char deck[DECK_LEN];
    fgets(deck, DECK_LEN, stdin);

    for(int i = 0; i < strlen(deck); i++) {
        if(is_valid_card(deck[i])) {
            int current_count = 1;
            char current_card = deck[i];

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

int is_valid_card(char c) {
    for(int i = 0; i < strlen(DEFAULT_DECK); i++) {
        if(DEFAULT_DECK[i] == c) {
            return 1;
        }
    }

    return 0;
}
