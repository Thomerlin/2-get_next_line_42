#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t 	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	offset;
	size_t	i;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	offset = dlen;
	i = 0;
	if (size <= dlen)
		return (slen + size);
	while (src[i] && offset != size - 1)
	{
		dest[offset] = src[i];
		offset++;
		i++;
	}
	dest[offset] = '\0';
	return (dlen + slen);
}