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
    int move_to_play;
    char **board;
    struct s_node **next;
}   node;

node    *creat_board();
void    init_node(node *new);
void    copy_node(node *old);
void    free_node(node *to_free);

#endif CONNECT_N_H