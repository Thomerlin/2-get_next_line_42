#include "get_next_line.h"

char		*ft_strchr(const char *s, int c)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(s, '\0');
	while (i <= j)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char		*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;
	char	*tmp;

	tmp = ft_strchr(s, '\n') + 1;
	i = ft_strlen(tmp, '\0');
	if (!(dest = malloc(sizeof(char) * (i + 1))))
	{
		free((char *)s);
		return (NULL);
	}
	i = 0;
	while (tmp[i] != '\0')
	{
		dest[i] = tmp[i];
		i++;
	}
	dest[i] = '\0';
	free((char *)s);
	return (dest);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1, '\0') + ft_strlen(s2, '\0');
	i = 0;
	j = 0;
	if (!(s3 = malloc(sizeof(char) * (len + 1))))
	{
		free(s1);
		s1 = NULL;
		free(s2);
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

size_t		ft_strlen(const char *s, const char c)
{
	size_t i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}