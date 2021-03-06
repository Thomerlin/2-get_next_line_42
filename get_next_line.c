#include "get_next_line.h"

char	*strings_line(char *s)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*save_next(char *s)
{
	size_t	i;
	size_t	counter;
	char	*str;

	i = 0;
	counter = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (0);
	i++;
	while (s[i])
		str[counter++] = s[i++];
	str[counter] = '\0';
	free(s);
	return (str);
}

char	*check_buff(int fd, char **line)
{
	char	*buff;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	return (buff);
}

char	check_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buff;
	int			counter;

	buff = check_buff(fd, line);
	if (!buff)
		return (-1);
	counter = 1;
	while (check_newline(save) != 1 && counter != 0)
	{
		counter = read(fd, buff, BUFFER_SIZE);
		if (counter == -1)
		{
			free(buff);
			return (-1);
		}
		buff[counter] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	*line = strings_line(save);
	save = save_next(save);
	if (counter == 0)
		return (0);
	return (1);
}
