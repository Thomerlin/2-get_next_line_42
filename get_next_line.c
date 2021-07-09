#include "get_next_line.h"

static void	kill(char **save)
{
	if (*save != NULL)
	{
		free(*save);
		*save = NULL;
	}
}

static int	linelen(char *line)
{
	size_t	len;

	len = 0;
	while (line[len])
	{
		if (line[len] == '\n')
			break ;
		len++;
	}
	return (len);
}

static t_status	get_line(char **save, char **line)
{
	size_t	size;
	char	*temp;

	size = linelen(*save);
	if ((*save)[size] == '\0')
	{
		*line = ft_strdup(*save);
		kill(save);
		return (END_OF_FILE);
	}
	*line = linedup(*save, size);
	temp = ft_strdup((*save) + size + 1);
	free(*save);
	*save = temp;
	return (NEWLINE);
}

static t_status	output(char **save, char **line, ssize_t size_read)
{
	if (size_read == -1)
		return (ERROR);
	else if (size_read == 0 && *save == NULL)
	{
		*line = ft_strdup("");
		return (END_OF_FILE);
	}
	return (get_line(save, line));
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	ssize_t		size_read;
	char		*buffer;
	char		*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	size_read = read(fd, buffer, BUFFER_SIZE);
	while (size_read > 0)
	{
		buffer[size_read] = '\0';
		if (save == NULL)
			save = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(save, buffer);
			free(save);
			save = temp;
		}
		if (ft_strchr(save, '\n'))
			break ;
		size_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (output(&save, line, size_read));
}