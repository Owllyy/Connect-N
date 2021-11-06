#ifndef CONNECT_N_H
# define CONNECT_N_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <math.h>

int width;
int height;
char move_to_win;

typedef struct s_node
{
    char end;
    int player;
    int move_to_play;
    int score;
    char **board;
    struct s_node **next;
    struct s_node *father;
}   node;

node *best_end;
node *current_move;

node    *creat_board();
void    init_node(node *new);
node    *copy_node(node *old, int move);
void    free_node(node *to_free);
node    **new_child(node *old);


int evaluate_board(node *arg);
#endif