#include "algo.h"

int first = 0;
int our_play = 0;

void timer(void)
{

	if (!first)
	{
		current_move = first_node(opponent_move);
		if (opponent_move != -1)
		{
			build_tree(current_move, 4, INT_MIN, INT_MAX, 7);
			choose_play();
		}
		first++;
	}
	else
	{
		opo_move(opponent_move);
		build_tree(current_move, 4, INT_MIN, INT_MAX, 7);
		choose_play();
	}
	printf("%d\n", our_play);
	fflush(stdout);
}
