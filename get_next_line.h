#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s, const char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*write_tail(char **line, char *buf, int *is_tail);
int		read_buf(int fd, int *result, char **line, char **buf);
int		process_tail(char **line, char **tail, int *is_tail);
char	*write_head(char *buf);

#endif