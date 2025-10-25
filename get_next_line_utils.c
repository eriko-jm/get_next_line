/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:30:17 by joaseque          #+#    #+#             */
/*   Updated: 2025/10/25 15:22:30 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	copy_s2(char *str, char const *s2, size_t *i)
{
	size_t	j;

	j = 0;
	while (s2[j])
	{
		str[*i] = s2[j];
		j++;
		(*i)++;
	}
	str[*i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens[2];
	size_t	i;
	char	*str;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s1 || !s2)
		return (NULL);
	lens[0] = ft_strlen(s1);
	lens[1] = ft_strlen(s2);
	str = malloc(sizeof(char) * ((lens[0] + lens[1]) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < lens[0])
	{
		str[i] = s1[i];
		i++;
	}
	copy_s2(str, s2, &i);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*s2;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	s2 = (char *)s;
	if (!s2)
		return (NULL);
	while (s2[i])
	{
		if ((unsigned char)s2[i] == (unsigned char)c)
			return (&s2[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&s2[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*dup;

	i = 0;
	size = ft_strlen(s);
	dup = malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (NULL);
	dup[size] = '\0';
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
