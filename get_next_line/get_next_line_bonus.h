/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:20:13 by del-yaag          #+#    #+#             */
/*   Updated: 2022/11/04 17:20:15 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
char	*cpy_two(char *s1, char *s2, char *p);
char	*ft_append(char *s1, char *s2);
char	*ft_read(char **leftover, char *line, size_t i);
char	*get_next_line(int fd);
char	*get_linee(int fd);
int		stc(t_collecion *vb);

#endif
