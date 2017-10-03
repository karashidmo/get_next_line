/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krashid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 22:58:35 by krashid-          #+#    #+#             */
/*   Updated: 2017/09/27 22:58:38 by krashid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define	BUFF_SIZE 32

char	*ft_get_file(int ac, char *av[]);
int		get_next_line(const int fd, char **line);
char	*ft_strrchr(const char *s, int c);
void	ft_putendl(char const *s);
