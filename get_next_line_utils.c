/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:43:46 by crocha-s          #+#    #+#             */
/*   Updated: 2023/05/17 18:00:30 by crocha-s         ###   ########.fr       */
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