#include "algo.h"

void	ft_init(t_board *board)
{
	board->width = -1;
	board->height = -1;
	board->win_size = -1;
	board->starting = -1;
	board->time_given = -1;
	board->time_add = -1;
}


int	parse_params(t_file *file, t_board *board)
{
	int	i;

	i = 0;
	int ret = 0;
	while (i < 6)
	{
		fscanf(stdin, "%d", &ret);
		if (i == 0)
        {
			board->width = ret;
            width = board->width;
        }
		else if (i == 1)
        {
			board->height = ret;
            height = board->height;
        }
		else if (i == 2)
        {
			board->win_size = ret;
            move_to_win = board->win_size;
        }
		else if (i == 3)
			board->starting = ret;
		else if (i == 4)
			board->time_given = ret;
		else if (i == 5)
			board->time_add = ret;
		i++;
	}
	if (board->starting == 1 || board->starting == 2)
	{
		if (board->starting == 1)
			printf("%d\n", width/2);
		else if (board->starting == 2)
			return (1);
	}
	timer();
	return (1);
}