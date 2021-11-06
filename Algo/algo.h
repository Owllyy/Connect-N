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
int move;

typedef struct s_node
{
    char end;
    int move_to_play;
    int score;
    char **board;
    struct s_node **next;
}   node;

node    *creat_board();
void    init_node(node *new);
node    *copy_node(node *old, int move, int player);
void    free_node(node *to_free);

int evaluate_board(node *arg);

#endif CONNECT_N_H