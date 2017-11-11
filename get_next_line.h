/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krashid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 22:58:35 by krashid-          #+#    #+#             */
/*   Updated: 2017/11/11 07:59:45 by krashid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


#define	BUFF_SIZE 11
#define FT_MAX_FD 1196434
int	  get_next_line(const int fd, char **stock);
int	  join(char **line, char *buff, int ret);
