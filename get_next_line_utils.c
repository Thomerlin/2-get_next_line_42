#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
	char	*res;
	size_t	offset;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(len + 1);
	if (res == NULL)
		return (NULL);
	offset = 0;
	while (*s1)
		res[offset++] = *s1++;
	while (*s2)
		res[offset++] = *s2++;
	res[offset] = '\0';
	return (res);
}

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

char	*linedup(char *save, size_t end)
{
	char	*dup;
	size_t	offset;

	dup = malloc(end + 1);
	if (dup == NULL)
		return (NULL);
	offset = 0;
	while (offset < end)
	{
		dup[offset] = save[offset];
		offset++;
	}
	dup[offset] = '\0';
	return (dup);
}