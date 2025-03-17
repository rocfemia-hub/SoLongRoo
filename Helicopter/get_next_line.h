/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roo <roo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:26:57 by roo               #+#    #+#             */
/*   Updated: 2025/03/16 15:09:15 by roo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_find_line(char *buffer);
char	*ft_create_line(char *buffer, char *line);
char	*get_next_line(int fd);

size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, const char *s2);
char	*ft_strchr_gnl(const char *s, int c);
void	*ft_calloc_gnl(size_t nmemb, size_t size);

#endif