#ifndef CONNECT_N_H
# define CONNECT_N_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <math.h>

extern int width;
extern int height;
extern char move_to_win;
extern int opponent_move;

typedef struct s_node
{
    char **board;
    char end;
    int player;
    int move_to_play;
    int score;
    struct s_node **next;
    struct s_node *father;
}   node;

extern node *best_end;
extern node *current_move;

void	debug_print_node(node *x);
node    *creat_board();
node    *copy_node(node *old, int move);
void    init_node(node *new);
void    free_node(node *new);
node	*first_node(int move);


node    **new_child(node *old);
int		evaluate_board(node *arg);

int    build_tree(node *old, int depth, int alpha, int beta, int max_player);

#endif