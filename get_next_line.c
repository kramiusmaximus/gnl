/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:42:45 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/02 18:56:32 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*ptrdst;
	const unsigned char	*ptrsrc;

	if (!dst && !src)
		return (NULL);
	ptrdst = dst;
	ptrsrc = src;
	while (len-- > 0)
		*ptrdst++ = *ptrsrc++;
	return (dst);
}

int		ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

int		process_output(int fd, int n_read, char *s, char **line)
{
	char *nlptr;
	char *nexts;

	if (fd < 0 || n_read < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if ((nlptr = ft_strchr(s, '\n')))
	{
		*nlptr = '\0';
		*line = ft_strdup(s);
		nexts = s + ft_strlen(s) + 1;
		ft_strlcpy(s, nexts, ft_strlen(nexts) + 1);
		return (1);
	}
	else if (s[0])
	{
		if (!(*line = ft_strdup(s)))
		{
			free(s);
			return (-1);
		}
		s[0] = '\0';
		return (1);
	}
	free(s);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*s[2048];
	char		buff[(BUFFER_SIZE > 0) ? BUFFER_SIZE + 1 : 1];
	int			n_read;

	n_read = 0;
	while ((fd >= 0 && BUFFER_SIZE > 0 && line)
	&& (!s[fd] || !ft_strchr(s[fd], '\n'))
	&& (n_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[n_read] = '\0';
		if (!s[fd])
		{
			if (!(s[fd] = ft_strdup(buff)))
				return (-1);
			continue ;
		}
		if (!(s[fd] = ft_strjoin(s[fd], buff)))
			return (-1);
	}
	return (process_output(fd, n_read, s[fd], line));
}
