#include "algo.h"

int width = 7;
int height = 6;
char move_to_win = 4;
int opponent_move = 3;
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
	printf("plyr = %d, score = %d, next = %p,\n"
	, x->player, x->score, x->next);
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

void    choose_play()
{
    int i = 0;
    int saver = INT_MIN;
    node *save = current_move;
    for (int j = 0; j < width; j++)
    {
        // debug_print_node(current_move->next[j]);
        if (current_move->next[j]->score > saver)
        {
            i = j;
            saver = current_move->next[j]->score;
        }
    }
    current_move = current_move->next[i];
    recursiv_free(save);
}

int main()
{
    node *x;

	x = first_node(3);
    current_move = x;
	build_tree(current_move, 10, INT_MIN, INT_MAX, 1);
    choose_play();
    debug_print_node(current_move);
};

