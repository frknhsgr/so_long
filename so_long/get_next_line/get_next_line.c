/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:38:58 by fhosgor           #+#    #+#             */
/*   Updated: 2024/01/08 16:59:54 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(int fd, char *str)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!res)
		return (NULL);
	i = 1;
	while (!ft_strchar(str, '\n') && i != 0)
	{
		i = read(fd, res, BUFFER_SIZE);
		if (i == -1)
		{
			free(res);
			free(str);
			return (NULL);
		}
		res[i] = '\0';
		str = ft_strjoin(str, res);
	}
	free(res);
	return (str);
}

char	*ft_takeline(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

char	*ft_leftline(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	i++;
	res = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*dst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dst = ft_readline(fd, dst);
	if (!dst)
		return (NULL);
	str = ft_takeline(dst);
	dst = ft_leftline(dst);
	return (str);
}
