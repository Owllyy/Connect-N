#include "algo.h"

int width = 0;
int height = 0;
char move_to_win = 0;
int opponent_move = -1;
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

void    opo_move(int move)
{
    current_move->player = 0;
    current_move->score = INT_MIN;
    current_move->next = 0;
	int i = 0;
    while (i < height)
    {
        if (!current_move->board[move][i])
        {
            current_move->board[move][i] = 2;
            return ;
        }
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
        if (current_move->next[j] && current_move->next[j]->score > saver)
        {
            i = j;
            saver = current_move->next[j]->score;
        }
    }
    current_move = current_move->next[i];
	our_play = i;
    recursiv_free(save);
}

void	ft_err_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	execute(t_file *file, t_board *board, char *file_path, int fd)
{
	// int nb_nodd;
	
	// nb_nodd = 1;
	file->file_path = file_path;
	file->fd = fd;
	ft_init(board);
	if (!parse_params(file, board))
	{
		ft_err_putstr("Params are incorrect\n");
		return (0);
	}
	while (1)
	{
		fscanf(stdin, "%i", &opponent_move);
		// fflush(stdin);
		// opponent_move = atoi(file->line);
		board->time_given = get_time(board);
		// nb_nodd = limit_reflexion(board, nb_nodd);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_file	file;
	t_board	board;

    (void)argv;
	if (argc == 1)
	{
		execute(&file, &board, 0, 0);
		return (0);
	}
	else
		ft_err_putstr("ERROR");
	return (0);
}