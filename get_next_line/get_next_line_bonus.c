/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:19:57 by del-yaag          #+#    #+#             */
/*   Updated: 2022/11/04 17:20:02 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char **leftover, char *line, size_t i)
{
	size_t	j;
	char	*temp;
	size_t	lent;

	j = 0;
	temp = NULL;
	lent = ft_strlen(*leftover);
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (free(*leftover),*leftover = NULL, NULL);
	while (j <= i)
	{
		line[j] = (*leftover)[j];
		j++;
	}
	temp = ft_calloc((lent - i) + 1, sizeof(char));
	if (!temp)
		return (free(*leftover),*leftover = NULL
			, free(line), line = NULL, NULL);
	j = 0;
	while (++i <= lent)
		temp[j++] = (*leftover)[i];
	free(*leftover);
	*leftover = temp;
	return (line);
}

int	strc(t_collecion *vb)
{
	vb->r = 1;
	vb->i = -1;
	vb->bf = NULL;
	vb->line = NULL;
	return (1);
}

char	*get_next_line(int fd)
{
	t_collecion	vb;
	static char	*lo[10240];

	while (!(strc(&vb) && (fd < 0 || read(fd, NULL, 0) < 0 || LO <= 0)))
	{
		vb.bf = ft_calloc(LO + 1, sizeof(char));
		if (!vb.bf)
			return (NULL);
		vb.r = read(fd, vb.bf, LO);
		if (vb.r < 0 || (!vb.r && !lo[fd]))
			return (free(lo[fd]), lo[fd] = 0, free(vb.bf), vb.bf = NULL, NULL);
		lo[fd] = ft_append(lo[fd], vb.bf);
		while (lo[fd][++vb.i])
			if (lo[fd][vb.i] == '\n')
				return (free(vb.bf), vb.bf = NULL
					, ft_read(&lo[fd], vb.line, vb.i));
		vb.i--;
		free(vb.bf);
		vb.bf = NULL;
		if (vb.r == 0 && lo[fd][0])
			return (vb.line = lo[fd], lo[fd] = 0, vb.line);
		if (vb.r == 0)
			return (free(lo[fd]), lo[fd] = 0, NULL);
	}
	return (free(lo[fd]), lo[fd] = 0, NULL);
}
