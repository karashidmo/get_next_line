/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krashid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 22:53:39 by krashid-          #+#    #+#             */
/*   Updated: 2017/11/11 08:55:03 by krashid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	  gnl_join(char **line, char *buff, int ret)
{
	char *tmp;
	int i;

	i = 0;
	while(buff[i])
	{
		if (buff[i] == '\n')
			break;
		i++;
	}
	tmp = ft_strnew(ft_strlen(*line) + i);
	ft_strcpy(tmp, *line);
	free(*line);
	ft_strncat(tmp, buff, i);
	ft_strcpy(buff, &(buff[(i != ret || buff[i] == '\n') ? (i + 1) : i]));
	*line = tmp;
	return ((i != ret) ? 1 : 0);
}


int		get_next_line(const int fd, char **line)
{
	static char	buff[FT_MAX_FD][BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || !line || read(fd, &ret, 0) == -1)
		return (-1);
	ret = 0;
	*line = NULL;
	if (buff[fd][0])
		(gnl_join(line, buff[fd], ret) == 1) ? ret = 1 : 0;
	while ((ret = read(fd, buff[fd], BUFF_SIZE)) > 0)
	{
		buff[fd][ret] = '\0';
		if (gnl_join(line, buff[fd], ret) == 1)
			return (1);
	}
	if (*line)
		return (1);
	return (0);
}

int		  main(int argc, char **argv)
{
	char	  *line;
	int		fd;
	int	  ret;
	int		count_lines;
	char	  *filename;
	int		errors;

	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
				errors++;
			if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
				errors++;
			if (count_lines == 2 && strcmp(line, "4567890") != 0)
				errors++;
			if (count_lines == 3 && strcmp(line, "defghijk") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 4)
			printf("-> must have returned '1' four times instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567\", \"abcdefg\", \"4567890\" and \"defghijk\"\n");
		if (count_lines == 4 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}

/*
   int main(int ac, char **av)
   {
   int fd;
   char *line = NULL;

   if (ac == 2 && ((fd = open(av[1], O_RDONLY)) > 0))
   {
   while(get_next_line(fd, &line) > 0)
   {
   printf("%s\n", line);
   free(line);
   line = NULL;
   }
   }

   return(0);
   }
   */
