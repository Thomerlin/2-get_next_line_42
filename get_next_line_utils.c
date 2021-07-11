#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	size_t	i;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(len + 1);
	if (result == NULL)
		return (0);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}
