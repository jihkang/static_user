/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallang <mallang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:05:02 by mallang           #+#    #+#             */
/*   Updated: 2020/11/01 18:50:16 by mallang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
int		ft_strlcat(char *dst, char *src, int len);
int		ft_strlcpy(char *dst, char *src, int len);
int		ft_strjoin(char **dst, char *str, char *str2);
int		empty_buf(char **buffer, char **line, int r);
void	initalize_array(char *str);

#endif
