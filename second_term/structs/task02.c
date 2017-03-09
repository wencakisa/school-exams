#include <stdio.h>

#define NORMAL_GAME_MAX_POINTS 25

typedef struct volleyball_game_t {
    int first_team_pts;
    int second_team_pts;
} volleyball_game_t;

int is_game_winner(int, int);
int get_game_winner(volleyball_game_t);

int main() {
    volleyball_game_t game = {
        .first_team_pts = 25,
        .second_team_pts = 20
    };

    printf("%d\n", get_game_winner(game));

    game.first_team_pts = 27;
    game.second_team_pts = 26;
    printf("%d\n", get_game_winner(game));

    game.second_team_pts = 29;
    printf("%d\n", get_game_winner(game));

    game.first_team_pts = 10;
    game.second_team_pts = 15;
    printf("%d\n", get_game_winner(game));

    return 0;
}

int is_game_winner(int first_team_pts, int second_team_pts) {
    if(first_team_pts > second_team_pts) {
        if(first_team_pts == NORMAL_GAME_MAX_POINTS) {
            if(second_team_pts < NORMAL_GAME_MAX_POINTS - 1) {
                return 1;
            }
        } else if(first_team_pts > NORMAL_GAME_MAX_POINTS) {
            if(first_team_pts - NORMAL_GAME_MAX_POINTS >= 2) {
                return 1;
            }
        }
    }

    return 0;
}

int get_game_winner(volleyball_game_t game) {
    if(is_game_winner(game.first_team_pts, game.second_team_pts)) {
        return -1;
    } else if(is_game_winner(game.second_team_pts, game.first_team_pts)) {
        return 1;
    }

    return 0;
}
