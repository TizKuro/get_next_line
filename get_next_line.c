/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmorand <trmorand@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 04:17:56 by trmorand          #+#    #+#             */
/*   Updated: 2026/11/07 06:43:59 by trmorand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char *buf, char *stash)
{
	free(buf);
	free(stash);
}

static char	*read_to_stash(int fd, char *stash)
{
	char	*buf;
	int		i;

	i = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(stash);
		return (NULL);
	}
	while (i > 0 && !ft_strchr(stash, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			ft_free(buf, stash);
			return (NULL);
		}
		buf[i] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			break;
	}
	free(buf);
	return (stash);
}

static char *extract_line(char *stash)
{
	int	len;
	char	*new_stash;

	len= 0;
	while (stash[len] != '\n' && stash[len] != '\0')
		len++;
	new_stash = ft_substr(stash, 0, len + 1);
	return (new_stash);
}

static char *clean_stash(char *stash)
{
	char	*res;
	char	*newline;

	if (ft_strchr(stash, '\n') == NULL)
	{
		free(stash);
		return (NULL);
	}
	else
	{
		newline = ft_strchr(stash, '\n');
		
		if (newline[1] == '\0')
		{
			free(stash);
			return (NULL);
		}
		res = ft_substr(newline + 1, 0, ft_strlen(newline + 1));
		free(stash);
		return (res);
	}
}
char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	stash = clean_stash(stash);
	if (!line)
	{
		ft_free(stash, line);
		stash = NULL;
		return (NULL);
	}
	return (line);
}
