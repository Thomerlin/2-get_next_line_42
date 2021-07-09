#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	conv_c;

	conv_c = (unsigned char)c;
	while (*s)
	{
		if (*s == conv_c)
			return ((char *)s);
		s++;
	}
	if (conv_c == *s)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		size;

	size = ft_strlen(src) + 1;
	copy = (char *)malloc(size);
	if (copy != 0)
	{
		ft_strlcpy(copy, src, size);
		return (copy);
	}
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	size_t	i;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s, const char c)
{
	size_t i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}