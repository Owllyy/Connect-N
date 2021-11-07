#include "algo.h"

int first = 0;
int our_play = 0;

unsigned int timer(void)
{
	struct timeval start, end;
	unsigned int	j;

  	gettimeofday(&start, NULL);
	
	if (!first)
	{
		current_move = first_node(opponent_move);
		if (opponent_move != -1)
		{
			build_tree(current_move, 4, INT_MIN, INT_MAX, 7);
			choose_play();
		}
		// else
		// 	debug_print_node(current_move);
		first++;
	}
	else
	{
		// printf("OPO = %d\n", opponent_move);
		opo_move(opponent_move);
		build_tree(current_move, 4, INT_MIN, INT_MAX, 7);
		choose_play();
	}
	// debug_print_node(current_move);
	printf("%d\n", our_play);
	fflush(stdout);

  	gettimeofday(&end, NULL);

  	j = ((end.tv_sec * 1000 + end.tv_usec / 1000) - 
    (start.tv_sec * 1000 + start.tv_usec / 1000));
	return (j);
}

unsigned int	get_time(t_board *board)
{
	board->time_given = (board->time_given - timer() + board->time_add);
	return(board->time_given);
}