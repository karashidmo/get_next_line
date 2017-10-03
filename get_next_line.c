/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krashid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 22:53:39 by krashid-          #+#    #+#             */
/*   Updated: 2017/10/03 20:38:54 by krashid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <libc.h>
#include "get_next_line.h"
#include <unistd.h>

int get_next_line(const int fd, char **line)
{

	char *buff;
	static int ret;

	buff = 0;
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		while (BUFF_SIZE >= fd && line)
		{
			if (!(fd != '\n'))
				buff[ret] = 0;
			else if (fd == '\0')
				return (1);
			else if (fd == '\n')
				buff = *line;
			line++;
		}
	}
	return(0);
}

int main(int ac, char **av)
{
	int fd;
//	int i;
	char **line = NULL;

	while(ac == 2 && (!(fd = open(av[1], O_RDONLY) > 0)))
	{
		if (!(open(av[1], O_RDONLY))) 
			 printf("error");
		get_next_line((const int) fd, line);
		printf("line copied is %s \n", *line);
	}
	return(0);
}
