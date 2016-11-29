#include <stdio.h>
#include <string.h>

#define MAX_DECK_LEN 400
#define DEFAULT_DECK "23456789TJQKA"
#define DEFAULT_SUITS "CDHS"

int is_valid_card(char);
int is_valid_suit(char);

int main() {
    char deck[MAX_DECK_LEN];
    fgets(deck, MAX_DECK_LEN, stdin);

    for(int i = 0; i < strlen(deck); i += 2) {
        if(is_valid_card(deck[i]) && is_valid_suit(deck[i + 1])) {
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

int is_valid_card(char card) {
    for(int i = 0; i < strlen(DEFAULT_DECK); i++) {
        if(DEFAULT_DECK[i] == card) {
            return 1;
        }
    }

    return 0;
}

int is_valid_suit(char suit) {
    for(int i = 0; i < strlen(DEFAULT_SUITS); i++) {
        if(DEFAULT_SUITS[i] == suit) {
            return 1;
        }
    }

    return 0;
}
