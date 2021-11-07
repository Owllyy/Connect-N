#include "algo.h"

int	limit_reflexion(t_board *board, int nb_nodd)
{
	int	min;
	int	max;
	
	min = 1;
	max = 6;
	if (timer() < board->time_add && nb_nodd < max)
		nb_nodd ++;
	else if (timer() > board->time_add && nb_nodd > min)
		nb_nodd --;
	return (nb_nodd);
}