#include "algo.h"

int width = 7;
int height = 6;
char move_to_win = 4;
int opponent_move = 3;
node *best_end = 0;
node *current_move = 0;

void	debug_print_node(node *x)
{
	for (int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			printf("%d ",x->board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("plyr = %d, mve = %d, score = %d, end = %d, next = %p, father = %p\n"
	, x->player, x->move_to_play, x->score, x->end, x->next, x->father);
}

void    recursiv_free(node *save)
{
    int i = 0;
    while (i < width)
    {
        if (save->next && save->next[i])
            recursiv_free(save->next[i]);
        if (save->next && save->next[i] != current_move)
            free_node(save->next[i]);
        i++;
    }
}

void    change_current()
{
    node *save = current_move;
    current_move = current_move->next[opponent_move];
    current_move->father = 0;
    recursiv_free(save);
}

void    choose_play()
{
    int i = 0;
    int saver = 0;
    node *save = current_move;
    for (int j = 0; j < width; j++)
    {
        if (save->next[i]->score > saver)
        {
            i = j;
            saver = save->score;
        }
    }
    current_move = current_move->next[i];
    current_move->father = 0;
    recursiv_free(save);
}

int main()
{
    node *x;

	x = first_node(-1);
    current_move = x;
	debug_print_node(current_move);
	build_tree(current_move, 3, INT_MIN, INT_MAX, 0);
    change_current();
	debug_print_node(current_move);
    build_tree(current_move, 3, INT_MIN, INT_MAX, 1);
    change_current();
	debug_print_node(current_move);
    build_tree(current_move, 3, INT_MIN, INT_MAX, 0);
    change_current();
	debug_print_node(current_move);
    build_tree(current_move, 3, INT_MIN, INT_MAX, 1);
    change_current();
	debug_print_node(current_move);
	free_node(x);
    // printf("%d\n", evaluate_board(best_end));
};

//change current;
//search from best_outcome;
//update node;
//free_node;
