#ifndef CONNECT_N_H
# define CONNECT_N_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <sys/time.h>

extern int width;
extern int height;
extern char move_to_win;
extern int opponent_move;
extern int our_play;
extern int first;

typedef struct s_node
{
    char **board;
    int player;
    int score;
    struct s_node **next;
}   node;

typedef struct s_board
{
	int					width;
	int					height;

	int					win_size;

	int					starting;	

	unsigned int		time_given;
	unsigned int		time_add;

	char	**board;
}	t_board;

typedef struct s_file
{
	int		fd;
	char	*file_path;
	char	*line;
}				t_file;

extern node *current_move;

void	debug_print_node(node *x);
node    *creat_board();
node    *copy_node(node *old);
void    init_node(node *new);
void    free_node(node *new);
node	*first_node(int move);
void    opo_move(int move);
void    choose_play();

node    **new_child(node *old);
int		evaluate_board(node *arg);

int    build_tree(node *old, int depth, int alpha, int beta, int max_player);
void    update_tree();


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	100
# endif


int					open_file(t_file *file);
int					close_file(t_file *file);
void				ft_init(t_board *board);
int					parse_params(t_file *file, t_board *board);
void				ft_err_putstr(char *str);
unsigned int		get_time(t_board *board);
int					get_next_line(int fd, char **line);
int					limit_reflexion(t_board *board, int nb_nodd);
unsigned int		ft_atoi(const char *str);
unsigned int 		timer(void);

#endif