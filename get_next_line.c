#include "get_next_line.h"

char	*save_next(char *s)
{
	size_t	i;
	size_t	count;
	char	*str;

	i = 0; 
	count = 0;
	while (s[i] && s[i] != '\n')
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
		str[count++] = s[i++];
	str[count] = '\0';
	free(s);
	return (str);
}

char *get_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	i = 0;	
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buff;
	int			i;

	buff = verific_buff(fd, line);
	if(!buff)
		return (-1);
	i = 1;
	while (verific_newline(save) != 1 && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (-1);
		}
		buff[i] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	*line = get_line(save);
	save = save_next(save);
	if (i == 0)
		return (0);
	return (1);
}
