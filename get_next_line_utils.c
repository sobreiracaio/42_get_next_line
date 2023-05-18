/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:43:46 by crocha-s          #+#    #+#             */
/*   Updated: 2023/05/19 00:07:21 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	x;

	x = (unsigned char) c;
	while (*s && *s != x)
		s++;
	if (*s == x)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*sum;

	i = -1;
	j = 0;
	sum = (char *)malloc ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!sum || (!s1 && !s2))
		return (NULL);
	if (s1)
	{
		while (s1[++i] != '\0')
			sum[i] = s1[i];
	}
	if (s2)
	{
		while (s2[j])
			sum[i++] = s2[j++];
	}
	sum[i] = '\0';
	return (sum);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen (src));
}

size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	if(!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}


