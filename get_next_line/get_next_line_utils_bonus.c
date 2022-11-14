/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_next_line_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:19:43 by del-yaag          #+#    #+#             */
/*   Updated: 2022/11/04 17:19:46 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	p = ft_calloc((len1 + 1), sizeof(char));
	if (!p)
		return (0);
	while (s[++i])
		p[i] = s[i];
	p[i] = 0;
	return (p);
}

char	*cpy_two(char *s1, char *s2, char *p)
{
	size_t	i;
	size_t	len1;

	i = 0;
	len1 = ft_strlen(s1);
	p = ft_calloc((len1 + ft_strlen(s2) + 1), sizeof(char));
	if (!p)
		return (0);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	free(s1);
	s1 = 0;
	i = 0;
	while (s2[i])
		p[len1++] = s2[i++];
	p[len1] = '\0';
	return (p);
}

char	*ft_append(char *s1, char *s2)
{
	char	*p;

	p = NULL;
	if (!s1 && !s2)
		return (0);
	if (!s1 || !*s1)
	{
		free(s1);
		s1 = 0;
		p = cpy(s2, p);
	}
	else if (!s2 || !*s2)
	{
		p = cpy(s1, p);
		free(s1);
		s1 = 0;
	}
	else
		p = cpy_two(s1, s2, p);
	return (p);
}
