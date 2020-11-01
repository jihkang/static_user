/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallang <mallang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:07:34 by mallang           #+#    #+#             */
/*   Updated: 2020/11/01 18:49:51 by mallang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strlcpy(char *dst, char *src, int len)
{
	int i;

	i = 0;
	if (dst == NULL)
		return (-1);
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	while (src[i])
		i++;
	return (i);
}

int		ft_strlcat(char *dst, char *src, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (dst == NULL)
		return (-1);
	while (dst[i] && i < len)
		i++;
	while (src[j] && i + j < len)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	while (src[j])
		j++;
	return (i + j);
}

char	*ft_strdup(char *str)
{
	char	*buf;
	int		len;
	int		r;

	len = ft_strlen(str);
	buf = malloc(sizeof(char) * (len + 1));
	if ((r = ft_strlcpy(buf, str, len + 1)) == -1)
		return (NULL);
	return (buf);
}

int		ft_strjoin(char **buffer, char *str, char *str2)
{
	int		len1;
	int		len2;
	int		i;

	i = 0;
	len1 = ft_strlen(str);
	len2 = ft_strlen(str2);
	*buffer = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (ft_strlcpy(*buffer, str, len1 + 1) == -1)
		return (-1);
	if (ft_strlcat(*buffer, str2, len1 + len2 + 1) == -1)
		return (-1);
	while (i < len1)
	{
		str[i] = 0;
		i++;
	}
	free(str);
	return (0);
}
