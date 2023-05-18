/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:22:35 by admin             #+#    #+#             */
/*   Updated: 2023/05/19 00:02:47 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_line(char *backup);
static char *read_file(int fd, char *backup);
static char *remove_read_line(char *backup);

char *get_next_line (int fd)
{
	char *line;
	static char *backup;

	
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_file(fd, backup);
	if(!backup)
		return (NULL);
	line = get_line(backup);
	backup = remove_read_line(backup);
	return (line);
	
	
			
}

static char *read_file(int fd, char *backup)
{
    char *temp;
	int		read_bytes;
	
    temp = (char *)malloc(BUFFER_SIZE + 1);
    if(!temp)
		return (NULL);
	read_bytes = 1;
	while (read_bytes && !ft_strchr(backup, '\n') )
	{
		read_bytes =  read(fd, temp, BUFFER_SIZE);
		if (read_bytes == -1 )
			{
				free(temp);
				free(backup);
				return (NULL);
			}
		temp[read_bytes] = '\0';
		backup = ft_strjoin(backup, temp);
	}    
	free(temp);
	return (backup);
}

static char *get_line(char *backup)
{
	char *line;
	int size;
	
	if(!*backup)
		return (NULL);
	size = 0;
	while (backup[size] && backup[size] != '\n')
		size++;
	line = (char *)malloc(sizeof(char) * (size + 2));
	if(!line)
	{
		
		return (NULL);
	}
	
	ft_strlcpy(line, backup, size +1);
	//if (backup[size] == '\n')
	//	line[size++] = '\n';
	line[size] = '\0';
	return (line);
}

static char *remove_read_line(char *backup)
{
	int i;
	int j;
	char *new_backup;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if(!backup[i])
	{
		return (NULL);
	}
	new_backup = (char *)malloc(sizeof(char) * (ft_strclen(backup, '\0') -1 + 1));
	if (!new_backup)
		return (NULL);
	i++;
	j = 0;
	while(backup[i])
		new_backup[j++] = backup[i++];
	new_backup[j] = '\0';
	
	return(new_backup);
	
		
}

// int main ()
// {
//     int fd = open("test.txt", O_RDONLY);
// 	char *backup;
	
// 	read_file(fd, backup);
// }

