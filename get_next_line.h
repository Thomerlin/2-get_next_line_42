#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFF_SIZE 17
# define MAX_FILES 4864

int     get_next_line(int fd, char **line);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strnew(size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_strclr(char *s);


#endif