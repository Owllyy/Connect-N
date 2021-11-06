#include "algo.h"

node *creat_board()
{
    int i = 0;
    node *new = malloc(sizeof(node));
    new->board = malloc(sizeof(char *) * width);
    new->move_to_play = -1;
    while(i < width)
    {
        new->board[i] = malloc(sizeof(char *) * height);
        i++;
    }
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

void    copy_node(node *old)
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