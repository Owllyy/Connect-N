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

void	clean_buffer(int *buffer)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		buffer[i] = -1;
		i++;
	}
}

int	check_params(t_board *board)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (((int *)board)[i] == -1)
			return (0);
		i++;
	}
	return (1);
}

size_t  ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned int	ft_atoi(const char *str)
{
	size_t			i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (str[i] != '\n' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		i ++;
	}
	return (result);
}

char    *ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;
	size_t	len;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = -1;
	j = -1;
	if (!(str = malloc(sizeof(char) * len)))
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = 0;
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = 0;
	return (str);
}

char    *ft_strdup(char *s1)
{
	char    *strdup;
	int     i;

	i = 0;
	if (!(strdup = malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (0);
	while (s1[i])
	{
		strdup[i] = s1[i];
		i++;
	}
	strdup[i] = '\0';
	return (strdup);
}

int				ft_find_nl_eol(const char *s, int ret)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (i);
	if (s[i] == '\0' && ret == 0)
		return (-2);
	return (-1);
}

char			*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;
	size_t		size;

	size = ft_strlen(&s[start]);
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (size < len)
		len = size;
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

int				ft_liner(char **line, char **save, int ret, int nl)
{
	char *buffer;

	if (ret == 0 && !(*save))
	{
		if (!(*line = malloc(1)))
			return (-1);
		**line = 0;
		return (0);
	}
	if (ret == 0)
		nl = ft_find_nl_eol(*save, ret);
	if (nl == -2)
	{
		if (!(*line = ft_strdup(*save)))
			return (-1);
		free(*save);
		*save = NULL;
		return (0);
	}
	if (!(*line = ft_substr(*save, 0, nl)) ||
		!(buffer = ft_strdup(&((*save)[nl + 1]))))
		return (-1);
	free(*save);
	*save = buffer;
	return (1);
}

int				ft_reader(char **save, int fd, char *buffer, int *nl)
{
	int		i;
	int		ret;
	char	*new_save;

	i = 0;
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = 0;
		if (*save == NULL)
		{
			if (!(*save = ft_strdup(buffer)))
				return (-1);
		}
		else
		{
			if (!(new_save = ft_strjoin(*save, buffer)))
				return (-1);
			free(*save);
			*save = new_save;
		}
		if ((*nl = ft_find_nl_eol(*save, ret)) != -1)
			break ;
	}
	free(buffer);
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		*buffer;
	int			nl;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || fd >= OPEN_MAX)
		return (-1);
	nl = 0;
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	ret = ft_reader(&(save[fd]), fd, buffer, &nl);
	if (ret < 0)
		return (-1);
	return (ft_liner(line, &(save[fd]), ret, nl));
}

int	parse_params(t_file *file, t_board *board)
{
	int	i;

	i = 0;
	int ret = 0;
	while (i < 6)
	{
		fscanf(stdin, "%d", &ret);
		// get_next_line(0, &file->line);
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
	get_time(board);
	return (1);
}