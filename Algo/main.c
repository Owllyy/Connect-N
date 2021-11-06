#include "algo.h"

int width = 7;
int height = 6;
char move_to_win = 4;
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

int main()
{
    node *x;

	x = first_node(-1);
	build_tree(x, 7, INT_MIN, INT_MAX, 1);
	debug_print_node(best_end);
	free_node(x);
    // printf("%d\n", evaluate_board(best_end));
};