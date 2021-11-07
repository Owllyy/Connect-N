#include "algo.h"

node *creat_board()
{
    int i = 0;
    node *new = malloc(sizeof(node));
    new->board = malloc(sizeof(char *) * width);
    new->next = 0;
    new->player = 0;
	new->score = INT_MIN;
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
	init_node(new);
    if (move != -1)
    {
        new->board[move][0] = 2;
        new->player = 0;
    }
    else
    {
	    new->board[width / 2][0] = 1;
        our_play = width / 2;
        new->player = 1;
        new->score = INT_MAX;
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

void    free_node(node *new)
{
    if (new)
    {
        for (int i = 0; i < width; i++)
        {
            free(new->board[i]);
        }
        free(new->board);
        free(new->next);
        free(new);
    }
}

int    play_move(node *new, int move, int player)
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
        return (1);
    }
    free_node(new);
    return (0);
}

node    *copy_node(node *old)
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
	if (old->next)
    	old->next[i] = new;
    return (new);
}

node **new_child(node *old)
{
    int i = 0;
    node **new = malloc(sizeof(node *) * width);
    while (i < width)
    {
        new[i] = copy_node(old);
        if (old->player)
            new[i]->player = 0;
        else
            new[i]->player = 1;
        if (!play_move(new[i], i, new[i]->player))
            new[i] = 0;
        i++;
    }
    return (new);
}
