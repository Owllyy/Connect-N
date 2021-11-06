#include "algo.h"

node *creat_board()
{
    int i = 0;
    node *new = malloc(sizeof(node));
    node **next = malloc(sizeof(node *) * width);
    new->board = malloc(sizeof(char *) * width);
    new->move_to_play = -1;
    while(i < width)
    {
        new->board[i] = malloc(sizeof(char *) * height);
        i++;
    }
    return (new);
}

node *first_node(int move)
{
    node *new = creat_board();
    if (move != -1)
        new->board[move][0] = 2;
    return (new);
}

void    init_node(node *new)
{
    int i = 0;
    int j;
    while (i < width)
    {
        j = 0;
        while (j < height)
        {
            new->board[i][j] = 0;
            j++;
        }
        i++;
    }
}

void    play_move(node *new, int move, int player)
{
    int i = 0;

    while (i < height && new->board[move][i])
        i++;
    if (i < height)
    {
        if (player)
            new->board[move][i] = 1;
        else
            new->board[move][i] = 2;
    }
}

node    *copy_node(node *old, int move)
{
    int i = 0;
    int j;
    node *new = creat_board();
    while (i < width)
    {
        j = 0;
        while (j < height)
        {
            new->board[i][j] = old->board[i][j];
            j++;
        }
        i++;
    }
    new->move_to_play = move;
    new->father = old;
    old->next[i] = new;
    return (new);
}

node **new_child(node *old)
{
    int i = 0;
    node **new = malloc(sizeof(node *) * width);
    while (i < width)
    {
        new[i] = copy_node(old, i);
        new[i]
        i++;
    }
    return (new);
}

void    update_current(int move)
{
    if (current_move->next[move])
        current_move = current_move->next[move];
}

void    update_tree()
{
    node *next;

    next = best_end;
    while (next->father)
    {
        if (next->father = current_move)
            current_move = next;
        next->score = best_end->score;
        next = next->father;
    }
}

void    free_node(node *to_free)
{
    int i = 0;

    while(i < width)
    {
        free(to_free->board[i]);
        i++;
    }
    free(to_free->board);
    free(to_free);
}