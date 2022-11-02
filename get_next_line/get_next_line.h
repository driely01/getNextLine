/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:29:23 by del-yaag          #+#    #+#             */
/*   Updated: 2022/11/02 21:29:26 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXTLINE_H
#define GETNEXTLINE_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t number, size_t size);
char	*cpy(char *s, char *p);
char	*ft_append(char *s1, char *s2);
char	*ft_read(char **leftover, char *line, size_t i);
char	*get_next_line(int fd);

#endif
