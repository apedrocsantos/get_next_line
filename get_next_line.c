/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:37:31 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/10 08:20:40 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
	{
		ft_clean_buf(buf);
		return (NULL);
	}
	while (buf[0] || read(fd, buf, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buf);
		if (ft_move_and_clean(buf))
			break ;
	}
	return (str);
}

/* int	main(void) */
/* { */
/* 	int		fd; */
/* 	char	*str; */

/* 	str = NULL; */
/* 	fd = open("test.txt", O_RDONLY); */
/* 	while (str = get_next_line(fd)) */
/* 	{ */
/* 		printf("%s", str); */
/* 		free(str); */
/* 	} */
/* } */
