/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:22:35 by admin             #+#    #+#             */
/*   Updated: 2023/05/16 23:45:35 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *buffer;
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if(!buffer)
        return (NULL);
        
    read(fd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);
    return (NULL);
}

int main ()
{
    int fd = open("test.txt", O_RDONLY);
    get_next_line(fd);
}

