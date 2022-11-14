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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct collecion{
	int		r;
	size_t	i;
	char	*bf;
	char	*ln;
}	t_collecion;

size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t number, size_t size);
char	*cpy(char *s, char *p);
char	*ft_append(char *s1, char *s2);
char	*ft_read(char **leftover, char *line, size_t i);
char	*get_next_line(int fd);
char	*cpy_two(char *s1, char *s2, char *p);
int		stc(t_collecion *vb);

#endif