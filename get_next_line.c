#include "get_next_line.h"

static size_t	move_buffer(char buffer[])
{
	size_t	i;
	size_t	j;
	int		bytes_left;

	i = 0;
	while (i < BUFFER_SIZE && buffer[i] != '\n')
		i++;
	if (i == BUFFER_SIZE)
		bytes_left = 0;
	else
		bytes_left = BUFFER_SIZE - i - 1;
	j = 0;
	while (j < BUFFER_SIZE)
	{
		if (i < BUFFER_SIZE)
			buffer[j++] = buffer[++i];
		else
			buffer[j++] = 0;
	}
	return (bytes_left);
}

static char	*merge_buffer_n(char *dest, char *src, size_t n)
{
	size_t	dest_len;
	size_t	result_len;
	char	*result;

	dest_len = 0;
	if (dest)
		dest_len = ft_strlen(dest);
	result_len = dest_len + n;
	result = malloc(sizeof(char) * (result_len + 1));
	if (!result)
		return (NULL);
	result[0] = '\0';
	if (dest)
		ft_strlcat(result, dest, dest_len + 1);
	ft_strlcat(result, src, result_len + 1);
	return (result);
}

static int	append_next_chunk(int fd, char **new_line, char *buffer)
{
	int			bytes_left;
	int			i;
	char		*merged_str;

	bytes_left = move_buffer(buffer);
	if (bytes_left == 0)
		bytes_left = read(fd, buffer, BUFFER_SIZE);
	if (bytes_left == -1)
		return (GNL_ERROR);
	i = 0;
	while (i < bytes_left && buffer[i] != '\n')
		i++;
	merged_str = merge_buffer_n(*new_line, buffer, i);
	if (!merged_str)
		return (GNL_ERROR);
	if (*new_line)
		free(*new_line);
	*new_line = merged_str;
	if (buffer[i] == '\n')
		return (1);
	if (bytes_left == 0)
		return (GNL_END_OF_FILE);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*new_line;
	int			finished;
	static char	buffer[BUFFER_SIZE + 1];

	new_line = NULL;
	finished = 0;
	while (!finished)
	{
		finished = append_next_chunk(fd, &new_line, buffer);
		*line = new_line;
		if (finished == GNL_END_OF_FILE)
			return (0);
		if (finished == GNL_ERROR)
			return (-1);
	}
	return (1);
}