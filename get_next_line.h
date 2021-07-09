#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
int			ft_verific_newline(char *str);
size_t	    ft_strlen(const char *s);
char	    *ft_strjoin(const char *s1, const char *s2);
char		*ft_verific_buff(int fd, char **line);

#endif