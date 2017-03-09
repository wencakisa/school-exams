#include <stdio.h>

#define MAX_GAMES 5
#define MAX_NAME_LEN 25

typedef struct volleyball_game_t {
    int first_team_pts;
    int second_team_pts;
} volleyball_game_t;

typedef struct volleyball_match_t {
    char first_team_name[MAX_NAME_LEN];
    char second_team_name[MAX_NAME_LEN];
    int played_games;
    volleyball_game_t games[MAX_GAMES];
} volleyball_match_t;

void print_game_stats(volleyball_match_t);

int main() {
    volleyball_game_t first_game = {
        .first_team_pts = 25,
        .second_team_pts = 20
    };

    volleyball_game_t second_game = {
        .first_team_pts = 28,
        .second_team_pts = 26
    };

    volleyball_game_t third_game = {
        .first_team_pts = 25,
        .second_team_pts = 23
    };

    volleyball_match_t match = {
        .first_team_name = "Bulgaria",
        .second_team_name = "Mexico",
        .played_games = 3,
        .games = { first_game, second_game, third_game }
    };

    print_game_stats(match);

    return 0;
}

void print_game_stats(volleyball_match_t match) {
    for(size_t i = 0; i < match.played_games; i++) {
        printf(
            "%s %d : %d %s\n",
            match.first_team_name, match.games[i].first_team_pts,
            match.games[i].second_team_pts, match.second_team_name
        );
    }
}
