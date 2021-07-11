#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t length)
{
	unsigned char		*dst;
	unsigned const char	*source;
	size_t				i;

	dst = (unsigned char *)dest;
	source = (unsigned const char *)src;
	i = 0;
	if (!source && !dst)
		return (NULL);
	if (source < dst)
		while ((int)(--length) >= 0)
			dst[length] = source[length];
	else
	{
		while (i < length)
		{
			dst[i] = source[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	lens_total;
	char	*ret;

	if (!s1 && !s2)
		return (0);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	lens_total = len_s1 + len_s2 + 1;
	ret = malloc(sizeof(char) * lens_total);
	if (!ret)
		return (0);
	ft_memmove(ret, s1, len_s1);
	ft_memmove(ret + len_s1, s2, len_s2);
	ret[lens_total - 1] = '\0';
	free((char *)s1);
	return (ret);
}
