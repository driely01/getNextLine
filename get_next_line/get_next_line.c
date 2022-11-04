/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yvbg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:29:04 by del-yvbg          #+#    #+#             */
/*   Updated: 2022/11/02 21:29:07 by del-yvbg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char **leftover, char *line, size_t i)
{
	size_t	j;
	char	*temp;

	j = 0;
	temp = NULL;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (free(*leftover),*leftover = NULL, NULL);
	while (j <= i)
	{
		line[j] = (*leftover)[j];
		j++;
	}
	temp = ft_calloc((ft_strlen(*leftover) - i) + 1, sizeof(char));
	if (!temp)
		return (free(*leftover),*leftover = NULL
			, free(line), line = NULL, NULL);
	j = 0;
	while (++i <= ft_strlen(*leftover))
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
	static char	*left;

	while (!(strc(&vb) && (read(fd, NULL, 0) < 0 || fd < 0 || LO <= 0)))
	{
		vb.bf = ft_calloc(LO + 1, sizeof(char));
		if (!vb.bf)
			return (NULL);
		vb.r = read(fd, vb.bf, LO);
		if (vb.r < 0 || (!vb.r && !left))
			return (free(left), left = 0, free(vb.bf), vb.bf = NULL, NULL);
		left = ft_append(left, vb.bf);
		while (left[++vb.i])
			if (left[vb.i] == '\n')
				return (free(vb.bf), vb.bf = NULL
					, ft_read(&left, vb.line, vb.i));
		vb.i--;
		free(vb.bf);
		vb.bf = NULL;
		if (vb.r == 0 && left[0])
			return (vb.line = left, left = 0, vb.line);
		if (vb.r == 0)
			return (free(left), left = 0, NULL);
	}
	return (free(left), left = 0, NULL);
}

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	line = 0;
// 	fd = open("tesst.txt", O_CREAT | O_RDWR, 0777);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
