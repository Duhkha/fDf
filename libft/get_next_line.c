/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 07:23:05 by syoung            #+#    #+#             */
/*   Updated: 2017/06/22 11:53:16 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>

static void		ft_remalloc(char *s, int size)
{
	char	*temp;
	int		i;

	temp = s;
	i = 0;
	s = (char *)malloc(sizeof(char *) * size);
	if (s == NULL)
		temp = NULL;
	while (temp[i])
	{
		s[i] = temp[i];
		i++;
	}
}

/*
** read into buff BUFF_SIZE bytes, join buff into buff2
*/

static int		ft_read(char *buff, char *buff2, int fd)
{
	int ttlbytes;
	int bytesread;
	int	i;
	int	j;

	i = 0;
	j = 0;
	ttlbytes = 0;
	bytesread = 0;
	while ((bytesread = read(fd, buff, BUFF_SIZE)))
	{
		ttlbytes += bytesread;
		ft_remalloc(buff2, ttlbytes);
		j = 0;
		while (j < bytesread)
		{
			buff2[i] = buff[j];
			j++;
			i++;
		}
	}
	free(buff);
	return (ttlbytes);
}

/*
** ft_strlen but with \n as the delimiter instead of \0
*/

static int		line_len(char *s, int ttlbytes)
{
	int n;

	n = 0;
	while (s[n] != '\n' && n < ttlbytes)
		n++;
	return (n);
}

/*
** puts buff2 into line and NULL terminates it
*/

static int		ft_put_line(int i, int ttlbytes, char **line, char *buff2)
{
	int j;

	j = 0;
	*line = (char *)malloc((line_len((&buff2[i] + 1), ttlbytes)));
	while (i < ttlbytes)
	{
		if (buff2[i] == '\n')
			break ;
		line[0][j] = buff2[i];
		i++;
		j++;
	}
	if (i == ttlbytes)
		free(buff2);
	line[0][j] = '\0';
	i++;
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buff = NULL;
	static int	ttlbytes = 0;
	static int	i = 0;
	static char	*buff2 = NULL;

	if (BUFF_SIZE >= 2147483647)
		return (-1);
	if (read(fd, buff, 0) < 0)
		return (-1);
	if (buff2 == NULL)
	{
		buff2 = (char *)malloc(sizeof(char *) * BUFF_SIZE);
		buff = (char *)malloc(sizeof(char *) * BUFF_SIZE);
		if (buff2 == NULL)
			return (-1);
	}
	if (i >= ttlbytes && i > 0)
		return (0);
	if (BUFF_SIZE == 0)
		return (-1);
	if (ttlbytes == 0)
		ttlbytes = ft_read(buff, buff2, fd);
	i = ft_put_line(i, ttlbytes, line, buff2);
	return (1);
}
