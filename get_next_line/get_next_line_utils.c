/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:08:29 by del-yaag          #+#    #+#             */
/*   Updated: 2022/11/02 23:08:32 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t number, size_t size)
{
	void	*p;
	char	*p1;
	size_t	i;
	size_t	j;

	j = 0;
	i = number * size;
	if ((number && (i / number) != size) || (size && (i / size) != number))
		return (NULL);
	p = malloc(i);
	if (!p)
		return (0);
	p1 = (char *)p;
	while (j < i)
		p1[j++] = '\0';
	return (p);
}

char	*cpy(char *s, char *p)
{
	size_t	i;
	size_t	len1;

	i = -1;
	len1 = ft_strlen(s);
	p = malloc(sizeof(char) * (len1 + 1));
	if (!p)
		return (0);
	while (s[++i])
		p[i] = s[i];
	p[i] = 0;
	return (p);
}

char	*ft_append(char *s1, char *s2)
{
	size_t	i;
	size_t	len1;
	char	*p;

	i = -1;
	p = NULL;
	if (!s1 && !s2)
		return (0);
	if (!s1 || !*s1)
		p = cpy(s2, p);
	else if (!s2 || !*s2)
		p = cpy(s1, p);
	else
	{
		len1 = ft_strlen(s1);
		p = malloc(sizeof(char) * (len1 + ft_strlen(s2) + 1));
		if (!p)
			return (0);
		while (s1[++i])
			p[i] = s1[i];
		i = -1;
		while (s2[++i])
			p[len1++] = s2[i];
		p[len1] = '\0';
	}
	return (p);
}

char *ft_read(char **leftover, char *line, size_t i)
{
	size_t j;
	char *temp;

	j = 0;
	temp = NULL;
	line = ft_calloc(i + 2, sizeof(char));
	while (j <= i)
	{
		line[j] = (*leftover)[j];
		j++;
	}
	temp = ft_calloc((ft_strlen(*leftover) - i) + 1, sizeof(char));
	j = 0;
	while (++i <= ft_strlen(*leftover))
		temp[j++] = (*leftover)[i];
	*leftover = temp;
	return (line);
}
