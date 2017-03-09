#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 25
#define NORMAL_GAME_MAX_POINTS 25
#define TIEBREAK_GAME_MAX_POINTS 15
#define MAX_GAMES 5
#define WINNING_GAMES_COUNT 3
#define TIEBREAK_GAMES 2

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

int is_game_winner(int, int, int);
int get_game_winner(volleyball_game_t, int);
int get_normal_game_winner(volleyball_game_t);
int is_tiebreak(int, int);
int get_tiebreak_game_winner(volleyball_game_t);
int get_match_winner(volleyball_match_t);
void print_match_winner(volleyball_match_t);

int main() {
    volleyball_game_t first_game = {
        .first_team_pts = 25,
        .second_team_pts = 20
    };

    volleyball_game_t second_game = {
        .first_team_pts = 18,
        .second_team_pts = 25
    };

    volleyball_game_t third_game = {
        .first_team_pts = 25,
        .second_team_pts = 20
    };

    volleyball_game_t fourth_game = {
        .first_team_pts = 19,
        .second_team_pts = 25
    };

    volleyball_game_t tiebreak_game = {
        .first_team_pts = 15,
        .second_team_pts = 13
    };

    volleyball_match_t match = {
        .first_team_name = "Bulgaria",
        .second_team_name = "Serbia",
        .played_games = 5,
        .games = {
            first_game,
            second_game,
            third_game,
            fourth_game,
            tiebreak_game
        }
    };

    print_match_winner(match);

    // Let's say that the second team wins this time.
    match.games[4].first_team_pts = 12;
    match.games[4].second_team_pts = 15;

    print_match_winner(match);

    return 0;
}

int is_game_winner(int first_team_pts, int second_team_pts, int max_pts) {
    if(first_team_pts > second_team_pts) {
        if(first_team_pts == max_pts) {
            if(second_team_pts < max_pts - 1) {
                return 1;
            }
        } else if(first_team_pts > max_pts) {
            if(first_team_pts - second_team_pts >= 2) {
                return 1;
            }
        }
    }

    return 0;
}

int get_game_winner(volleyball_game_t game, int max_pts) {
    if(is_game_winner(game.first_team_pts, game.second_team_pts, max_pts)) {
        return -1;
    } else if(is_game_winner(game.second_team_pts, game.first_team_pts, max_pts)) {
        return 1;
    }

    return 0;
}

int get_normal_game_winner(volleyball_game_t game) {
    return get_game_winner(game, NORMAL_GAME_MAX_POINTS);
}

int is_tiebreak(int first_team_games, int second_team_games) {
    return (first_team_games == TIEBREAK_GAMES) && (second_team_games == first_team_games);
}

int get_tiebreak_game_winner(volleyball_game_t game) {
    return get_game_winner(game, TIEBREAK_GAME_MAX_POINTS);
}

int get_match_winner(volleyball_match_t match) {
    int first_team_games = 0, second_team_games = 0;

    for(size_t i = 0; i < match.played_games; i++) {
        volleyball_game_t current_game = match.games[i];
        int current_winner = get_normal_game_winner(current_game);

        if(current_winner == -1) {
            first_team_games++;
        } else if(current_winner == 1) {
            second_team_games++;
        } else {
            if(is_tiebreak(first_team_games, second_team_games)) {
                return get_tiebreak_game_winner(current_game);
            }
        }

        if(first_team_games == WINNING_GAMES_COUNT && second_team_games < WINNING_GAMES_COUNT) {
            return -1;
        } else if(second_team_games == WINNING_GAMES_COUNT && first_team_games < WINNING_GAMES_COUNT) {
            return 1;
        }
    }
}

void print_match_winner(volleyball_match_t match) {
    char winner_name[MAX_NAME_LEN];

    if(get_match_winner(match) == -1) {
        strcpy(winner_name, match.first_team_name);
    } else if(get_match_winner(match) == 1) {
        strcpy(winner_name, match.second_team_name);
    }

    printf("%s wins!\n", winner_name);
}
