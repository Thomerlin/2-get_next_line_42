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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_str1;
	size_t	len_str2;
	size_t	stot_len;
	char	*ret;

	if (!s1 && !s2)
		return (0);
	len_str1 = ft_strlen((char *)s1);
	len_str2 = ft_strlen((char *)s2);
	stot_len = len_str1 + len_str2 + 1;
	ret = malloc(sizeof(char) * stot_len);
	if (!ret)
		return (0);
	ft_memmove(ret, s1, len_str1);
	ft_memmove(ret + len_str1, s2, len_str2);
	ret[stot_len - 1] = '\0';
	free((char *)s1);
	return (ret);
}
