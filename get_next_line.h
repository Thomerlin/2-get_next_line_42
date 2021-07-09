#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define FD_SIZE 4096

typedef enum e_status
{
	ERROR = -1,
	END_OF_FILE,
	NEWLINE,
}	t_status;

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *src);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_strchr(const char *s, int c);

char	*linedup(char *save, size_t end);

#endif