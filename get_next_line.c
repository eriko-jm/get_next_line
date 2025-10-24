/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:42:52 by joaseque          #+#    #+#             */
/*   Updated: 2025/10/22 18:30:04 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*lectura(int fd, char **buffer)
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
		if (bytes_read < 0)
			return (free(*buffer), *buffer = NULL, NULL);

		temp_buf[bytes_read] = '\0';
		
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
	if (!lectura(fd, &buffer) || (buffer && *buffer == NULL))
		return (free(buffer), buffer = NULL, NULL);
	
}

