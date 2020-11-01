/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallang <mallang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:03:25 by mallang           #+#    #+#             */
/*   Updated: 2020/11/01 18:33:37 by mallang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_newline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	initalize_array(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
}

int		cut_line(char **buffer, char **line, int idx)
{
	int		i;
	char	*temp;

	(*buffer)[idx] = '\0';
	*line = ft_strdup(*buffer);
	i = ft_strlen(*buffer + idx + 1);
	if (i != -1)
	{
		temp = ft_strdup(*buffer + idx + 1);
		initalize_array(*buffer);
		free(*buffer);
		*buffer = temp;
	}
	else
	{
		initalize_array(*buffer);
		free(*buffer);
		*buffer = 0;
	}
	return (1);
}

int		empty_buf(char **buffer, char **line, int r)
{
	int i;

	if (r < 0)
		return (-1);
	if (*buffer)
	{
		i = find_newline(*buffer);
		if (i >= 0)
			return (cut_line(buffer, line, i));
		*line = *buffer;
		*buffer = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer[65536];
	char		buf[BUFFER_SIZE + 1];
	int			size;
	char		*temp;
	int			i;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = 0;
		if (buffer[fd] == NULL)
			temp = ft_strdup("");
		else
			temp = ft_strdup(buffer[fd]);
		ft_strjoin(&buffer[fd], temp, buf);
		if ((i = find_newline(buffer[fd])) != -1)
			return (cut_line(&buffer[fd], line, i));
	}
	return (empty_buf(&buffer[fd], line, size));
}