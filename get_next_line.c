/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:42:52 by joaseque          #+#    #+#             */
/*   Updated: 2025/10/24 20:03:57 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_line(char *buffer, int *error_flag)
{
	char	*new_buff;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (*error_flag = 0, NULL);
	}
	new_buff = (char *)malloc(ft_strlen(buffer) - i);
	if (!new_buff)
		return (free(buffer), *error_flag = 1, NULL);
	i++;
	j = 0;
	while (buffer[i])
	{
		new_buff[j] = buffer[i];
		i++;
		j++;
	}
	new_buff[j] = '\0';
	free(buffer);
	return (*error_flag = 0, new_buff);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	ssize_t	i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	i++;
	line[i] = '\0';
	return (line);
}

static char	*read_line(int fd, char **buffer)
{
	char	*temp_buf;
	size_t	bytes_read;

	temp_buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp_buf)
		return (free(*buffer), *buffer = NULL, NULL);
	bytes_read = 1;
	while (!ft_strchr(*buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, temp_buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free(*buffer), *buffer = NULL, NULL);
		temp_buf[BUFFER_SIZE] = '\0';
		*buffer = ft_strjoin(*buffer, temp_buf);
		if (!*buffer)
			return (free(temp_buf), NULL);
	}
	return (free(temp_buf), *buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			error_flag;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), buffer = NULL, NULL);

	buffer = read_line(fd, &buffer);
	if (!*buffer || (buffer && !*buffer))
		return (free(buffer), buffer = NULL, NULL);
	line = extract_line(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = update_line(buffer, &error_flag);
	if (!buffer && error_flag == 1)
		return (free(line), NULL);
	return (line);
}
