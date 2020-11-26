/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:42:45 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/02 18:56:32 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t srclen;

	srclen = ft_strlen(src);
	if (srclen < dstsize)
		ft_memcpy(dst, src, srclen + 1);
	else if (dstsize > 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	reslen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	reslen = (dstsize < dstlen) ? dstsize + srclen : dstlen + srclen;
	if (dstsize > dstlen)
	{
		dst += dstlen;
		ft_strlcpy(dst, src, dstsize - dstlen);
	}
	return (reslen);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		dstsize;

	dstsize = ft_strlen(s) + 1;
	copy = malloc(dstsize * sizeof(char));
	if (copy)
		ft_strlcpy(copy, s, dstsize);
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		l1;
	int		l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = malloc((l1 + l2 + 1) * sizeof(char));
	if (res)
	{
		res[0] = '\0';
		ft_strlcat(res, s1, (l1 + l2 + 1) * sizeof(char));
		ft_strlcat(res, s2, (l1 + l2 + 1) * sizeof(char));
	}
	free((void *)s1);
	return (res);
}
