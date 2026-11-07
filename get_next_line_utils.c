/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trmorand <trmorand@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 03:50:41 by trmorand          #+#    #+#             */
/*   Updated: 2026/11/07 04:03:15 by trmorand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*new;
	int		i;
	int		s_len;

	i = 0;
	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[len] = '\0';
	return (new);
}


char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if((char)c == '\0')
		return((char *)&s[i]);
	return (0);
}

static void	ft_fill(char *new, const char *s1, const char *s2)
{
	int	d;
	int	i;

	i = 0;
	d = 0;
	while (s1 && s1[i])
	{
		new[d] = s1[i];
		i++;
		d++;
	}
	i = 0;
	while (s2[i])
	{
		new[d] = s2[i];
		i++;
		d++;
	}
	new[d] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*rawr;

	if (!s2)
		return (0);
	rawr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rawr)
	{
		free(s1);
		return (0);
	}
	ft_fill(rawr, s1, s2);
	free(s1);
	return (rawr);
}
