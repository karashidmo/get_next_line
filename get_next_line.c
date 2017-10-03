/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krashid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 22:53:39 by krashid-          #+#    #+#             */
/*   Updated: 2017/10/03 19:40:39 by krashid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <libc.h>
#include "get_next_line.h"
#include <unistd.h>

int get_next_line(const int fd, char **line)
{

	char *buff;
	static char ret;
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		while (BUFF_SIZE >= fd && line)
		{
			if (!(fd != '\n'))
				buff[ret] = NULL;
			else if (fd == '\0')
				return (1);
			else if (fd == '\n')
				buff[ret] = line;
		}
		*line++;
	}
	return(0);
}

int searchn(const int fd,char *line)
{
	const char *str1;

	str1 = line;
	while(fd)
		ft_strchr(str1, '\n' + 48);
	return (1);
}

int main(int ac, char **av)
{
	int fd;
	int i;
	char **line = NULL;

	i = 0;
	while(ac >+ 2 && (fd = open(av[i], O_RDONLY) > 0))
	{
		get_next_line((const int) fd, line);
	}
	return(0);
}
