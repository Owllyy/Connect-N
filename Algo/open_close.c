#include "algo.h"

int	open_file(t_file *file)
{
	if (file->fd == 0)
		return (1);
	file->fd = open(file->file_path, O_RDONLY);
	if (file->fd == -1)
		return (0);
	return (1);
}

int	close_file(t_file *file)
{
	if (file->line != 0)
	{
		free(file->line);
		file->line = 0;
	}
	if (file->fd <= 0)
		return (0);
	close(file->fd);
	return (1);
}