#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	if (!s)
		return (0);
	while (s[counter])
		counter++;
	return (counter);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;
	int		i;

	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	if (src == dst)
		return (dst);
	if (source < dest)
	{
		while (len--)
			*(dest + len) = *(source + len);
		return (dst);
	}
	while (len--)
		*dest++ = *source++;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	lens_total;
	char	*result;

	if (!s1 && !s2)
		return (0);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	lens_total = len_s1 + len_s2 + 1;
	result = malloc(sizeof(char) * lens_total);
	if (!result)
		return (0);
	ft_memmove(result, s1, len_s1);
	ft_memmove(result + len_s1, s2, len_s2);
	result[lens_total - 1] = '\0';
	free((char *)s1);
	return (result);
}
