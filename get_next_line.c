#include "get_next_line.h"

char	*write_beginning(char *buf)
{
	char	*bgn;
	size_t	len_buf;
	size_t	i;

	i = 0;
	len_buf = ft_strlen(buf, '\n');
	bgn = malloc(sizeof(char) * (len_buf + 1));
	if (!bgn)
		return (NULL);
	while (i < len_buf)
	{
		bgn[i] = buf[i];
		i++;
	}
	bgn[i] = '\0';
	return (bgn);
}

char	*write_end(char **line, char *buf, int *end)
{
	char	*bgn;
	char	*dest;
	size_t	i;

	i = 0;
	bgn = write_beginning(buf);
	dest = ft_strdup(buf);
	line[i] = ft_strjoin(line[i], bgn);
	if (!bgn || !dest || !line[i])
	{
		free(line[i]);
		line[i] = NULL;
		free(buf);
		return (NULL);
	}
	free(bgn);
	end[i] = 1;
	return (dest);
}

int	read_buf(int fd, int *result, char **line, char **buf)
{
	size_t	i;

	i = 0;
	buf[i] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	result[i] = read(fd, buf[i], BUFFER_SIZE);
	if (!buf[i] || result[i] == -1)
	{
		free(line[i]);
		line[i] = NULL;
		free(buf[i]);
		return (0);
	}
	*(buf[i] + result[i]) = '\0';
	while (!(ft_strchr(buf[i], '\n')) && result[i] > 0)
	{
		line[i] = ft_strjoin(line[i], buf[i]);
		if (!line[i])
			return (0);
		result[i] = read(fd, buf[i], BUFFER_SIZE);
		if (!result[i])
			return (1);
		*(buf[i] + result[i]) = '\0';
	}
	return (2);
}

int	process_end(char **line, char **end, int *is_end)
{
	size_t	i;

	i = 0;
	if (ft_strchr(end[i], '\n'))
	{
		end[i] = write_end(line, end[i], is_end);
		if (!end[i])
			return (0);
		return (1);
	}
	line[i] = ft_strjoin(line[i], end[i]);
	if (!line[i])
		return (0);
	free(end[i]);
	is_end[i] = 0;
	return (2);
}

int	get_next_line(int fd, char **line)
{
	static int	is_end;
	static char	*end;
	char		*buf;
	int			res;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || !(*line = malloc(sizeof(char))))
		return (-1);
	**line = '\0';
	if (is_end)
	{
		if (!process_end(line, &end, &is_end))
			return (-1);
		if (process_end(line, &end, &is_end) == 1)
			return (1);
	}
	if (!(read_buf(fd, &res, line, &buf)) || (ft_strchr(buf, '\n') && !(write_end(line, buf, &is_end))))
		return (-1);
	if (!res)
	{
		free(buf);
		return (0);
	}
	return (1);
}
