#include "get_next_line.h"

char    *write_beginning(char *buf)
{
    char    *bgn;
    size_t  len_buf;
    size_t  i;

    i = 0;
    len_buf = ft_strlen(buf, '\n');
    if ((bgn = malloc((sizeof(char) * (len_buf + 1)))) == NULL)
        return (NULL);
    while (len_buf > i)
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

    if ((bgn = write_beginning(buf)) == NULL)
    {
        free(*line);
        *line = '\0';
        free(buf);
        return (NULL);
    }
    if ((dest = ft_strdup(buf)) == NULL)
    {
        free(buf);
        return (NULL);
    }
    free(bgn);
    if ((*line = ft_strjoin(*line, bgn)) == NULL)
    {
        free(*line);
        *line = '\0';
        return (NULL);
    }
    *end = 1;
    return (dest);
}

int     read_buf(int fd, int *result, char **line, char **buf)
{
    if ((*buf = malloc(sizeof(char) * (BUFFER_SIZE)) + 1) == NULL)
    {
        free(*line);
        *line = '\0';
        return (NULL);
    }
    if (((*result = read(fd, *buf, BUFFER_SIZE)) == -1) == NULL)
    {
        free(*line);
        *line = '\0';
        free(*buf);
        return (NULL);
    }
    *(*buf + *result) = '\0';
    while (((ft_strchr(*buf, '\n')) && *result > 0) == NULL)
    {
        if ((*line = ft_strjoin(*line, *buf)) == NULL)
            return (0);
        if ((*result = read(fd, *buf, BUFFER_SIZE)) == NULL)
            return (1);
        *(*buf + *result) = '\0';
    }
    return (2);
}

int     process_end(char **line, char **end, int *is_end)
{
    if (ft_strchr(*end, '\n'))
    {
        if ((*line = ft_strjoin(*line, *end)) == NULL)
            return (0);
        return (1);
    }
    if ((*line = ft_strjoin(*line, *end)) == NULL)
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

    if (fd < 0 || BUFFER_SIZE < 1 || line == NULL || (*line = malloc(sizeof(char)) == NULL))
        return (-1);
    **line = '\0';
    if (is_end)
    {
        if ((res = process_end(line, &end, &is_end)) == NULL)
            return (-1);
        if (res == 1)
            return (1);
    }
    if ((read_buf(fd, &res, line, &bf)) == NULL)
        return (-1);
    if (ft_strchr(bf, '\n') && (end = write_end(line, bf, &is_end) == NULL))
        return (-1);
    if (res == NULL)
    {
        free(bf);
        return (0);
    }
    return (1);

}