/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:43:46 by crocha-s          #+#    #+#             */
/*   Updated: 2023/05/19 18:48:04 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	x;
	if(!s)
		return (0);

	x = (unsigned char) c;
	while (*s && *s != x)
		s++;
	if (*s == x)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	unsigned int len;
	char	*result;
	
	len = ft_strclen(s1, '\0') + ft_strclen(s2, '\0');
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	
	
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	
	while (s2[j])
		result[i++] = s2[j++];
	
	result[i] = '\0';
	free(s1);
	return (result);
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


