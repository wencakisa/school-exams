#include <stdio.h>
#include <string.h>

#define DECK_LEN 13
#define STRAIGHT_LEN 5
#define DEFAULT_DECK "23456789TJQKA"

int is_valid_card(char);
int has_straight(char*);

int main() {
    char deck[DECK_LEN];
    fgets(deck, DECK_LEN, stdin);

    printf((has_straight(deck)) ? "Has straight.\n" : "Has not straight.\n");

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

int has_straight(char* deck) {
    char part[STRAIGHT_LEN] = "";

    for(int i = 0, j = 0; i < strlen(deck); i++, j++) {
        char current_card = deck[i];

        if(is_valid_card(current_card)) {
            part[j] = current_card;

            if(j == STRAIGHT_LEN - 1) {
                j = 0;

                if(strstr(DEFAULT_DECK, part)) {
                    return 1;
                }
            }
        }
    }

    return 0;
}
