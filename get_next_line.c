/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:22:35 by admin             #+#    #+#             */
/*   Updated: 2023/05/17 18:16:47 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line (int fd)
{
	
}

static char *read_file(int fd, char *backup)
{
    char *buffer;
	int		read_bytes;
	
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if(!buffer)
        return (NULL);
    read_bytes = 1;
	while (read_bytes > 0 &&  !ft_strchr(backup, '\n') )
	{
		read_bytes =  read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0 )
			break;
		buffer[read_bytes] = '\0';
		backup = ft_strjoin(backup, buffer);
	}    
	
	free(buffer);
	if(read_bytes < 0)   
    	return (NULL);
	else
		return (backup);
		
}

int main ()
{
    int fd = open("test.txt", O_RDONLY);
	char *backup;
	
	read_file(fd, backup);
}

