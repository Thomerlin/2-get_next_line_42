#include "get_next_line.h"

char    *write_beginning(char *buf)
{
    char    *bgn;
    size_t  len_buf;
    size_t  i;

    i = 0;
    len_buf = ft_strlen(buf, '\n');
    if (!(bgn = malloc(sizeof(char) * (len_buf + 1))))
        return (NULL);
    while (i < len_buf)
    {
        bgn[i] = buf[i];
        i++;
    }
    bgn[i] = '\0';
    return (bgn);
}

char    *write_end(char **line, char *buf, int *end)
{
    char *bgn;
    char *dest;

    if (!(bgn = write_beginning(buf)))
    {
        free(*line);
        *line = NULL;
        free(buf);
        return (NULL);
    }
    if (!(*line = ft_strjoin(*line, bgn)))
    {
        free(buf);
        return (NULL);
    }
    free(bgn);
    if (!(dest = ft_strdup(buf)))
    {
        free(*line);
        *line = NULL;
        return (NULL);
    }
    *end = 1;
    return (dest);
}

int     read_buf(int fd, int *result, char **line, char **buf)
{
    if (!(*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))
    {
        free(*line);
        *line = NULL;
        return (0);
    }
    if ((*result = read(fd, *buf, BUFFER_SIZE == -1)
    {
        free(*line);
        *line = NULL;
        free(*buf);
        return (0);
    }
    *(*buf + *result) = '\0';
    while (!(ft_strchr(*buf, '\n')) && *result > 0)
    {
        if (!(*line = ft_strjoin(*line, *buf)))
            return (0);
        if (!(*result = read(fd, *buf, BUFFER_SIZE)))
            return (1);
        *(*buf + *result) = '\0';
    }
    return (2);
}

int     process_end(char **line, char **end, int *is_end)
{
    if (ft_strchr(*end, '\n'))
    {
        if (!(*end = write_end(line, *end, is_end)))
            return (0);
        return (1);
    }
    if (!(*line = ft_strjoin(*line, *end)))
        return (0);
    free(*end);
    *is_end = 0;
    return (2);
}

int     get_next_line(int fd, char **line)
{
    static int  is_end;
    static char *end;
    char        *bf;
    int         res;

    if (fd < 0 || BUFFER_SIZE < 1 || !line || !(*line = malloc(sizeof(char))))
        return (-1);
    **line = '\0';
    if (is_end)
    {
        if (!(res = process_end(line, &end, &is_end)))
            return (-1);
        if (res == 1)
            return (1);
    }
    if (!(read_buf(fd, &res, line, &bf)))
        return (-1);
    if (ft_strchr(bf, '\n') && !(end = write_end(line, bf, &is_end)))
        return (-1);
    if (!res)
    {
        free(bf);
        return (0);
    }
    return (1);

}