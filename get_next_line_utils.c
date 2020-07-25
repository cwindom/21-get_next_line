/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwindom <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 17:40:03 by cwindom           #+#    #+#             */
/*   Updated: 2020/06/28 17:40:08 by cwindom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (new = ft_strdup(s2));
	if (!s2 && s1)
		return (new = ft_strdup(s1));
	if (!(new = malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)))))
		return (NULL);
	while (s1 && *s1 != '\0')
		new[i++] = *s1++;
	free(s1 - i);
	while (s2 && *s2 != '\0')
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int n)
{
	int		i;
	char	*a;

	i = 0;
	while (str[i] != '\0' && str[i] != n)
		i++;
	if (str[i] == n)
	{
		a = (char *)&str[i];
		return (a);
	}
	if (str[i] == '\0' && !n)
	{
		a = (char *)&str[i];
		return (a);
	}
	return (NULL);
}

char	*ft_strcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}
