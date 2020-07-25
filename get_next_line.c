/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwindom <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 17:39:49 by cwindom           #+#    #+#             */
/*   Updated: 2020/06/28 17:39:57 by cwindom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	free_gnl(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (-1);
}

static char	*check(char *balance, char **line)
{
	char	*nl_addr;

	nl_addr = NULL;
	if (balance)
	{
		if ((nl_addr = ft_strchr(balance, '\n')))
		{
			*nl_addr = '\0';
			*line = ft_strdup(balance);
			nl_addr++;
			ft_strcpy(balance, nl_addr);
		}
		else
			*line = ft_strdup(balance);
	}
	else
		*line = ft_strdup("");
	return (nl_addr);
}

static int	free_and_ret(int r, char **buf, char **balance, char **nl_addr)
{
	free(*buf);
	if (r == 0 && *balance != 0)
		free_gnl(balance);
	return (r || *nl_addr) ? 1 : 0;
}

int			get_next_line(int fd, char **line)
{
	int			r;
	static char	*balance;
	char		*buf;
	char		*nl_addr;

	r = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0)
		return (-1);
	nl_addr = check(balance, line);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-(free_gnl(&buf) * free_gnl(line)));
	while (!nl_addr && (r = read(fd, buf, BUFFER_SIZE)))
	{
		if (r < 0)
			return (-(free_gnl(&balance) * free_gnl(&buf)));
		buf[r] = '\0';
		if ((nl_addr = ft_strchr(buf, '\n')))
		{
			*nl_addr = '\0';
			free(balance);
			balance = ft_strdup(++nl_addr);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (free_and_ret(r, &buf, &balance, &nl_addr));
}
