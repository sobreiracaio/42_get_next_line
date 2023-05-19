/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:22:35 by admin             #+#    #+#             */
/*   Updated: 2023/05/19 18:50:12 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_line(char *buff);
static char *read_file(int fd, char *buff);
static char *remove_read_line(char *buff);

char *get_next_line (int fd)
{
	char *line;
	static char *buff;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_file(fd, buff);
	if(!buff)
		return (NULL);
	line = get_line(buff);
	buff = remove_read_line(buff);
	return (line);
	
	
			
}

static char *read_file(int fd, char *buff)
{
    char *temp;
	int		read_bytes;
	
    temp = (char *)malloc(BUFFER_SIZE + 1);
    if(!temp)
		return (NULL);
	read_bytes = 1;
	while (read_bytes && !ft_strchr(buff, '\n') )
	{
		read_bytes =  read(fd, temp, BUFFER_SIZE);
		if (read_bytes == -1 )
			{
				free(temp);
				free(buff);
				return (NULL);
			}
		temp[read_bytes] = '\0';
		buff = ft_strjoin(buff, temp);
	}    
	free(temp);
	return (buff);
}

static char *get_line(char *buff)
{
	char *line;
	int size;
	
	if(!*buff)
		return (NULL);
	size = 0;
	while (buff[size] && buff[size] != '\n')
		size++;
	line = (char *)malloc(sizeof(char) * (size + 2));
	if(!line)
	{
		
		return (NULL);
	}
	
	ft_strlcpy(line, buff, size +1);
	if (buff[size] == '\n')
		line[size++] = '\n';
	line[size] = '\0';
	return (line);
}

static char *remove_read_line(char *buff)
{
	int line_len;
	int buff_len;
	int i;

	line_len = ft_strclen(buff, '\n');
	if (!buff [line_len])
	{
		free(buff);
		return (NULL);
	}
	buff_len = ft_strclen(buff, '\0');
	i = -1;
	while (++i < buff_len - line_len)
		buff[i] = buff[line_len +1 + i];
	buff[i] = '\0';
	return (buff);
	
		
}

// int main ()
// {
//     int fd = open("test.txt", O_RDONLY);
// 	char *buff;
	
// 	read_file(fd, buff);
// }

